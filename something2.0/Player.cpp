#include "Player.h"


Player::Player() {
	character.setRadius(20.f);
	character.setFillColor(Color::White);
	character.setPosition({ 30.f, 30.f });
}

void Player::move(float time) {

	if (Keyboard::isKeyPressed(Keyboard::Key::LShift)) { speed = 150.f; }
	else { speed = 50.f; }

	if (Keyboard::isKeyPressed(Keyboard::Key::A)) { character.move({ -speed*time, 0 }); }
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) { character.move({speed*time, 0 });}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) { character.move({ 0, -speed*time }); }
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) { character.move({ 0, speed*time }); }
}

void Player::draw(RenderWindow& window) {
	window.draw(character);
}

void Player::update(float time) {
	
	move(time);
}