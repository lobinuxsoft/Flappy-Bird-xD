#pragma once
#include "class/Entity.h"

class Obstacle : public Entity
{
private:
	const float verticalOffset = 100;
	const float speed = 100;

	Texture2D sprite;
	Sound collisionSfx;
	Rectangle rectUp{ 0,0,0,0 };
	Rectangle rectDown{ 0,0,0,0 };
	Vector2 pivot = { 0, 0 };
	float width = 0;

private:
	void screenLimitsLogic();
	void movement();

public:
	Obstacle(Vector2 position, const char spriteUrl[], const char collisionSfxUrl[]);
	~Obstacle();
	void setPivot(Vector2 pivot);
	void resetPos();
	bool isCollideWithCircle(Vector2 position, float radius);
	void update();
	void draw();
};

