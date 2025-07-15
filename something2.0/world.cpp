//Игровой мир, все объекты на карте и сама карта
#include "World.h"

World::World() {
	UpBorder.setSize({ 800,25 });
	UpBorder.setFillColor(Color::White);

	DownBorder.setSize({ 800,25 });
	DownBorder.setPosition({ 0,600-25 });
	DownBorder.setFillColor(Color::White);

	LeftBorder.setSize({ 25,600 });
	LeftBorder.setFillColor(Color::White);

	RightBorder.setSize({ 25,600 });
	RightBorder.setPosition({ 800 - 25,0 });
	RightBorder.setFillColor(Color::White);
	
	net.setSize({ 30,250 });
	net.setPosition({ 800/2-15,600 - 250 });
	net.setFillColor(Color::White);
}

void World::draw(RenderWindow& window) {
	window.draw(UpBorder);
	window.draw(DownBorder);
	window.draw(LeftBorder);
	window.draw(RightBorder);
	window.draw(net);
}
