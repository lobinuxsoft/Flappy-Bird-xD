#include "GameplayScreen.h"

GameplayScreen::GameplayScreen()
{
	player = new Player({ GetScreenWidth() * 0.15f, GetScreenHeight() * 0.5f }, playerSpriteUrl.c_str(), jumpSfxUrl.c_str());
	player->setPivot({ 0.5f,0.5f });

	obstacle = new Obstacle({ (float)GetScreenWidth(), GetScreenHeight() * 0.5f }, obstacleSpriteUrl.c_str(), collisionSfxUrl.c_str());
	obstacle->setPivot({ 0.5f,0.5f });
}

GameplayScreen::~GameplayScreen()
{
	delete player;
	delete obstacle;
}

void GameplayScreen::update(GameState& gameState)
{
	player->update();

	if (!player->getIsAlive())
	{
		gameState = GameState::MainMenu;
		player->setIsAlive(true);
		obstacle->resetPos();
	}

	obstacle->update();
	if(obstacle->isCollideWithCircle(player->getPosition(), player->getRadius())) 
	{
		player->setIsAlive(false);
	}
}

void GameplayScreen::draw()
{
	player->draw();
	obstacle->draw();
}
