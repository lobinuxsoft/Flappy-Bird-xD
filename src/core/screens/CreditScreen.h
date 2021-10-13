#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "class/UIObjects/Button.h"
#include "class/UIObjects/TextButton.h"

using namespace std;

class CreditScreen
{
private:
	string clickSfxUrl = "";
	string myLinkedinUrl = "https://www.linkedin.com/in/lobinux/";
	TextButton* myLinkedin;
	string parallaxUrl = "https://mobilegamegraphics.com/product/free-parallax-backgrounds/";
	TextButton* parallaxLinkButton;
	Button* returnButton;

public:
	CreditScreen();
	~CreditScreen();
	void update(GameState& gameState);
	void draw();
};

