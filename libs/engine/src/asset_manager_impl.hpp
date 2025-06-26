#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

namespace hob::engine
{

class asset_manager_impl final
{
public:
	asset_manager_impl();

	sf::Sprite create_sprite(const std::filesystem::path& texture_path, const sf::Vector2f& scale, const sf::IntRect& dimension);

	sf::Text create_text(const std::filesystem::path& font_path);

	sf::Sound create_sound(const std::filesystem::path& sound_path);

	sf::Music& open_music(const std::filesystem::path& music_path);

	void scene_unloaded();

	void scene_loaded(bool is_successful);

private:
	///
	/// \throws std::runtime_error: 
	///
	const sf::Texture& get_texture(const std::filesystem::path& texture_path);

	const sf::Font& get_font(const std::filesystem::path& font_path);

	const sf::SoundBuffer& get_sound_buffer(const std::filesystem::path& sound_path);

private:
	using texture_cache = std::unordered_map<std::filesystem::path, sf::Texture>;

	using font_cache = std::unordered_map<std::filesystem::path, sf::Font>;

	using sound_cache = std::unordered_map<std::filesystem::path, sf::SoundBuffer>;

	using music_cache = std::unordered_map<std::filesystem::path, sf::Music>;

	texture_cache textures;

	font_cache fonts;

	sound_cache sounds;

	music_cache songs;
};

} // namespace hob::engine

