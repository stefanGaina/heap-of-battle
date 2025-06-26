#include "configuration.hpp"

#include <fstream>

namespace hob
{

configuration::configuration(const std::string_view configuration_file)
	: parser(nlohmann::json::parse(std::ifstream{ configuration_file.data() }))
{
}

std::uint32_t configuration::get_width() const
{
	return parser["width"];
}

std::uint32_t configuration::get_height() const
{
	return parser["height"];
}

std::string configuration::get_title() const
{
	return parser["title"];
}

std::string configuration::get_icon() const
{
	return parser["icon"];
}

std::string configuration::get_scenes_directory() const
{
	return parser["scenes_directory"];
}

std::string configuration::get_starting_scene() const
{
	return parser["starting_scene"];
}

} // namespace hob

