#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "class/UIObjects/Button.h"

using namespace std;

class MainMenuScreen
{
private:
	string clickSfxUrl = "";
	Button* gameplayButton;
	Button* creditsButton;
	Button* quitButton;

public:
	MainMenuScreen();
	~MainMenuScreen();
	void update(GameState& gameState);
	void draw();
};

