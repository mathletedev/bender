if (WIN32)
	cmake_minimum_required(VERSION 3.16)
	project(bender LANGUAGES CXX)

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	set(EXEC main)

	option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

	include_directories(includes)
	include(FetchContent)
	FetchContent_Declare(
		SFML
		GIT_REPOSITORY https://github.com/SFML/SFML.git
		GIT_TAG 2.6.x
	)
	FetchContent_MakeAvailable(SFML)

	file(GLOB SOURCES src/*.cpp)

	add_executable(${EXEC} ${SOURCES})
	target_link_libraries(${EXEC} sfml-graphics)
	target_compile_features(${EXEC} PRIVATE cxx_std_17)

	add_custom_command(
		TARGET ${EXEC}
		COMMENT "Copy OpenAL DLL"
		PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${EXEC}>
		VERBATIM
	)

	install(TARGETS ${EXEC})
else()
	cmake_minimum_required(VERSION 3.28)

	project(bender)

	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
	set(EXEC main)

	include_directories(includes)

	file(GLOB SOURCES src/*.cpp)

	find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

	add_executable(${EXEC} ${SOURCES})

	target_link_libraries(${EXEC} sfml-graphics)
endif()
