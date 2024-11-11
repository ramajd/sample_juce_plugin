cmake_minimum_required(VERSION 3.20)

project(sample_juce_plugin VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)

FetchContent_Declare(
	JUCE
	URL https://github.com/juce-framework/JUCE/archive/refs/tags/8.0.3.tar.gz
)
FetchContent_MakeAvailable(JUCE)

add_executable(test-app src/main.cpp)
target_link_libraries(test-app PRIVATE
	juce::juce_core
	juce::juce_gui_basics
)
target_compile_definitions(test-app PUBLIC 
	JUCE_USE_CURL=0
)
