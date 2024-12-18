#pragma once

#include "object.h"

namespace Polygame {
	namespace Gameplay {
		class Player : public Object {
		public:
			virtual void Tick(double deltaTime) override;

			void SetSpeed(float speed);

		private:
			float m_speed = 5.f;
		};
	}
}