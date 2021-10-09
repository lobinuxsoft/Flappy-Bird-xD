#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	gameplayButton = new Button({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f }, "PLAY", clickSfxUrl.c_str());
}

MainMenuScreen::~MainMenuScreen()
{
	delete gameplayButton;
}

void MainMenuScreen::update(GameState& gameState)
{
	gameplayButton->update();

	if (gameplayButton->isClick()) { gameState = GameState::Gameplay; }
}

void MainMenuScreen::draw()
{
	gameplayButton->draw();
}
