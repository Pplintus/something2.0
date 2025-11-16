#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

////////////////////////////////////////»√–Œ /////////////////////////////////////

using namespace sf;

class Player {
public:
	Player(World& world, Color color, float X );

	void move(float time, ...);
	void draw(RenderWindow& window);


	RectangleShape character;
	float speed = 100.f;
	bool isJumping = false;

	World& world;
	float Y_position;
	float jumpSpeed = 0.f;
	const float gravity = 500.f;
	const float startJumpSpeed = -400.f;
	const float groundLevel;
	
	int score = 0;
};

