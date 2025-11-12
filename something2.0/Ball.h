#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "World.h"


using namespace sf;

class Ball {
public:
	Ball(World& world, Player& player1, Player& player2, float X);
	void update(float time);
	void draw(RenderWindow& window);

	RectangleShape ball;

	World& world;
	Player& player1;
	Player& player2;

	void handlePlayerCollision(Player& player);

	Vector2f position;
	Vector2f velocity{ 0.f, 150.f }; //Начальная скорость

	const float gravity = 300.f;
	const float bounceSpeed = 400.f; 
	const float maxBounceAngle = 60.f; 

	bool isActive = true;

};

