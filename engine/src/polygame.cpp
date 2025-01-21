#include "polygame.h"
#include "renderer.h"
#include "object.h"
#include "window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <vector>

static float last_time = 0.f;
static float delta_time = 0.f;

namespace Polygame {
	static std::vector<std::shared_ptr<Object>> objects;
	static Renderer* renderer = nullptr;

	void Init() {
		Window::CreateWindow(1920, 1080, false);
		renderer = new Renderer(1920, 1080);
	}

	void Init(uint32_t window_width, uint32_t window_height, bool fullscreen) {
		Window::CreateWindow(window_width, window_height, fullscreen);
		renderer = new Renderer(window_width, window_height);
	}

	void Start()
	{
		while (Window::IsWindowOpen()) {
			Tick();
		}
	}

	void Tick()
	{
		delta_time = GetDeltaTime();
		glfwPollEvents();
		
		// Tick and/or delete objects and add them to the render queue if visible
		for (int i = 0; i < objects.size(); i++) {
			auto& object = objects[i];

			if (object->ShouldDelete()) {
				objects.erase(objects.begin() + i);
				continue;
			}

			object->Tick(delta_time);

			if (object->GetVisibility() == true) {
				renderer->AddDrawObject(object->GetDrawInfo());
			}
		}

		renderer->Render();
		Window::SwapBuffers();
	}

	void End()
	{
		if (glGetError() != GL_NO_ERROR) {
			std::cout << "OpenGL Error Code: " << glGetError() << std::endl;
		}

		delete renderer;
		Window::CloseWindow();
	}

	float GetDeltaTime() {
		float currentTime = (float)glfwGetTime();
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