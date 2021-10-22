#pragma once
#include "Utils/Vector2Utils.h"

using namespace GameUtils;

namespace GameCore
{
	class Entity
	{
	protected:
		Vector2 position;

	public:
		Entity(Vector2 position);
		virtual ~Entity();
		void setPosition(Vector2 position);
		Vector2 getPosition();
		virtual void draw() = 0;
	};
}