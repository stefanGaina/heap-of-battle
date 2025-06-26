#include "asset_manager_impl.hpp"

namespace hob::engine
{

asset_manager_impl::asset_manager_impl()
	: textures{}
	, fonts{}
	, sounds{}
	, songs{}
{
}

sf::Sprite asset_manager_impl::create_sprite(const std::filesystem::path& texture_path, const sf::Vector2f& scale, const sf::IntRect& dimension)
{
	sf::Sprite sprite = sf::IntRect{ { 0, 0 }, { 0, 0 } } == dimension ? sf::Sprite{ get_texture(texture_path) } : sf::Sprite{ get_texture(texture_path), dimension };

	sprite.setScale(scale);
	return sprite;
}

sf::Text asset_manager_impl::create_text(const std::filesystem::path& font_path)
{
	return sf::Text{ get_font(font_path) };
}

sf::Sound asset_manager_impl::create_sound(const std::filesystem::path& sound_path)
{
	return sf::Sound{ get_sound_buffer(sound_path) };
}

sf::Music& asset_manager_impl::open_music(const std::filesystem::path& music_path)
{
	const music_cache::iterator iterator = songs.find(music_path);
	return iterator != songs.end() ? iterator->second : songs[music_path] = sf::Music{ music_path };
}

void asset_manager_impl::scene_unloaded()
{
	// TODO
}

void asset_manager_impl::scene_loaded(const bool is_successful)
{
	// TODO
}

const sf::Texture& asset_manager_impl::get_texture(const std::filesystem::path& texture_path)
{
	const texture_cache::const_iterator iterator = textures.find(texture_path);
	return iterator != textures.end() ? iterator->second : textures[texture_path] = sf::Texture{ texture_path };
}

const sf::Font& asset_manager_impl::get_font(const std::filesystem::path& font_path)
{
	const font_cache::const_iterator iterator = fonts.find(font_path);
	return iterator != fonts.end() ? iterator->second : fonts[font_path] = sf::Font{ font_path };
}

const sf::SoundBuffer& asset_manager_impl::get_sound_buffer(const std::filesystem::path& sound_path)
{
	const sound_cache::const_iterator iterator = sounds.find(sound_path);
	return iterator != sounds.end() ? iterator->second : sounds[sound_path] = sf::SoundBuffer{ sound_path };
}

} // namespace hob::engine

