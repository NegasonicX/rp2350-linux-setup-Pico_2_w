##############################################################################################
# Standard Template / Boilerplate Child Cross-Platform Make file (CMake File)
# @Author: Kush Jain
# @Date: 09/14/2025
##############################################################################################

# ============ CMAKE Start ============ #

# Add *.c / *.h files as executable
add_executable(
    ${projName}
    ${SRC_FILES}
)

# Link standard PICO libraries to the projects
target_link_libraries(${projName} pico_stdlib)
pico_enable_stdio_usb(${projName} 1)
pico_enable_stdio_uart(${projName} 0)

# Generate binary (map/hex/bin) for the project
pico_add_extra_outputs(${projName})

# ============ CMAKE End ============ #
