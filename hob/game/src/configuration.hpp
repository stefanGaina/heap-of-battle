#pragma once

#include <nlohmann/json.hpp>

namespace hob
{

class configuration final
{
public:
	configuration(std::string_view configuration_file);

	std::uint32_t get_width() const;

	std::uint32_t get_height() const;

	std::string get_title() const;

	std::string get_icon() const;
	
	std::string get_scenes_directory() const;

	std::string get_starting_scene() const;

private:
	const nlohmann::json parser;
};

} // namespace hob

