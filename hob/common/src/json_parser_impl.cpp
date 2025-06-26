#include "json_parser_impl.hpp"

#include <fstream>

namespace hob
{

json_parser_impl::json_parser_impl(const std::string_view file_path, engine::asset_manager& assets)
	: parser(nlohmann::json::parse(std::ifstream{ file_path.data() }))
	, assets{ assets }
{
}

std::vector<std::string> json_parser_impl::get_children() const
{
	std::vector<std::string> children = {};

	for (const nlohmann::json& child : parser["children"])
	{
		children.push_back(child);
	}

	return children;
}

sprite_map json_parser_impl::get_sprites() const
{
	sprite_map sprites = {};

	for (const nlohmann::json& sprite : parser["sprites"])
	{
		sprites[sprite["name"]] = std::make_shared<sf::Sprite>(assets.create_sprite(sprite["texture"], { sprite["scale_x"], sprite["scale_y"] },
						sf::IntRect{ { sprite["x"], sprite["y"] }, { sprite["width"], sprite["height"] } } ));
	}

	return sprites;
}

text_map json_parser_impl::get_texts() const
{
	text_map texts = {};

	for (const nlohmann::json& text : parser["texts"])
	{
		// TODO
	}

	return texts;
}

} // namespace hob

