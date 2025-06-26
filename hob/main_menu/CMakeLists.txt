file(GLOB SOURCES "src/*.cpp")

add_library(hob_main_menu SHARED)
target_sources(hob_main_menu PRIVATE ${SOURCES})

target_link_libraries(hob_main_menu PUBLIC hob_common hob_engine)

