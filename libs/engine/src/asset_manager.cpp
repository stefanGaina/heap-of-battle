#include "asset_manager.hpp"

#include "asset_manager_impl.hpp"

namespace hob::engine
{

asset_manager::asset_manager()
	: pimpl{ std::make_unique<asset_manager_impl>() }
{
}

asset_manager::~asset_manager() noexcept = default;

sf::Sprite asset_manager::create_sprite(const std::filesystem::path& texture_path, const sf::Vector2f& scale, const sf::IntRect& dimension)
{
	assert(nullptr != pimpl);
	return pimpl->create_sprite(texture_path, scale, dimension);
}

sf::Text asset_manager::create_text(const std::filesystem::path& font_path)
{
	assert(nullptr != pimpl);
	return pimpl->create_text(font_path);
}

sf::Sound asset_manager::create_sound(const std::filesystem::path& sound_path)
{
	assert(nullptr != pimpl);
	return pimpl->create_sound(sound_path);
}

sf::Music& asset_manager::open_music(const std::filesystem::path& music_path)
{
	assert(nullptr != pimpl);
	return pimpl->open_music(music_path);
}

void asset_manager::scene_unloaded()
{
	assert(nullptr != pimpl);
	pimpl->scene_unloaded();
}

void asset_manager::scene_loaded(const bool is_successful)
{
	assert(nullptr != pimpl);
	pimpl->scene_loaded(is_successful);
}

} // namespace hob::engine

