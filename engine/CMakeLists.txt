add_library(polygame STATIC "src/window.cpp" "src/renderer.cpp" "src/utilities/glad.c" "src/renderer.h" "src/renderer.cpp" "src/polygame.cpp" "src/classes/shader.h" "src/classes/shader.cpp")

target_include_directories(polygame
    PRIVATE 
    src
    src/classes
    includes
)