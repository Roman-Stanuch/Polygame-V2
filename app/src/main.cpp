#include "polygame.h"
#include "object.h"

int main() {
	Polygame::Init(1920, 1080, false);

	Polygame::SetBackgroundColor(0.8, 0.8, 0.9, 1.0);

	Polygame::Object test;
	Polygame::AddObject(test);

	Polygame::Start();
	Polygame::End();

	return 0;
}