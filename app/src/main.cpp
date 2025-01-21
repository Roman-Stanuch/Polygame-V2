#include "polygame.h"
#include "gameplay/player.h"
#include <iostream>

using namespace Polygame;

int main() {
	Polygame::Init(1920, 1080, false);

	Polygame::SetBackgroundColor(0.8f, 0.8f, 0.9f, 1.0f);

	if (true) {
		DrawInfo new_draw_info;
		new_draw_info.scale = glm::vec3(100.f, 100.f, 100.f);
		new_draw_info.texture_name = "tex";
		new_draw_info.texture_path = "album_cover.png";
		new_draw_info.color = glm::vec3(0.f, 0.f, 0.f);
		auto test = std::make_shared<Gameplay::Player>();
		Polygame::AddObject(test);
	}

	Polygame::Start();
	Polygame::End();

	return 0;
}