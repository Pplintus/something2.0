#include "World.h"

World::World()
{
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

	font = new Font();
	font->openFromFile("8bitoperatorregular.ttf");
	score1 = new Text(*font);
	score2 = new Text(*font);
	score1->setString(std::to_string(n1));
	score2->setString(std::to_string(n2));
	score1->setCharacterSize(80);
	score2->setCharacterSize(80);
	score1->setPosition({ 60, 60 });
	score2->setPosition({ 800 - 40 - 80, 60 });
	score1->setFillColor(Color::White);
	score2->setFillColor(Color::White);

	result = new Text(*font);
	result->setString("");
	result->setCharacterSize(50);
	result->setPosition({ 170, 60 });
	result->setFillColor(Color::White);

}

void World::draw(RenderWindow& window) {
	window.draw(UpBorder);
	window.draw(DownBorder);
	window.draw(LeftBorder);
	window.draw(RightBorder);
	window.draw(net);
	window.draw(*score1);
	window.draw(*score2);
	if (resultVisible)
		window.draw(*result);
}


void World::update() {
	score1->setString(std::to_string(n1));
	score2->setString(std::to_string(n2));

	if (!resultVisible && (n1 == 5 || n2 == 5))
	{
		if (n1 > n2) result->setString("Player 1 Wins!");
		else result->setString("Player 2 Wins!");

		resultVisible = true;
		resultClock.restart(); 
	}

	if (resultVisible && resultClock.getElapsedTime().asSeconds() >= 2.f)
	{
		resultVisible = false;
		result->setString("");
		n1 = 0;
		n2 = 0;
		score1->setString("0");
		score2->setString("0");
	}
}