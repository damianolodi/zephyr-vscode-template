set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

##############
# BUILD TYPE #
##############

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
        STRING "Choose the type of build."
        FORCE
    )
endif()

# Set the possible values of build type for cmake-gui/ccmake
set_property(CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo"
)

#########
# BOARD #
#########

set(default_board "nrf52840dk_nrf52840")
if (NOT BOARD)
    message(STATUS "Setting board to '${default_board}' as none was specified.")
    set(BOARD "${default_board}" CACHE
        STRING "Choose the board to build for."
        FORCE
    )

    set_property(CACHE BOARD
        PROPERTY STRINGS
            "nrf52840dk_nrf52840"
            "thingy52_nrf52832"
    )
endif()

##############
# CONF FILES #
##############

# Set the directory in which Zephyr is looking for configuration files
set(APPLICATION_CONFIG_DIR "conf")

set(CONF_FILE "prj.conf")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND CONF_FILE "debug.conf")
endif()
