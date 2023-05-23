set(SRCROOT ${PROJECT_SOURCE_DIR}/src/models)
set(INCROOT ${PROJECT_SOURCE_DIR}/include/models)

set(SRC
    ${INCROOT}/data.hpp
    ${SRCROOT}/data.cpp
)

add_library(models ${SRC})

target_include_directories(models PUBLIC ${PROJECT_SOURCE_DIR}/include/)