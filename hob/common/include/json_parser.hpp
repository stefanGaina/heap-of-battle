#pragma once

#include "asset_manager.hpp"

namespace hob
{

class json_parser_impl;

using sprite_map = std::unordered_map<std::string, std::shared_ptr<sf::Sprite>>;

using text_map = std::unordered_map<std::string, std::shared_ptr<sf::Text>>;

using texture_map = std::unordered_map<std::string, std::shared_ptr<sf::Texture>>;

class json_parser final
{
public:
	json_parser(std::string_view file_path, engine::asset_manager& assets);

	~json_parser() noexcept;

	std::vector<std::string> get_children() const;

	sprite_map get_sprites() const;

	text_map get_texts() const;

private:
	const std::unique_ptr<json_parser_impl> pimpl;
};

} // namespace hob

