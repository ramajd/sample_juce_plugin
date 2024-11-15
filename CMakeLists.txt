cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(sample_juce_plugin VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(cmake/get_cpm.cmake)

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

add_subdirectory(libs/juce)
add_subdirectory(plugin)
# add_subdirectory(test)