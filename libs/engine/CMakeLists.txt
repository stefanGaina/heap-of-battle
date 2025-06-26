set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(DYLIB_DIR ${EXTERNAL_DIR}/dylib)

add_library(hob_engine SHARED)

file(GLOB SOURCES "src/*.cpp")
target_sources(hob_engine PRIVATE ${SOURCES})

target_include_directories(hob_engine
	PUBLIC
	include
	${SFML_DIR}/include
	${DYLIB_DIR}/include
)

target_link_libraries(hob_engine PUBLIC sfml-window sfml-graphics sfml-audio)

