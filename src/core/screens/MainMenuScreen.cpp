#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	gameplayButton = new Button({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.3f }, "Jugar", clickSfxUrl.c_str(), GetScreenHeight() * 0.1f, 40);
	gameplayButton->setPivot({ 0.5f, 0.5f });
	creditsButton = new Button({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.48f }, "Creditos", clickSfxUrl.c_str(), GetScreenHeight() * 0.1f, 40);
	creditsButton->setPivot({ 0.5f, 0.5f });
}

MainMenuScreen::~MainMenuScreen()
{
	delete gameplayButton;
	delete creditsButton;
}

void MainMenuScreen::update(GameState& gameState)
{
	gameplayButton->update();
	creditsButton->update();

	if (gameplayButton->isClick()) { gameState = GameState::Gameplay; }
	if (creditsButton->isClick()) { gameState = GameState::Credits; }
}

void MainMenuScreen::draw()
{
	DrawText("Flappy Bird xD", GetScreenWidth() * 0.5f - (MeasureText("Flappy Bird xD", GetScreenHeight() * 0.15f) * 0.5f), 0, GetScreenHeight() * 0.15f, WHITE);
	gameplayButton->draw();
	creditsButton->draw();
	DrawText("version 0.1", GetScreenWidth() - MeasureText("version 0.1", 20) - 10, GetScreenHeight() - 30, 20, WHITE);
}
