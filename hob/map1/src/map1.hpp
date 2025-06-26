#pragma once

#include "scene.hpp"

namespace hob
{

class map1 final : public engine::scene
{
public:
	map1(engine::application_interface& app_interface, engine::asset_manager& assets);

	engine::drawable_list get_drawables() override;

private:
	void initialize();
};

} // namespace hob

