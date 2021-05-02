# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ws2812examples C CXX ASM)

pico_sdk_init()

# Add executable. Default name is the project name, 
add_subdirectory(brightness)
add_subdirectory(simple)
add_subdirectory(strandtest_wheel)
add_subdirectory(onboard_cytron)
add_subdirectory(../pico_neopixels build)

