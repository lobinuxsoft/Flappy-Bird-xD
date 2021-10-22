#include "Obstacle.h"

void Obstacle::screenLimitsLogic()
{
	if (position.x < -width)
	{
		int verticalOffsetInt = static_cast<int>(verticalOffset);
		position.x = GetScreenWidth() + width;
		position.y = static_cast<float>(GetRandomValue(verticalOffsetInt, GetScreenHeight() - verticalOffsetInt));
	}
}

void Obstacle::movement()
{
	position.x -= speed * GetFrameTime();
}

Obstacle::Obstacle(Vector2 position, const char spriteUrl[], const char collisionSfxUrl[])
	: Entity { position }, sprite(LoadTexture(spriteUrl)), collisionSfx(LoadSound(collisionSfxUrl))
{
	width = GetScreenWidth() * 0.1f;
	position.x += width;
}

Obstacle::~Obstacle()
{
	UnloadTexture(sprite);
	UnloadSound(collisionSfx);
}

void Obstacle::setPivot(Vector2 pivot)
{
	this->pivot = pivot;
}

void Obstacle::resetPos()
{
	position.x = GetScreenWidth() + width;
}

bool Obstacle::isCollideWithCircle(Vector2 position, float radius)
{
	return CheckCollisionCircleRec(position, radius, rectDown) || CheckCollisionCircleRec(position, radius, rectUp);
}

void Obstacle::update()
{
	screenLimitsLogic();
	movement();
}

void Obstacle::draw()
{
	// Down obstacle
	rectDown = Rectangle
	{
		position.x - (width * pivot.x),
		0,
		width,
		position.y - verticalOffset
	};

	// Up Obstacle
	rectUp = Rectangle
	{
		position.x - (width * pivot.x),
		position.y + verticalOffset,
		width,
		GetScreenHeight() - (position.y)
	};

	// Draw collision
#if _DEBUG
	DrawRectangle(static_cast<int>(rectDown.x), static_cast<int>(rectDown.y), static_cast<int>(rectDown.width), static_cast<int>(rectDown.height), Fade(RED, 0.5f));
	DrawRectangle(static_cast<int>(rectUp.x), static_cast<int>(rectUp.y), static_cast<int>(rectUp.width), static_cast<int>(rectUp.height), Fade(RED, 0.5f));
	DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), 10, WHITE);
#endif // _DEBUG
}
