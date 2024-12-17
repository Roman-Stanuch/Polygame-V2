#include "polygame.h"
#include "renderer.h"
#include "object.h"
#include "window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <vector>

namespace Polygame {
	static std::vector<Object> objects;
		
	void Init() {
		Window::CreateWindow(1920, 1080, false);
		Renderer::Init();
	}

	void Init(uint32_t window_width, uint32_t window_height, bool fullscreen) {
		Window::CreateWindow(window_width, window_height, fullscreen);
		Renderer::Init();
	}

	void Start()
	{
		Tick();
	}

	void Tick()
	{
		glfwPollEvents();

		for (Object& object : objects) {
			object.Tick(1.0);
		}

		Renderer::Render();
		Window::SwapBuffers();

		if (Window::IsWindowOpen()) {
			Tick();
		}
	}

	void End()
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

	void AddObject(const Object& object)
	{
		objects.push_back(object);
	}
}