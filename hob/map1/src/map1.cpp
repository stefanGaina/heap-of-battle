#include "map1.hpp"

#include "application_interface.hpp"
#include "json_parser.hpp"
#include "player.hpp"

namespace hob
{

map1::map1(engine::application_interface& app_interface, engine::asset_manager& assets)
	: scene{ app_interface, assets }
{
	initialize();
}

engine::drawable_list map1::get_drawables()
{
	engine::drawable_list drawables = {};

	for (const std::unique_ptr<engine::scene>& child : children)
	{
		drawables.splice_after(drawables.before_begin(), child->get_drawables());
	}

	return drawables;
}

void map1::initialize()
{
	const json_parser parser = { "configuration/map1.json", assets };

	children.push_back(std::make_unique<player>(app_interface, assets, parser.get_children()[0]));
}

extern "C" engine::scene* create_scene(engine::application_interface& app_interface, engine::asset_manager& assets)
{
	try
	{
		return new map1{ app_interface, assets };
	}
	catch (const std::exception& exception)
	{
		return nullptr;
	}
}

} // namespace hob

