#include "Player.h"
#include "stdarg.h"

Player::Player(Color color, float X) {
	character.setSize({ 120, 160 });
	character.setFillColor(color);
	character.setPosition({ X,  600 - 25 - 160 });
	Y_position = groundLevel;
}

void Player::move(float time, ...) {
	va_list keys;
	va_start(keys, time);
	/*if (Keyboard::isKeyPressed(Keyboard::Key::LShift)) { speed = 150.f; }
	else { speed = 50.f; }*/

	if (Keyboard::isKeyPressed(va_arg(keys,Keyboard::Key))) { character.move({ -speed*time, 0 }); }
	if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key))) { character.move({speed*time, 0 });}
	//if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key))) { character.move({ 0, -speed*time }); }
	//if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key))) { character.move({ 0, speed*time }); }
	

	if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key)) && !isJumping && Y_position >= groundLevel - 1.f) { 
		isJumping = true;
		jumpSpeed = startJumpSpeed;
	}

	if (isJumping) {
		jumpSpeed += gravity * time;
		Y_position += jumpSpeed * time;
		character.setPosition({ character.getPosition().x, Y_position });

		// ѕроверка приземлени€
		if (Y_position >= groundLevel) {
			Y_position = groundLevel;
			character.setPosition({ character.getPosition().x, Y_position });
			isJumping = false;
		}
	}
	//когда нибудь € это исправлю
	/*while(Up) {
		Y_pozition = Y_pozition - 50;
		character.move({ 0, -speed * time });
		if (Y_pozition <= 600 - 25 - 240) {
			Up = false;
			Down = true;
		}
	}
	while (Down) {
		Y_pozition = Y_pozition + 50;
		character.move({ 0, speed * time });
		if (Y_pozition == 600 - 25 - 160) { Down = false; }
	}*/
	va_end(keys);
}

void Player::draw(RenderWindow& window) {
	window.draw(character);
}

//HumanObject::HumanObject() {
//
//}