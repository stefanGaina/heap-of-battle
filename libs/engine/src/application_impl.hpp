#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <dylib.hpp>

#include "application_interface.hpp"
#include "asset_manager.hpp"

namespace hob::engine
{

class scene;

class application_impl final : public application_interface
{
public:
	///
	/// \brief Construct an application.
	///
	application_impl(const sf::VideoMode& mode, const std::string& title, const std::filesystem::path& scenes_directory);

	///
	/// \brief This is defined in the source file to prevent unique_ptr from in-lining its destructor.
	/// \details An error is issued because scene is forward declared and its size is unknown.
	///
	~application_impl() noexcept;

	///
	/// \brief
	///
	/// \param scene_name:
	/// \returns void
	///
	void run(const std::string& scene_name);

	void run();

	void set_icon(const std::filesystem::path& icon_file);

	void set_scene(const std::string& scene_name) override;

	void stop() override;

	void toggle_fullscreen() override;

private:
	void run_game_loop();

	void handle_events();

	void update_scene(sf::Clock& timer);

	void draw();

private:
	sf::RenderWindow window;

	asset_manager assets;

	std::filesystem::path scenes_directory;

	std::unique_ptr<dylib> scene_library;

	std::unique_ptr<dylib> previous_scene_library;

	std::unique_ptr<scene> current_scene;

	std::unique_ptr<scene> previous_scene;

	bool is_running;
};

} // namespace hob::engine

