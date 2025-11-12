#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

////////////////////////////////////////ИГРОК/////////////////////////////////////

using namespace sf;

class Player {
public:
	Player(World& world, Color color, float X );

	void move(float time, ...);
	void draw(RenderWindow& window);

	RectangleShape character;
	float speed = 200.f;
	bool isJumping = false;

	World& world;
	float Y_position;
	float jumpSpeed = 0.f;
	const float gravity = 500.f;
	const float startJumpSpeed = -400.f;
	const float groundLevel;
	
	int score = 0;
};

//доделаю потом, класс для нормального вида игрока
//class HumanObject {
//public:
//	HumanObject();
//	void setSize(int height, int wight);
//	void setPozition(int x, int y);
//	void setColor(Color color);
//	void move(int x, int y);
//
//};