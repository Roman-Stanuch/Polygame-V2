add_library(polygame STATIC 
    "src/test.cpp"
    "src/utilities/glad.c"
)

target_link_libraries(polygame
    PRIVATE 
    glfw3
)

target_include_directories(polygame
    PRIVATE 
        src
        includes
)