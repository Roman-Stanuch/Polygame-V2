#include "polygame.h"
#include "renderer.h"
#include "object.h"
#include "window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <vector>
#include <memory>

static float last_time = 0.f;
static float delta_time = 0.f;

namespace Polygame {
	static std::vector<std::shared_ptr<Object>> objects;

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
		while (Window::IsWindowOpen())
		{
			Tick();
		}
	}

	void Tick()
	{
		delta_time = GetDeltaTime();
		glfwPollEvents();
		
		for (int i = 0; i < objects.size(); i++) {
			auto& object = objects[i];
			object->Tick(delta_time);

			if (object->ShouldDelete()) {
				objects.erase(objects.begin() + i);
			}
		}

		Renderer::Render();
		Window::SwapBuffers();
	}

	void End()
	{
		if (glGetError() != GL_NO_ERROR) {
			std::cout << "OpenGL Error Code: " << glGetError() << std::endl;
		}

		Renderer::Deinit();
		Window::CloseWindow();
	}

	float GetDeltaTime() {
		float currentTime = glfwGetTime();
		float delta = currentTime - last_time;
		last_time = currentTime;
		return delta;
	}

	void SetBackgroundColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}

	void AddObject(std::shared_ptr<Object> object)
	{
		objects.push_back(object);
	}
}