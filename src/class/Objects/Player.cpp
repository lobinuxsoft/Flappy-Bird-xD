#include "Player.h"

void Player::screenLimitsLogic()
{
	if (position.y > (GetScreenHeight() - radius))
	{
		isAlive = false;
		position = startPosition;
	}
	else if (position.y < radius) 
	{
		isAlive = false;
		position = startPosition;
	}
}

void Player::movement()
{
	if(IsKeyDown(KEY_UP))
	{
		position.y -= speed * GetFrameTime();
	}
	else if(IsKeyDown(KEY_DOWN))
	{
		position.y += speed * GetFrameTime();
	}
}

Player::Player(Vector2 position, const char spriteUrl[], const char jumpSfxUrl[])
	: Entity{position}, startPosition(position), sprite(LoadTexture(spriteUrl)), jumpSfx(LoadSound(jumpSfxUrl)) { }

Player::~Player()
{
	UnloadTexture(sprite);
	UnloadSound(jumpSfx);
}

float Player::getRadius()
{
	return radius;
}

void Player::setIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

bool Player::getIsAlive()
{
	return isAlive;
}


void Player::update()
{
	screenLimitsLogic();
	movement();
}

void Player::draw()
{
	rect = Rectangle{
		position.x - (((float)sprite.width * 0.3f) * pivot.x),
		position.y - (((float)sprite.height * 0.3f) * pivot.y),
		(float)sprite.width * 0.3f,
		(float)sprite.height * 0.3f
	};

	// Draw spaceship
	DrawTexturePro(
		sprite,
		Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },
		rect,
		Vector2{ ((float)sprite.width * 0.3f) * pivot.x, ((float)sprite.height * 0.3f) * pivot.y },
		rotation,
		WHITE);

	// Draw collision
#if _DEBUG
	DrawCircle(position.x, position.y, radius, Fade(GREEN, 0.5f));
#endif // _DEBUG
}
