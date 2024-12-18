#include "player.h"
#include "window.h"

void Polygame::Gameplay::Player::Tick(double deltaTime)
{
	if (Window::GetKeyDown(87)) {
		Move(glm::vec3(0.f, -1.f, 0.f), m_speed);
	}
	if (Window::GetKeyDown(65)) {
		Move(glm::vec3(-1.f, 0.f, 0.f), m_speed);
	}
	if (Window::GetKeyDown(83)) {
		Move(glm::vec3(0.f, 1.f, 0.f), m_speed);
	}
	if (Window::GetKeyDown(68)) {
		Move(glm::vec3(1.f, 0.f, 0.f), m_speed);
	}

	Object::Tick(deltaTime);
}

void Polygame::Gameplay::Player::SetSpeed(float speed)
{
	m_speed = speed;
}
