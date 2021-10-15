#pragma once
#include "class/Entity.h"

#include <vector>

using namespace std;

class Player : public Entity
{
private:
	const float defaultRadius = 20.0;
	const float speed = 512;

	vector<Texture2D> sprite;
	float spriteScale = 0.1f;
	int spriteIndex = 0;
	Sound jumpSfx;
	Rectangle rect{ 0,0,0,0 };
	Vector2 pivot = { 0, 0 };
	Vector2 startPosition = { 0,0 };
	float rotation = 0;
	float radius = defaultRadius;
	bool isAlive = true;
	bool isPlayable = false;
	int frameCounter = 0;
	int frameSpeed = 8;
	float acceleration = 0;
	float velocity = 0;

private:
	void screenLimitsLogic();
	void movement();

public:
	Player(Vector2 position, const char jumpSfxUrl[]);
	~Player() override;
	void setPivot(Vector2 pivot);
	float getRadius();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	void update();
	void draw();
};

