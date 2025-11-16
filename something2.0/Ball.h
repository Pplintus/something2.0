#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World.h"
#include <random>
#include <ctime>

////////////////////////////ћ€чик делает бам бам бам///////////////////////

using namespace sf;

class Ball {
private:
	int r() {
		srand(time(NULL));
		int n = rand() % 2;
		if (n == 0) return -1;
		else return 1;
	}

	Vector2f position;
	Vector2f velocity_start{ 200.f * r(), 150.f };
	Vector2f velocity = velocity_start;

	const float gravity = 300.f;
	const float bounceSpeed = 400.f;
	const float maxBounceAngle = 60.f;

	void handlePlayerCollision(Player& player);

public:
	Ball(World& world, Player& player1, Player& player2);
	void update(float time);
	void draw(RenderWindow& window);

	RectangleShape ball;

	World& world;
	Player& player1;
	Player& player2;

	bool isActive = true;

};

