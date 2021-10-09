#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameEnums.h"
#include "class/UIObjects/Button.h"

using namespace std;

class MainMenuScreen
{
private:
	string clickSfxUrl = "";
	Button* gameplayButton;

public:
	MainMenuScreen();
	~MainMenuScreen();
	void update(GameState& gameState);
	void draw();
};

