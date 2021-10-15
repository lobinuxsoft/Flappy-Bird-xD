#include "Player.h"

void Player::screenLimitsLogic()
{
	if (position.y > (GetScreenHeight() - radius))
	{
		setIsAlive(false);
	}
	else if (position.y < radius) 
	{
		setIsAlive(false);
	}
}

void Player::movement()
{
	if(IsMouseButtonPressed(0))
	{
		acceleration = 0;
		velocity = -speed / 2.5f;
	}
	else
	{
		acceleration += speed * GetFrameTime();
	}

	acceleration = (acceleration >= speed) ? speed : acceleration;

	velocity += acceleration * GetFrameTime();
	position.y += velocity * GetFrameTime();

	rotation = Lerp(0, 90, Clamp(velocity / speed, -1.0f, 1.0f));
}

Player::Player(Vector2 position, const char jumpSfxUrl[])
	: Entity{position}, startPosition(position), jumpSfx(LoadSound(jumpSfxUrl))
{ 
	sprite.push_back(LoadTexture("resources/images/bird/Frame-1.png"));
	sprite.push_back(LoadTexture("resources/images/bird/Frame-2.png"));
	sprite.push_back(LoadTexture("resources/images/bird/Frame-3.png"));
	sprite.push_back(LoadTexture("resources/images/bird/Frame-4.png"));
}

Player::~Player()
{
	for (int i = 0; i < sprite.size(); i++)
	{
		UnloadTexture(sprite[i]);
	}

	UnloadSound(jumpSfx);
}

void Player::setPivot(Vector2 pivot)
{
	this->pivot = pivot;
}

float Player::getRadius()
{
	return radius;
}

void Player::setIsAlive(bool isAlive)
{
	this->isPlayable = false;
	this->position = startPosition;
	this->rotation = 0;
	this->isAlive = isAlive;
}

bool Player::getIsAlive()
{
	return isAlive;
}

void Player::update()
{
	if (isPlayable)
	{
		screenLimitsLogic();
		movement();
	}
	else
	{
		if (IsMouseButtonPressed(0))
		{
			isPlayable = true;
			velocity = -speed / 2.5f;
		}
	}
}

void Player::draw()
{
	frameCounter++;
	if (frameCounter >= (60 / frameSpeed))
	{
		frameCounter = 0;
		spriteIndex++;

		if (spriteIndex > sprite.size() - 1) spriteIndex = 0;
	}

	rect = Rectangle{
		position.x,
		position.y,
		sprite[spriteIndex].width * spriteScale,
		sprite[spriteIndex].height * spriteScale
	};

	// Draw spaceship
	DrawTexturePro(
		sprite[spriteIndex],
		Rectangle{ 0,0,(float)sprite[spriteIndex].width,(float)sprite[spriteIndex].height },
		rect,
		Vector2{ (sprite[spriteIndex].width * spriteScale) / 2, (sprite[spriteIndex].height * spriteScale) / 2 },
		rotation,
		WHITE);

	// Draw collision
#if _DEBUG
	DrawCircle(position.x, position.y, radius, Fade(GREEN, 0.5f));
#endif // _DEBUG
}
