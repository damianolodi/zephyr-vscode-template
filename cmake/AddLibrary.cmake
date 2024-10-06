##############
# AddLibrary #
##############

# Wrap the default `add_library` function so that library files can be included like
# ```
# #include "<libname>/<filename>.hpp"
# ```
# without the need of a separate `include` folder.
#
# ==> set `target_include_directories` for library targets so this scheme can be used.
# WARNING: library targets themselves should NOT set public/interface includes within the library tree.

function(add_library target)
	_add_library(${target} ${ARGN})
	# message(STATUS "This is called for ${target} with dir: ${CMAKE_CURRENT_LIST_DIR}")
	
  # Ensure this directory is included as an interface include
	target_include_directories(${target} PUBLIC ${LIBRARY_ROOT_DIR})
endfunction()
