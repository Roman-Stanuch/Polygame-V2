#include "window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

static GLFWwindow* currentWindow = nullptr;
uint32_t CURRENT_WIDTH = 0;
uint32_t CURRENT_HEIGHT = 0;

namespace Polygame {
	namespace Window {
		void CreateWindow(uint32_t width, uint32_t height, bool fullscreen) {
			GLFWwindow* newWindow;

			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, false);

			GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
			newWindow = glfwCreateWindow(width, height, "Polygame", monitor, nullptr);
			glfwMakeContextCurrent(newWindow);

			// Glad: load all OpenGL function pointers
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				std::cout << "Failed to initialize GLAD" << std::endl;
			}
			glViewport(0, 0, width, height);

			glfwSetFramebufferSizeCallback(newWindow, [](GLFWwindow* window, int width, int height) {
				// Make sure the viewport matches the new window dimensions
				glViewport(0, 0, width, height);
			});

			glfwSetWindowCloseCallback(newWindow, [](GLFWwindow* window) {
				currentWindow = nullptr;
			});

			currentWindow = newWindow;
			CURRENT_WIDTH = width;
			CURRENT_HEIGHT = height;
		}

		void CloseWindow()
		{
			if (currentWindow) {
				glfwDestroyWindow(currentWindow);
				currentWindow = nullptr;
			}

			glfwTerminate();
		}

		void SwapBuffers()
		{
			if (currentWindow) {
				glfwSwapBuffers(currentWindow);
			}
		}

		bool IsWindowOpen()
		{
			return !(currentWindow == nullptr);
		}

		bool GetKeyDown(const uint32_t key)
		{
			if (currentWindow == nullptr) return false;
			return glfwGetKey(currentWindow, key) == GLFW_PRESS;
		}

		bool GetMouseButtonDown(const uint8_t button)
		{
			if (currentWindow == nullptr) return false;
			return glfwGetMouseButton(currentWindow, button) == GLFW_PRESS;
		}

		glm::vec2 GetMousePosition()
		{
			if (currentWindow == nullptr) return glm::vec2(0.f, 0.f);
			double xpos, ypos;
			glfwGetCursorPos(currentWindow, &xpos, &ypos);
			return glm::vec2(xpos, ypos);
		}

		uint32_t GetWindowWidth()
		{
			return CURRENT_WIDTH;
		}

		uint32_t GetWindowHeight()
		{
			return CURRENT_HEIGHT;
		}
	}
}