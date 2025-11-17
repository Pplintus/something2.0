#pragma once
#include <SFML/Graphics.hpp>
#include "windows.h"

////////////////////////////—“≈Õ » » Õ¿ƒœ»—»///////////////////////

using namespace sf;

class World {
public:
	World();
	void draw(RenderWindow& window);
	void update();

	float BorderSize = 40;

	RectangleShape UpBorder;
	RectangleShape DownBorder;
	RectangleShape LeftBorder;
	RectangleShape RightBorder;

	RectangleShape net;

	Font* font;
	Text* score1;
	Text* score2;
	Text* result;

	int n1 = 0;
	int n2 = 0;

	Clock resultClock;
	bool resultVisible = false;
};