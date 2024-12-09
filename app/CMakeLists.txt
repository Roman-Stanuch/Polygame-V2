add_executable(app
    src/main.cpp
)

target_link_libraries(app
    PRIVATE 
        polygame
        ../../../engine/libs/glfw3
)

target_include_directories(app
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/engine/src
)