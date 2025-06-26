#include "game.hpp"
#include "configuration.hpp"
#include "application.hpp"

namespace hob
{

void run_game(const std::string_view configuration_file)
{
	const configuration configuration = configuration_file;
	engine::application application = { sf::VideoMode{ { configuration.get_width(), configuration.get_height() } }, configuration.get_title(), configuration.get_scenes_directory() };

	application.set_icon(configuration.get_icon());
	application.run(configuration.get_starting_scene());
}

} // namespace hob

