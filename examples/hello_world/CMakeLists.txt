##############################################################################################
# Standard Template / Boilerplate Parent Cross-Platform Make file (CMake File) for rp2350
# @Author: Kush Jain
# @Date: 09/14/2025
#
# @Pre-requisites
#
#   - arm-none-eabi-gcc
#   - `sudo apt install gcc-arm-none-eabi`
#
#   - build-essential
#   - `sudo apt-get install build-essential`
#
#   - pico-sdk
#   - `git clone https://github.com/raspberrypi/pico-sdk.git`
#   - Tip: `git submodule update --init` in pico-sdk git repo
#
#   - pico_sdk_import.cmake
#   - Tip: pico_sdk_import.cmake is available at `.../pico-sdk/external/pico_sdk_import.cmake`
#
#   - build/ directory
#   - Note: This is where `cmake ..` command is executed to build the "build-structure"
#               for this project
#
# @Note: First time building might take sometime ( even for simple blink )
#           This is because it needs to build the entire pico-sdk!
#
##############################################################################################

# ============ Global Variables ============ #
set(CMAKE_VER "3.17")
set(C_STANDARD "11")
set(CXX_STANDARD "17")
# Note: this sdk path is the same path where pico-sdk was git cloned
set(PICO_SDK_PATH "/mnt/c/rpi/pico-sdk")
# Specify PICO platform for ARM (by default)
# Note: override PLATFORM for RISC-V if -DRISCV flag is passed
set(PICO_PLATFORM "rp2350-arm-s")
set(PICO_COMPILER "pico_arm_cortex_m33_gcc")
if(RISCV)
    set(PICO_PLATFORM "rp2350-riscv")
    set(PICO_COMPILER "pico_arm_gcc")
endif()
# Specify PICO Board to pico2_w
set(PICO_BOARD "pico2_w")

# ============ CMAKE Start ============ #
cmake_minimum_required(VERSION ${CMAKE_VER})

# Include the PICO SDK to get RPI dependent libraries
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Extract current working directory for Project
get_filename_component(projName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" projName ${projName})
# Set CMake current directory as Project
project(${projName} C CXX ASM)

# Set C/C++ standards for compilation for project
set(CMAKE_C_STANDARD ${C_STANDARD})
set(CMAKE_CXX_STANDARD ${CXX_STANDARD})

# TODO: FIXME: ???
# set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize PICO SDK
pico_sdk_init()

# Collect all the *.c / *.h files (recursively)
# Note: update and add more directories (if created)
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# Add src directory to project
add_subdirectory(src)

# ============ CMAKE End ============ #
