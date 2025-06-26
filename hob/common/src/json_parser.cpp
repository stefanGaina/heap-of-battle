#include "json_parser.hpp"

#include "json_parser_impl.hpp"

namespace hob
{

json_parser::json_parser(const std::string_view file_path, engine::asset_manager& assets)
	: pimpl{ std::make_unique<json_parser_impl>(file_path, assets) }
{
}

json_parser::~json_parser() noexcept = default;

std::vector<std::string> json_parser::get_children() const
{
	assert(nullptr != pimpl);
	return pimpl->get_children();
}

sprite_map json_parser::get_sprites() const
{
	assert(nullptr != pimpl);
	return pimpl->get_sprites();
}

text_map json_parser::get_texts() const
{
	assert(nullptr != pimpl);
	return pimpl->get_texts();
}

} // namespace hob

