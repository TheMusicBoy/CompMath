set(INCROOT ${PROJECT_SOURCE_DIR}/include/controllers)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/controllers)

set(SRC
	${INCROOT}/calc.hpp
	${SRCROOT}/calc.cpp
)

if("${SRC}" STREQUAL "")
	message("Controller source not found")
	set(controllers_CREATED FALSE)
else()
    add_library(controllers ${SRC})

    target_include_directories(controllers PUBLIC ${PROJECT_SOURCE_DIR}/include/)
	set(controllers_CREATED TRUE)
endif()