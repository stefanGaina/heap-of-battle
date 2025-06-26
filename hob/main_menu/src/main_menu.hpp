#pragma once

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "scene.hpp"
#include "json_parser.hpp"

namespace hob
{

class main_menu final : public engine::scene
{
public:
	main_menu(engine::application_interface& app_interface, engine::asset_manager& assets);

	engine::drawable_list get_drawables() override;

private:
	void on_event(const sf::Event::KeyPressed& event) override;

private:
	sf::Music& song;

	sprite_map sprites;
};

} // namespace hob

