cmake_minimum_required(VERSION 3.16)

project(HysteresisSwitchTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Test)

qt_standard_project_setup()

qt_add_executable(HysteresisSwitchTest
    tst_hysteresis_switch.cpp
    hysteresis_switch.h
    hysteresis_switch.cpp
)

target_link_libraries(HysteresisSwitchTest
    PRIVATE Qt6::Test
)

add_test(NAME HysteresisSwitchTest COMMAND HysteresisSwitchTest)
