#pragma once

#include "scene.hpp"
#include "json_parser.hpp"
// #include "animation.hpp"

namespace hob
{

class player final : public engine::scene
{
public:
	player(engine::application_interface& app_interface, engine::asset_manager& assets, std::string_view configuration_file);

	engine::drawable_list get_drawables() override;

private:
	void on_event(const sf::Event::MouseButtonPressed& event) override;

	void on_event(const sf::Event::MouseButtonReleased& event) override;

	void on_update(float delta_time) override;

	void initialize(std::string_view configuration_file, engine::asset_manager& assets);

private:
//	using animation_map = std::unordered_map<std::string_view, animation>;

//	using animation_reference = std::optional<std::reference_wrapper<animation>>;

	sprite_map sprites;

//	animation_map animations;

//	animation_reference animation_current;

	std::shared_ptr<sf::Sprite> current_sprite;

	float elapsed_time;

	std::size_t current_frame;

	bool is_moving;
};

} // namespace hob

