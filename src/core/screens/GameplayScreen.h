#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameEnums.h"
#include "class/Objects/Player.h"

using namespace std;

class GameplayScreen
{
private:
	string playerSpriteUrl = "";
	string jumpSfxUrl = "";
	Player* player;

public:
	GameplayScreen();
	~GameplayScreen();
	void update(GameState& gameState);
	void draw();
};

