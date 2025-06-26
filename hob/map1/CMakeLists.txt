file(GLOB SOURCES "src/*.cpp")

add_library(hob_map1 SHARED)
target_sources(hob_map1 PRIVATE ${SOURCES})

target_link_libraries(hob_map1 PRIVATE hob_common hob_engine)

