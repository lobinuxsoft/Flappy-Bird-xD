#pragma once
#include <vector>

#include "raylib.h"

using namespace std;

struct Background
{
	Texture2D image;
	float scrolling = 0.0f;
	float speed = 0.0f;
};

class ParallaxBackground
{
private:
	vector<Background> backgrounds;
	float scale = (float)GetScreenHeight() / (float)GetScreenWidth();

public:
	ParallaxBackground();
	~ParallaxBackground();
	void update();
	void draw();
	// TODO terminar parallax
};

