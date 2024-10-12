#####################
# mylibrary Library #
#####################

add_library(${LIB_TARGET})

set_target_properties(${LIB_TARGET} PROPERTIES
  VERSION       ${${PROJECT_NAME}_VERSION}
  OUTPUT_NAME   ${LIB_TARGET}
)

# Source files ##################################

target_sources(${LIB_TARGET}
  PUBLIC
    testlibrary.cpp
)

target_sources(${LIB_TARGET} PUBLIC
  FILE_SET public_headers
  TYPE HEADERS
  FILES
    testlibrary.hpp
)

# target_sources(${LIB_TARGET} PRIVATE
#   FILE_SET private_headers
#   TYPE HEADERS
#   FILES
#     # ...
# )
