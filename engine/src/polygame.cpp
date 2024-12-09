#include "polygame.h"
#include "renderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace Polygame {
	void Init() {
		Window::CreateWindow(1920, 1080, false);
		Renderer::Init();
	}

	void Init(uint32_t window_width, uint32_t window_height, bool fullscreen) {
		Window::CreateWindow(window_width, window_height, fullscreen);
		Renderer::Init();
	}

	void Tick()
	{
		glfwPollEvents();
		Renderer::Render();
		Window::SwapBuffers();
	}

	void Deinit()
	{
		if (glGetError() != GL_NO_ERROR) {
			std::cout << "OpenGL Error Code: " << glGetError() << std::endl;
		}

		Renderer::Deinit();
		Window::CloseWindow();
	}

	void SetBackgroundColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
}