#include "polygame.h"
#include "object.h"

int main() {
	Polygame::Init(1920, 1080, false);

	Polygame::SetBackgroundColor(0.8, 0.8, 0.9, 1.0);

	if (true) {
		auto test = std::make_shared<Polygame::Object>();
		Polygame::AddObject(test);
	}

	Polygame::Start();
	Polygame::End();

	return 0;
}