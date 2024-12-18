#pragma once

#include "glm/vec2.hpp"
#include "stdint.h"

struct GLFWwindow;

namespace Polygame {
	namespace Window {
		void CreateWindow(uint32_t width, uint32_t height, bool fullscreen);
		void CloseWindow();
		void SwapBuffers();
		bool IsWindowOpen();

		bool GetKeyDown(const uint32_t key);
		bool GetMouseButtonDown(const uint8_t button);
		glm::vec2 GetMousePosition();

		uint32_t GetWindowWidth();
		uint32_t GetWindowHeight();
	}
}