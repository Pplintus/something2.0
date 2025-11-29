#include "Game.h"

Game::Game() 
{
    window.create(VideoMode({800,600}), "Something");
    window.setFramerateLimit(120);

    setState(new MainMenuState());
}

void Game::setState(GameState* newState) {
    if (state)
        delete state;
    state = newState;
}

void Game::run() {
    Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        state->handleInput(*this);
        state->update(*this, dt);
        state->render(*this);
    }
}



void Game::restart() {
    world.n1 = 0;
    world.n2 = 0;
    player1.character.setPosition({ 800 / 4 - 60, 600 - world.BorderSize - 160 });
    player1.Y_position = player1.groundLevel;
    player1.isJumping = false;
    player2.character.setPosition({ 800 * 3 / 4 - 60, 600 - world.BorderSize - 160 });
    player2.Y_position = player2.groundLevel;
    player2.isJumping = false;
    ball.ballRestart();
}