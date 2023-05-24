add_subdirectory(models)
add_subdirectory(controllers)
add_subdirectory(views)

set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)

set(SRC 
    ${SRCROOT}/main.cpp
)

if ("${SRC}" STREQUAL "")
	message("Main source not found")
else()
	message("Main building...")
    add_executable(main ${SRC})

	target_link_libraries(main PUBLIC models)

	target_link_libraries(main PUBLIC controllers)
	
	target_link_libraries(main PUBLIC views)


	target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(main PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)
    target_link_libraries(main PUBLIC qcustomplot)
endif()