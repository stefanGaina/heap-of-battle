#pragma once

#include <string>

namespace hob::engine
{

class application_interface
{
public:
	virtual void set_scene(const std::string& scene_name) = 0;

	virtual void stop() = 0;

	virtual void toggle_fullscreen() = 0;
};

} // namespace hob::engine

