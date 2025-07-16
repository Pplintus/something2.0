#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
public:
	Player(Color color, float X);

	void move(float time, ...);
	void draw(RenderWindow& window);

private:
	RectangleShape character;
	/*float Y_pozition;
	bool Up = false;
	bool Down = false;
	float speed = 100.f;*/
	float Y_position;
	bool isJumping = false;
	float jumpSpeed = 0.f;
	const float gravity = 500.f;
	const float startJumpSpeed = -400.f;
	const float groundLevel = 600 - 25 - 160; // Уровень земли
	float speed = 100.f;
};

//class HumanObject {
//public:
//	HumanObject();
//	void setSize(int height, int wight);
//	void setPozition(int x, int y);
//	void setColor(Color color);
//	void move(int x, int y);
//
//};