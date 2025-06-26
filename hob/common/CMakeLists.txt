file(GLOB SOURCES "src/*.cpp")

add_library(hob_common SHARED)
target_sources(hob_common PRIVATE ${SOURCES})

target_include_directories(hob_common
	PUBLIC
	include
	${CMAKE_SOURCE_DIR}/external/nlohmann/include
)

target_link_libraries(hob_common PRIVATE hob_engine)

