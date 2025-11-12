#pragma once
#include <SFML/Graphics.hpp>

////////////////////////////Игровой мир, все объекты на карте и сама карта///////////////////////

using namespace sf;

class World {
public:
	World();
	void draw(RenderWindow& window);

	float BorderSize = 40;

	RectangleShape UpBorder;
	RectangleShape DownBorder;
	RectangleShape LeftBorder;
	RectangleShape RightBorder;

	RectangleShape net;
};