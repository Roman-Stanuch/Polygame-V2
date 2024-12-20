#include "player.h"
#include "window.h"

#include <iostream>

namespace Polygame {
	namespace Gameplay {
		void Polygame::Gameplay::Player::Tick(double deltaTime)
		{
			switch (m_movement_type)
			{
			case Polygame::Gameplay::EMovementType::EMT_Default:
				DefaultMove();
				break;
			case Polygame::Gameplay::EMovementType::EMT_Physics:
				PhysicsMove();
				break;
			default:
				DefaultMove();
				break;
			}

			Object::Tick(deltaTime);
		}

		void Player::DefaultMove()
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
		}

		void Player::PhysicsMove()
		{
			if (Window::GetKeyDown(65)) {
				Move(glm::vec3(-1.f, 0.f, 0.f), m_speed);
			}
			if (Window::GetKeyDown(68)) {
				Move(glm::vec3(1.f, 0.f, 0.f), m_speed);
			}

			if (GetPosition().y + 100 < Window::GetWindowHeight()) {
				Move(glm::vec3(0.f, 1.f, 0.f), 1.f);
			}
		}

		void Polygame::Gameplay::Player::SetSpeed(float speed)
		{
			m_speed = speed;
		}

		void Polygame::Gameplay::Player::SetMovementType(const EMovementType new_type)
		{
			m_movement_type = new_type;
		}
	}
}
