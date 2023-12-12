cmake_minimum_required(VERSION 3.20.0)

include(cmake/build_options.cmake)

##########
# ZEPHYR #
##########

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

#######
# APP #
#######

project(zephyr-vscode-template
	VERSION 0.1.0
	DESCRIPTION "Working example of a Zephyr project managed using VSCode."
	LANGUAGES C CXX
)

set_property(GLOBAL PROPERTY C_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD 20)

target_sources(app
    PRIVATE
	    src/main.c 
)

target_include_directories(app PRIVATE src)
