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
			virtual void Tick(double deltaTime) override;

			void SetSpeed(float speed);
			void SetMovementType(const EMovementType new_type);

		private:
			float m_speed = 5.f;
			EMovementType m_movement_type = EMovementType::EMT_Default;
			
			void DefaultMove();
			void PhysicsMove();
		};
	}
}