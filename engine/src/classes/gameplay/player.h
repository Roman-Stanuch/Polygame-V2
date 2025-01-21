#pragma once

#include "object.h"

namespace Polygame {
	namespace Gameplay {
		enum class EMovementType {
			EMT_Default,
			EMT_Physics
		};

		class Player : public Object {
		public:
			Player() : Object() {}
			Player(const DrawInfo& draw_info) : Object(draw_info) {}
			virtual void Tick(float delta_time) override;

			void SetSpeed(float speed);
			void SetMovementType(const EMovementType new_type);

		private:
			EMovementType m_movement_type = EMovementType::EMT_Default;
			float m_speed = 1000.f;
			float m_jump_force = 3.f;
			bool m_falling = false;
			float m_falling_time = 0.f;
			
			void DefaultMove(float delta_time);
			void PhysicsMove(float delta_time);
		};
	}
}