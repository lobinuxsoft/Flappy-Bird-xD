#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "class/Objects/Player.h"
#include "class/Objects/Obstacle.h"

using namespace std;

class GameplayScreen
{
private:
	string jumpSfxUrl = "";
	Player* player;

	string obstacleSpriteUrl = "";
	string collisionSfxUrl = "";
	Obstacle* obstacle;

public:
	GameplayScreen();
	~GameplayScreen();
	void update(GameState& gameState);
	void draw();
};

