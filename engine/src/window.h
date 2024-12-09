#pragma once
#include "stdint.h"

struct GLFWwindow;

namespace Polygame {
	namespace Window {
		void CreateWindow(uint32_t width, uint32_t height, bool fullscreen);
		void CloseWindow();
		void SwapBuffers();
		bool IsWindowOpen();

		uint32_t GetWindowWidth();
		uint32_t GetWindowHeight();
	}
}