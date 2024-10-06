##############
# App Target #
##############

# Dependencies ##################################

target_link_libraries(${APP_TARGET} PRIVATE ${LIB_TARGET})

# Source files ##################################

target_sources(${APP_TARGET}
	PRIVATE
		main.c 
)
