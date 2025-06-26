#include "application.hpp"

#include "application_impl.hpp"

namespace hob::engine
{

application::application(const sf::VideoMode& mode, const std::string& title, const std::filesystem::path& scenes_directory)
	: pimpl{ std::make_unique<application_impl>(mode, title, scenes_directory) }
{
}

application::~application() noexcept = default;

void application::run(const std::string& scene_name)
{
	assert(nullptr != pimpl);
	pimpl->run(scene_name);
}

void application::run()
{
	assert(nullptr != pimpl);
	pimpl->run();
}

void application::set_icon(const std::filesystem::path& icon_file)
{
	assert(nullptr != pimpl);
	pimpl->set_icon(icon_file);
}

void application::set_scene(const std::string& scene_name)
{
	assert(nullptr != pimpl);
	pimpl->set_scene(scene_name);
}

void application::stop()
{
	assert(nullptr != pimpl);
	pimpl->stop();
}

void application::toggle_fullscreen()
{
	assert(nullptr != pimpl);
	pimpl->toggle_fullscreen();
}

} // namespace hob::engine

