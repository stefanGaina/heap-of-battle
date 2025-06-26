#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

namespace hob::engine
{

class asset_manager_impl;

class asset_manager final
{
public:
	asset_manager();

	~asset_manager() noexcept;

	sf::Sprite create_sprite(const std::filesystem::path& texture_path, const sf::Vector2f& scale, const sf::IntRect& dimension = {});

	sf::Text create_text(const std::filesystem::path& font_path);

	sf::Sound create_sound(const std::filesystem::path& sound_path);

	sf::Music& open_music(const std::filesystem::path& music_path);

	void scene_unloaded();

	void scene_loaded(bool is_successful = true);

private:
	const std::unique_ptr<asset_manager_impl> pimpl;
};

} // namespace hob::engine

