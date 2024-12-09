add_library(polygame STATIC "src/window.cpp" "src/renderer.cpp" "src/utilities/glad.c" "src/renderer.h" "src/renderer.cpp" "src/polygame.cpp" "src/classes/shader.h" "src/classes/shader.cpp")

target_link_libraries(polygame
    PRIVATE 
    glfw3
)

target_include_directories(polygame
    PRIVATE 
    src
    src/classes
    includes
)