set(INCROOT ${PROJECT_SOURCE_DIR}/include/views)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/views)

set(SRC
    ${INCROOT}/plot.hpp
    ${SRCROOT}/plot.cpp
	${INCROOT}/object_manager.hpp
	${INCROOT}/nav_bar.hpp
	${SRCROOT}/nav_bar.cpp
	${INCROOT}/main_interface.hpp
	${SRCROOT}/main_interface.cpp
)

if("${SRC}" STREQUAL "")
	message("Views source not found")
	set(views_CREATED FALSE)
else()
    add_library(views ${SRC})

    target_include_directories(views PUBLIC ${PROJECT_SOURCE_DIR}/include/)

    target_link_libraries(views PUBLIC models)
	target_link_libraries(views PUBLIC controllers)
	
	target_link_libraries(views PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)
    target_link_libraries(views PUBLIC qcustomplot)
	
	set(views_CREATED TRUE)
endif()