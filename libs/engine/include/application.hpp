#pragma once

#include <memory>
#include <filesystem>
#include <SFML/Window/VideoMode.hpp>

#include "application_interface.hpp"

namespace hob::engine
{

class application_impl;

class application final : public application_interface
{
public:
	application(const sf::VideoMode& mode, const std::string& title, const std::filesystem::path& scenes_directory);

	~application() noexcept;

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
	const std::unique_ptr<application_impl> pimpl;
};

} // namespace hob::engine

