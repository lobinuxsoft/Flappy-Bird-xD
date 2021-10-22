#include "ParallaxBackground.h"

ParallaxBackground::ParallaxBackground()
{
	backgrounds.push_back({ LoadTexture("resources/images/background/layer08.png"),0, 0 });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer07.png"),0, 0 });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer06.png"),0,0.2f });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer05.png"),0,0.3f });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer04.png"),0,0.4f });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer03.png"),0,0.5f });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer02.png"),0,0.6f });
	backgrounds.push_back({ LoadTexture("resources/images/background/layer01.png"),0,0.7f });
}

ParallaxBackground::~ParallaxBackground()
{
	for (size_t i = 0; i < backgrounds.size(); i++)
	{
		UnloadTexture(backgrounds[i].image);
	}
}

void ParallaxBackground::update()
{
	for (size_t i = 0; i < backgrounds.size(); i++)
	{
		backgrounds[i].scrolling -= backgrounds[i].speed;
		if (backgrounds[i].scrolling <= -(backgrounds[i].image.width * scale)) backgrounds[i].scrolling = 0;
	}
}

void ParallaxBackground::draw()
{
	for (size_t i = 0; i < backgrounds.size(); i++)
	{
		DrawTextureEx(backgrounds[i].image, { backgrounds[i].scrolling, 0}, 0.0f, scale, WHITE);
		DrawTextureEx(backgrounds[i].image, { backgrounds[i].image.width * scale + backgrounds[i].scrolling, 0 }, 0.0f, scale, WHITE);
	}
}
