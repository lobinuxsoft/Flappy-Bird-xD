#pragma once
#include <string>

#include "Class/Entity.h"

using namespace std;

class TextButton : public Entity
{
private:
	string text = "";
	int fontSize = 10;
	string linkUrl = "";
	Color normalColor = WHITE;
	Color hoverColor = BLUE;
	Color pressColor = DARKBLUE;
	Rectangle rect{ 0,0,0,0 };
	Vector2 pivot = { 0.0f, 0.0f };
	bool hover = false;
	bool press = false;
	bool click = false;

private:
	void mouseCollision();

public:
	TextButton(Vector2 position, string text, int fontsize = 10, string linkUrl = "", Color normalColor = WHITE, Color hoverColor = BLUE, Color pressColor = DARKBLUE);
	~TextButton() override;
	void setPivot(Vector2 pivot);
	void setText(string text);
	bool isClick();
	void update();
	void draw() override;
};

