# https://www.youtube.com/watch?v=Uq7Hwt18s3s&ab_channel=WolfSound

cmake_minimum_required(VERSION 3.22)

project(sample_juce_plugin VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(cmake/get_cpm.cmake)

CPMAddPackage(
	NAME JUCE
	GITHUB_REPOSITORY juce-framework/JUCE
	GIT_TAG 8.0.3
	VERSION 8.0.3
	SOURCE_DIR ${LIB_DIR}/juce
)

CPMAddPackage(
	NAME GOOGLETEST 
	GITHUB_REPOSITORY google/googletest 
	VERSION 1.15.2
	SOURCE_DIR ${LIB_DIR}/googletest
	OPTIONS 
		"INSTALL_GTEST OFF"
		"gtest_force_shared_crt ON"
)
enable_testing()
# set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (MSVC)
	add_compile_options(/Wall /WX)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(test-app src/main.cpp)
target_link_libraries(test-app PRIVATE
	juce::juce_core
	juce::juce_gui_basics
)
target_compile_definitions(test-app PUBLIC 
	JUCE_USE_CURL=0
)

add_subdirectory(plugin)
add_subdirectory(test)