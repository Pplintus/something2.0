#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World.h"
#include "Ball.h"
#include "GameState.h"

//////////////////////////////////ябъгэ бяеу назейрнб////////////////////////

using namespace sf;

class Game {
public:

	Game();
	void run();

	void pre_render();
	void render();
	void update(float time);
	void restart();

	RenderWindow window;
	
	World world;
	Clock clock;

	bool player1hasTexture = false;
	bool player2hasTexture = false;
	Texture player1Texture;
	Texture player2Texture;
	Player player1{world, Color::Blue, 800 / 4 - 60 };
	Player player2{world, Color::Red, 800 * 3 / 4 - 60 };

	Ball ball{world, player1, player2};

	GameState* state;
	void setState(GameState* newState);

};

