#include "polygame.h"
#include "gameplay/player.h"

using namespace Polygame;

int main() {
	Polygame::Init(1920, 1080, false);

	Polygame::SetBackgroundColor(0.8f, 0.8f, 0.9f, 1.0f);

	if (true) {
		auto test = std::make_shared<Gameplay::Player>();
		test->SetMovementType(Gameplay::EMovementType::EMT_Physics);
		Polygame::AddObject(test);
	}

	Polygame::Start();
	Polygame::End();

	return 0;
}