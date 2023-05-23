set(SRCROOT ${PROJECT_SOURCE_DIR}/src/models)
set(INCROOT ${PROJECT_SOURCE_DIR}/include/models)

set(SRC
    
)

add_library(models ${SRC})

target_include_directories(models PUBLIC ${PROJECT_SOURCE_DIR}/include/)