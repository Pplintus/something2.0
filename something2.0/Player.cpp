#include "Player.h"
#include "stdarg.h"

Player::Player(World& world, Color color, float X) : world{ world }, groundLevel{ 600 - world.BorderSize - 160 }
{
	character.setSize({ 120, 160 });//РАЗМЕРЫ
	character.setFillColor(color);
	character.setPosition({ X,  600 - world.BorderSize - 160 });
	Y_position = groundLevel;
}

void Player::move(float time, ...) {
	va_list keys;
	va_start(keys, time);

	//шифт, который уже не нужен
	/*if (Keyboard::isKeyPressed(Keyboard::Key::LShift)) { speed = 150.f; }
	else { speed = 50.f; }*/

	//тут куча проверок на коллизии со стенками
	if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key)) && (character.getPosition().x - speed * time > 800 / 2 + 20 ||
		(800 / 2 - 20 > character.getPosition().x - speed * time && character.getPosition().x - speed * time > world.BorderSize) ) ) {
		character.move({ -speed * time, 0 }); 
	}
	if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key)) && (character.getPosition().x + speed*time < 800 / 2 - 20 - 120 || 
		(800 / 2 + 20 < character.getPosition().x + speed * time && character.getPosition().x + speed * time < 800 - world.BorderSize - 120) ) ) {

		character.move({speed*time, 0 });
	}

	//тоже не надо, но удалять не буду
	//if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key))) { character.move({ 0, -speed*time }); }
	//if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key))) { character.move({ 0, speed*time }); }

	//прыжок
	if (Keyboard::isKeyPressed(va_arg(keys, Keyboard::Key)) && !isJumping && Y_position >= groundLevel - 1.f) { 
		isJumping = true;
		jumpSpeed = startJumpSpeed;
	}

	if (isJumping) {
		jumpSpeed += gravity * time;
		Y_position += jumpSpeed * time;
		character.setPosition({ character.getPosition().x, Y_position });

		if (Y_position >= groundLevel) {
			Y_position = groundLevel;
			character.setPosition({ character.getPosition().x, Y_position });
			isJumping = false;
		}
	}

	va_end(keys);
}

void Player::draw(RenderWindow& window) {
	window.draw(character);
}

//HumanObject::HumanObject() {
//
//}