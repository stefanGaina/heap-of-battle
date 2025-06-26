#pragma once

#include <nlohmann/json.hpp>

#include "json_parser.hpp"

namespace hob
{

class json_parser_impl final
{
public:
	json_parser_impl(std::string_view file_path, engine::asset_manager& assets);

	std::vector<std::string> get_children() const;

	sprite_map get_sprites() const;

	text_map get_texts() const;

private:
	const nlohmann::json parser;

	engine::asset_manager& assets;
};

} // namespace hob

