cmake_minimum_required(VERSION 3.16)

project(bender LANGUAGES CXX)

set(EXEC main)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})

if (WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

	option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

	include(FetchContent)
	FetchContent_Declare(
		SFML
		GIT_REPOSITORY https://github.com/SFML/SFML.git
		GIT_TAG 2.6.x
	)
	FetchContent_MakeAvailable(SFML)

	target_link_libraries(${EXEC} sfml-graphics)
	target_compile_features(${EXEC} PRIVATE cxx_std_17)

	add_custom_command(
		TARGET ${EXEC}
		COMMENT "Copy OpenAL DLL"
		PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${EXEC}>
		VERBATIM
	)

	install(TARGETS ${EXEC})

	add_custom_command(
		TARGET ${EXEC} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}\\data\\monkey.obj" ".\\data\\monkey.obj"
		COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}\\data\\Arial.ttf" ".\\data\\Arial.ttf"

	)
else()
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

	find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

	target_link_libraries(${EXEC} sfml-graphics)

	add_custom_command(
		TARGET ${EXEC} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy "../data/monkey.obj" "./data/monkey.obj"
		COMMAND ${CMAKE_COMMAND} -E copy "../data/Arial.ttf" "./data/Arial.ttf"
	)
endif()
