#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class World {
public:
	World();
	void draw(RenderWindow& window);

private:
	RectangleShape UpBorder;
	RectangleShape DownBorder;
	RectangleShape LeftBorder;
	RectangleShape RightBorder;

	RectangleShape net;
};