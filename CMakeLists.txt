# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
cmake_minimum_required(VERSION 3.13)

cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)

project(servo_pwm)

pico_sdk_init()

add_executable(servo_pwm src/PWM_LED_0)

pico_enable_stdio_usb(servo_pwm 1)
pico_enable_stdio_uart(servo_pwm 0)

target_link_libraries(servo_pwm pico_stdlib hardware_pwm)