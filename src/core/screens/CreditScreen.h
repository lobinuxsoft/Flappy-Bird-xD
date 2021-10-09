#pragma once
#include <string>

#include "raylib.h"

#include "utils/GameEnums.h"
#include "class/UIObjects/Button.h"
#include "class/UIObjects/TextButton.h"

using namespace std;

class CreditScreen
{
private:
	string clickSfxUrl = "";
	string myLinkedinUrl = "https://www.linkedin.com/in/lobinux/";
	TextButton* myLinkedin;
	Button* returnButton;

public:
	CreditScreen();
	~CreditScreen();
	void update(GameState& gameState);
	void draw();
};

