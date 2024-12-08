#pragma once
#include "stdint.h"

struct GLFWwindow;

GLFWwindow* CreateWindow(uint32_t width, uint32_t height, bool fullscreen);