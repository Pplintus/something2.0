#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World.h"
using namespace sf;

class Game {
public:

	Game();
	void run();
	
private:

	void render();
	void update(float time);

	RenderWindow window;

	Player player1{Color::Blue, 800 / 4 - 60 };
	Player player2{ Color::Red, 800*3 / 4 - 60 };

	World world;
	Clock clock;
};