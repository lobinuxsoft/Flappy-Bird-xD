#include "CreditScreen.h"

CreditScreen::CreditScreen()
{

	myLinkedin = new TextButton({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.2f }, "Created by Matias Galarza", 30, myLinkedinUrl, BLACK);
	myLinkedin->setPivot({ 0.5f,0.5f });

	parallaxLinkButton = new TextButton({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.25f }, "Free Game Backgrounds created by mobilegamegraphics.com", 30, parallaxUrl, BLACK);
	parallaxLinkButton->setPivot({ 0.5f,0.5f });

	birdSpriteLinkButton = new TextButton({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.3f }, "Flappy Bird Sprite Sheets created by bevouliin.com", 30, birdSpriteUrl, BLACK);
	birdSpriteLinkButton->setPivot({ 0.5f,0.5f });

	returnButton = new Button({ GetScreenWidth() * 0.5f, GetScreenHeight() - 50.0f }, "Volver", clickSfxUrl.c_str(), GetScreenHeight() * 0.05f, 20);
	returnButton->setPivot({ 0.5f,0.5f });
}

CreditScreen::~CreditScreen()
{
	delete myLinkedin;
	delete parallaxLinkButton;
	delete birdSpriteLinkButton;
	delete returnButton;
}

void CreditScreen::update(GameState& gameState)
{
	myLinkedin->update();
	myLinkedin->isClick();

	parallaxLinkButton->update();
	parallaxLinkButton->isClick();

	birdSpriteLinkButton->update();
	birdSpriteLinkButton->isClick();

	returnButton->update();

	if (returnButton->isClick()) { gameState = GameState::MainMenu; }
}

void CreditScreen::draw()
{
	DrawText("Creditos", GetScreenWidth() * 0.5f - (MeasureText("Creditos", GetScreenHeight() * 0.125f) * 0.5f), 0, GetScreenHeight() * 0.125f, BLACK);
	myLinkedin->draw();
	parallaxLinkButton->draw();
	birdSpriteLinkButton->draw();
	returnButton->draw();

	DrawText(gameVersion, GetScreenWidth() - MeasureText(gameVersion, 20) - 10, GetScreenHeight() - 30, 20, WHITE);
}

