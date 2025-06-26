#pragma once

#include "scene.hpp"

namespace hob
{

class animation final : engine::scene
{
public:
	engine::drawable_list get_drawables() override;

	void add(std::string_view name);

private:



};

} // namespace hob

