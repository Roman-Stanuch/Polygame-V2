#include "polygame.h"

int main() {
	Polygame::Init(1920, 1080, false);
	Polygame::SetBackgroundColor(0.8, 0.8, 0.9, 1.0);

	while (Polygame::Window::IsWindowOpen())
	{
		Polygame::Tick();
	}

	Polygame::Deinit();

	return 0;
}