add_executable(hob)

file(GLOB SOURCES "src/*.cpp")
target_sources(hob PRIVATE ${SOURCES})

target_include_directories(hob
	PUBLIC
	${CMAKE_SOURCE_DIR}/external/nlohmann/include
)

target_link_options(hob PRIVATE -Wl,-rpath=lib)
target_link_libraries(hob PRIVATE hob_engine)

