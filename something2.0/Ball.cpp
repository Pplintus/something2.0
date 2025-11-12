#include "Ball.h"

//РАЗМЕРЫ ИГРОКА 120х160

Ball::Ball(World& world, Player& player1, Player& player2, float X) : world{ world }, player1{ player1 }, player2{ player2 }
{
    ball.setSize({ 40,40 });
    ball.setFillColor(Color::White);
    ball.setPosition({ X,600 / 2 - 120 });
    position = Vector2f(X, 600 / 2 - 120);

}

void Ball::update(float time) {
    velocity.y += gravity * time;

    position += velocity * time;
    ball.setPosition(position);

    //столкновение с игроком 1
    if (ball.getGlobalBounds().findIntersection(player1.character.getGlobalBounds())) {
        handlePlayerCollision(player1);
    }

    //столкновение с игроком 2
    if (ball.getGlobalBounds().findIntersection(player2.character.getGlobalBounds())) {
        handlePlayerCollision(player2);
    }

    //удар о стенки ось Х
    if (ball.getGlobalBounds().findIntersection(world.RightBorder.getGlobalBounds()) || 
        ball.getGlobalBounds().findIntersection(world.LeftBorder.getGlobalBounds()) ) {
        velocity.x = -velocity.x;
    }
    //
    if (ball.getGlobalBounds().findIntersection(world.UpBorder.getGlobalBounds())) {
        velocity.y = bounceSpeed*0.5f;
    }

    if (ball.getGlobalBounds().findIntersection(world.DownBorder.getGlobalBounds())) {
        velocity.y = -bounceSpeed*0.5f;
    }

    if (ball.getGlobalBounds().findIntersection(world.net.getGlobalBounds())) {
        if (ball.getPosition().y+30 >= world.net.getPosition().y ) {
            velocity.x = -velocity.x;
        }
        if (ball.getPosition().y+30 <= world.net.getPosition().y) {
            velocity.y = -velocity.y;
        }
    }

}

//переделаю потом
void Ball::handlePlayerCollision(Player& player) {
    float playerCenterX = player.character.getPosition().x + player.character.getSize().x / 2;
    float hitPosition = (position.x + 20) - playerCenterX; 
    float normalizedHit = hitPosition / (player.character.getSize().x / 2);

    float bounceAngle = normalizedHit * maxBounceAngle;
    float angleRad = bounceAngle * 3.14159f / 180.f;

    velocity.x = bounceSpeed * sin(angleRad);
    velocity.y = -bounceSpeed * cos(angleRad);

    if (player.isJumping) {
        velocity.x += player.jumpSpeed * 0.5f;
    }
}

void Ball::draw(RenderWindow& window) {
    window.draw(ball);
}
