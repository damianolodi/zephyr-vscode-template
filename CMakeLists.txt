cmake_minimum_required(VERSION 3.26)

##########
# ZEPHYR #
##########

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

#######
# APP #
#######

project(zephyr-template
	VERSION 0.1.0
	DESCRIPTION "Working example of a Zephyr project managed using VSCode."
	LANGUAGES C CXX
)

include(BuildTargets)

add_subdirectory(src)

include(Tooling)
