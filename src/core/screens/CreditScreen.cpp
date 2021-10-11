#include "CreditScreen.h"

CreditScreen::CreditScreen()
{

	myLinkedin = new TextButton({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.2f }, "Created by Matias Galarza", 30, myLinkedinUrl);
	myLinkedin->setPivot({ 0.5f,0.5f });

	returnButton = new Button({ GetScreenWidth() * 0.5f, GetScreenHeight() - 50.0f }, "Volver", clickSfxUrl.c_str(), GetScreenHeight() * 0.05f, 20);
	returnButton->setPivot({ 0.5f,0.5f });
}

CreditScreen::~CreditScreen()
{
	delete myLinkedin;
	delete returnButton;
}

void CreditScreen::update(GameState& gameState)
{
	myLinkedin->update();
	myLinkedin->isClick();

	returnButton->update();

	if (returnButton->isClick()) { gameState = GameState::MainMenu; }
}

void CreditScreen::draw()
{
	DrawText("Creditos", GetScreenWidth() * 0.5f - (MeasureText("Creditos", GetScreenHeight() * 0.125f) * 0.5f), 0, GetScreenHeight() * 0.125f, WHITE);
	myLinkedin->draw();
	returnButton->draw();

	DrawText(gameVersion, GetScreenWidth() - MeasureText(gameVersion, 20) - 10, GetScreenHeight() - 30, 20, WHITE);
}

