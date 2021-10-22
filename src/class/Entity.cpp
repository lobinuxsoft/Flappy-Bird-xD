#include "Entity.h"

namespace GameCore
{
	Entity::Entity(Vector2 position) : position(position) { }

	Entity::~Entity() { }

	void Entity::setPosition(Vector2 position)
	{
		this->position = position;
	}

	Vector2 Entity::getPosition()
	{
		return position;
	}
}