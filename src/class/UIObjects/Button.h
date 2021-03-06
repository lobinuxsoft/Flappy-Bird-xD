#pragma once

#include <string>

#include "Class/Entity.h"

using namespace std;

namespace GameCore
{
	class Button : public Entity
	{
	private:
		string text = "";
		Sound clickSfx;
		int fontSize = 10;
		Color textColor = WHITE;
		Color normalColor = BLUE;
		Color pressColor = DARKBLUE;
		float hMargin = 5;
		float vMargin = 5;
		float roundness = 0.5f;
		int segment = 16;
		int tickness = 1;
		Rectangle rect{ 0,0,0,0 };
		Vector2 pivot = { 0.0f, 0.0f };
		bool hover = false;
		bool press = false;
		bool click = false;

	private:
		void mouseCollision();

	public:
		Button(
			Vector2 position,
			string text,
			const char clickSfxUrl[],
			int fontSize = 20,
			float hMargin = 10,
			float vMargin = 10,
			float roundness = 1,
			int segment = 16,
			int tickness = 5,
			Color textColor = WHITE,
			Color normalColor = BLUE,
			Color pressColor = DARKBLUE
		);

		~Button() override;
		void setPivot(Vector2 pivot);
		void setText(string text, Color color = WHITE);
		void setNormalColor(Color color);
		void setPressColor(Color color);
		bool isClick();
		void update();
		void draw() override;
	};
}