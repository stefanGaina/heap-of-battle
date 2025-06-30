#include "player.hpp"

namespace hob
{

player::player(engine::application_interface& app_interface, engine::asset_manager& assets, const std::string_view configuration_file)
	: scene{ app_interface, assets }
	, sprites{}
	, current_sprite{ nullptr }
	, elapsed_time{ 0.0f }
	, current_frame{ 0UL }
	, is_moving{ false }
{
	initialize(configuration_file, assets);
}

engine::drawable_list player::get_drawables()
{
	return { *current_sprite };
}

void player::on_event(const sf::Event::MouseButtonPressed& event)
{
	if (sf::Mouse::Button::Right != event.button)
	{
		return;
	}

	is_moving = true;
	elapsed_time = 0.0f;
}

void player::on_event(const sf::Event::MouseButtonReleased& event)
{
	if (sf::Mouse::Button::Right != event.button)
	{
		return;
	}

	is_moving = false;
	current_sprite = sprites["up_idle"];
}

void player::on_update(const float delta_time)
{
	static std::vector<std::string> ANIMATION_TEST = { "up_walk_0", "up_walk_1", "up_walk_2", "up_walk_3" };

	elapsed_time += delta_time;

	if (elapsed_time >= 0.1f)
	{
		elapsed_time = 0.0f;

		if (!is_moving)
		{
			current_sprite = sprites["up_idle"];
			return;
		}

		current_frame = (current_frame + 1) % ANIMATION_TEST.size();
		current_sprite = sprites[ANIMATION_TEST[current_frame]];
	}
}

void player::initialize(const std::string_view configuration_file, engine::asset_manager& assets)
{
	const json_parser parser = { configuration_file, assets };

	sprites = parser.get_sprites();
	current_sprite = sprites["up_idle"];
}

} // namespace hob

