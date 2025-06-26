#include "main_menu.hpp"

#include "asset_manager.hpp"
#include "application_interface.hpp"

#include <print>

namespace hob
{

main_menu::main_menu(engine::application_interface& app_interface, engine::asset_manager& assets)
	: scene{ app_interface, assets }
	, song{ assets.open_music("assets/music/theme.flac") }
	, sprites{ json_parser{ "configuration/main_menu.json", assets }.get_sprites() }
{
	song.setVolume(10.0f);
	song.play();
}

engine::drawable_list main_menu::get_drawables()
{
	engine::drawable_list drawables = {};

	for (const std::pair<std::string, std::shared_ptr<sf::Sprite>> drawable : sprites)
	{
		drawables.push_front(*drawable.second);
	}

	return drawables;
}

void main_menu::on_event(const sf::Event::KeyPressed& event)
{
	try
	{
		app_interface.set_scene("hob_map1");
	}
	catch (const std::exception& exception)
	{
		std::println("{}", exception.what());
	}
}

extern "C" engine::scene* create_scene(engine::application_interface& app_interface, engine::asset_manager& assets)
{
	try
	{
		return new main_menu{ app_interface, assets };
	}
	catch (const std::exception& exception)
	{
		std::println("{}", exception.what());
		return nullptr;
	}
}

} // namespace hob

