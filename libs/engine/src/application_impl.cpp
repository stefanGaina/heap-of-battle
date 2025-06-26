#include "application_impl.hpp"

#include <SFML/Graphics/Image.hpp>

#include "scene.hpp"

namespace hob::engine
{

application_impl::application_impl(const sf::VideoMode& mode, const std::string& title, const std::filesystem::path& scenes_directory)
	: window{ mode, title, sf::Style::Titlebar | sf::Style::Close }
	, assets{}
	, scenes_directory{ scenes_directory }
	, scene_library{}
	, current_scene{ nullptr }
	, is_running{ false }
{
	if (!window.isOpen())
	{
		throw std::runtime_error{ "Failed to create window!" };
	}
}

application_impl::~application_impl() noexcept = default;

void application_impl::run(const std::string& scene_name)
{
	set_scene(scene_name);
	run_game_loop();
}

void application_impl::run()
{
	if (nullptr == current_scene)
	{
		return;
	}

	run_game_loop();
}

void application_impl::set_icon(const std::filesystem::path& icon_file)
{
	assert(window.isOpen());
	window.setIcon(sf::Image{ icon_file });
}

void application_impl::set_scene(const std::string& scene_name)
{
	using create_scene_fn = scene* (*)(application_interface&, asset_manager&);

	std::unique_ptr		  dynamic_library = std::make_unique<dylib>(scenes_directory, scene_name.data());
	const create_scene_fn create_scene	  = reinterpret_cast<create_scene_fn>(dynamic_library->get_symbol("create_scene"));
	scene* const		  scene_handle	  = create_scene(*this, assets);
	std::unique_ptr		  next_scene	  = nullptr != scene_handle
												? std::unique_ptr<scene>{ scene_handle }
												: throw std::runtime_error{ std::format("Failed to create \"{}\" scene!", scene_name) };

	previous_scene = std::move(current_scene);
	current_scene = std::move(next_scene);

	previous_scene_library = std::move(scene_library);
	scene_library = std::move(dynamic_library);
}

void application_impl::stop()
{
	is_running = false;
}

void application_impl::toggle_fullscreen()
{
	// TODO
}

void application_impl::run_game_loop()
{
	assert(!is_running);

	sf::Clock timer = {};

	is_running = true;
	while (is_running)
	{
		handle_events();
		update_scene(timer);
		draw();
	}
}

void application_impl::handle_events()
{
	assert(window.isOpen());
	assert(nullptr != current_scene);

	while (const std::optional event = window.pollEvent())
	{
		current_scene->handle_event(*event);
	}
}

void application_impl::update_scene(sf::Clock& timer)
{
	current_scene->update(timer.restart().asSeconds());
	previous_scene = nullptr;
	previous_scene_library = nullptr;
}

void application_impl::draw()
{
	assert(window.isOpen());
	assert(nullptr != current_scene);

	window.clear();

	for (const drawable_reference drawable : current_scene->get_drawables())
	{
		window.draw(drawable.get());
	}

	window.display();
}

} // namespace hob::engine

