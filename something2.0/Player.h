#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
public:
	Player();

	void move(float time);
	void draw(RenderWindow& window);
	void update(float time);

private:
	CircleShape character;
	float speed = 50.f;
};

class HumanObject {
public:
	HumanObject();
	void setSize(int height, int wight);
	void setPozition(int x, int y);
	void setColor(std::string color); //пока не придумала как запихнуть туда все цвета, будет только 3
	void move(int x, int y);

};