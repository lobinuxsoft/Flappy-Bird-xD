#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "class/UIObjects/Button.h"
#include "class/UIObjects/TextButton.h"

using namespace std;
using namespace GameCore;

namespace FlappyBirdXD
{
	class CreditScreen
	{
	private:
		string clickSfxUrl = "";
		string myLinkedinUrl = "https://www.linkedin.com/in/lobinux/";
		TextButton* myLinkedin;
		string parallaxUrl = "https://mobilegamegraphics.com/product/free-parallax-backgrounds/";
		TextButton* parallaxLinkButton;
		string birdSpriteUrl = "https://opengameart.org/content/free-game-asset-grumpy-flappy-bird-sprite-sheets";
		TextButton* birdSpriteLinkButton;
		Button* returnButton;

	public:
		CreditScreen();
		~CreditScreen();
		void update(GameState& gameState);
		void draw();
	};
}

