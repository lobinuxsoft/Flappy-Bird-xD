#include "ParallaxBackground.h"

ParallaxBackground::ParallaxBackground()
{
	backgrounds.push_back({ LoadTexture("resources/images/layer01.png"),0,0.1f });
	backgrounds.push_back({ LoadTexture("resources/images/layer02.png"),0,0.2f });
	backgrounds.push_back({ LoadTexture("resources/images/layer03.png"),0,0.3f });
	backgrounds.push_back({ LoadTexture("resources/images/layer04.png"),0,0.4f });
	backgrounds.push_back({ LoadTexture("resources/images/layer05.png"),0,0.5f });
	backgrounds.push_back({ LoadTexture("resources/images/layer06.png"),0,0.6f });
	backgrounds.push_back({ LoadTexture("resources/images/layer07.png"),0,0.7f });
	backgrounds.push_back({ LoadTexture("resources/images/layer08.png"),0,0.8f });
}

ParallaxBackground::~ParallaxBackground()
{
	for (Background b : backgrounds)
	{
		UnloadTexture(b.image);
	}
}
