#include <cstdint>
#include <cstdlib>

#include "game.hpp"

std::int32_t main(const std::int32_t argument_count, char** const arguments)
{
	hob::run_game(1 < argument_count ? arguments[0] : "configuration/configuration.json");
	return EXIT_SUCCESS;
}

