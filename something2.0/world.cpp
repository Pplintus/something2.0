#include "World.h"

World::World() {
	UpBorder.setSize({ 800,BorderSize });
	UpBorder.setFillColor(Color::White);

	DownBorder.setSize({ 800,BorderSize });
	DownBorder.setPosition({ 0,600 - BorderSize });
	DownBorder.setFillColor(Color::White);

	LeftBorder.setSize({ BorderSize, 600 });
	LeftBorder.setFillColor(Color::White);

	RightBorder.setSize({ BorderSize,600 });
	RightBorder.setPosition({ 800 - BorderSize,0 });
	RightBorder.setFillColor(Color::White);
	
	net.setSize({ 40,300 });
	net.setPosition({ 800/2-20,600 - 300 });
	net.setFillColor(Color::White);
}

void World::draw(RenderWindow& window) {
	window.draw(UpBorder);
	window.draw(DownBorder);
	window.draw(LeftBorder);
	window.draw(RightBorder);
	window.draw(net);
}
