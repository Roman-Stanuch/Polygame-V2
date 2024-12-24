#include "player.h"
#include "window.h"

#include <iostream>

namespace Polygame {
	namespace Gameplay {
		void Polygame::Gameplay::Player::Tick(float delta_time)
		{
			switch (m_movement_type)
			{
			case Polygame::Gameplay::EMovementType::EMT_Default:
				DefaultMove(delta_time);
				break;
			case Polygame::Gameplay::EMovementType::EMT_Physics:
				PhysicsMove(delta_time);
				break;
			default:
				DefaultMove(delta_time);
				break;
			}

			Object::Tick(delta_time);
		}

		void Player::DefaultMove(float delta_time)
		{
			if (Window::GetKeyDown(87)) {
				Move(glm::vec3(0.f, -1.f, 0.f), m_speed * delta_time);
			}
			if (Window::GetKeyDown(65)) {
				Move(glm::vec3(-1.f, 0.f, 0.f), m_speed * delta_time);
			}
			if (Window::GetKeyDown(83)) {
				Move(glm::vec3(0.f, 1.f, 0.f), m_speed * delta_time);
			}
			if (Window::GetKeyDown(68)) {
				Move(glm::vec3(1.f, 0.f, 0.f), m_speed * delta_time);
			}
		}

		void Player::PhysicsMove(float delta_time)
		{
			// Left and right
			if (GetPosition().x > 0 && Window::GetKeyDown(65)) {
				Move(glm::vec3(-1.f, 0.f, 0.f), m_speed * delta_time);
			}
			if (GetPosition().x < Window::GetWindowWidth() - 100 && Window::GetKeyDown(68)) {
				Move(glm::vec3(1.f, 0.f, 0.f), m_speed * delta_time);
			}

			// Jump
			if (Window::GetKeyDown(32)) {
				Move(glm::vec3(0.f, -m_jump_force, 0.f), m_speed * delta_time);
			}

			// Gravity
			if (GetPosition().y + 100 < Window::GetWindowHeight()) {
				m_falling = true;
				m_falling_time += delta_time;
				Move(glm::vec3(0.f, 1.f, 0.f), 9.8f * m_falling_time * m_falling_time);
			}
			else {
				m_falling = false;
				m_falling_time = 0.f;
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
