#include "GameplayScreen.h"

GameplayScreen::GameplayScreen()
{
	player = new Player({ GetScreenWidth() * 0.15f, GetScreenHeight() * 0.5f }, playerSpriteUrl.c_str(), jumpSfxUrl.c_str());
}

GameplayScreen::~GameplayScreen()
{
	delete player;
}

void GameplayScreen::update(GameState& gameState)
{
	player->update();

	if (!player->getIsAlive())
	{
		gameState = GameState::MainMenu;
		player->setIsAlive(true);
	}
}

void GameplayScreen::draw()
{
	player->draw();
}
