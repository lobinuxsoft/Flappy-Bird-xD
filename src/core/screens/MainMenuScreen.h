#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "class/UIObjects/Button.h"

using namespace std;
using namespace GameCore;

namespace FlappyBirdXD
{
	class MainMenuScreen
	{
	private:
		string clickSfxUrl = "";
		float verticalOffset = 60;
		Button* gameplayButton;
		Button* creditsButton;
		Button* quitButton;

	public:
		MainMenuScreen();
		~MainMenuScreen();
		void update(GameState& gameState);
		void draw();
	};
}

