#include "test.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

GLFWwindow* CreateWindow(uint32_t width, uint32_t height, bool fullscreen)
{
	GLFWwindow* newWindow;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);

	GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
	newWindow = glfwCreateWindow(width, height, "Polygame", monitor, nullptr);
	glfwMakeContextCurrent(newWindow);

	// Glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(newWindow, [](GLFWwindow* window, int width, int height)
		{
			// Make sure the viewport matches the new window dimensions
			glViewport(0, 0, width, height);
	});

	return newWindow;
}