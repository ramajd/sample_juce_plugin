cmake_minimum_required(VERSION 3.22)

project(SampleAudioPluginTest)

enable_testing()

add_executable(${PROJECT_NAME}
    src/test_audioprocessor.cpp
)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        SampleAudioPlugin
        GTest::gtest_main
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${GOOGLETEST_SOURCE_DIR}/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../plugin/include
        ${JUCE_SOURCE_DIR}/modules
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})