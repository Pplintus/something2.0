#include "Game.h"

Game::Game() {
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

void Game::update(float time) {
    player1.move(time, Keyboard::Key::A, Keyboard::Key::D, Keyboard::Key::W);
    player2.move(time, Keyboard::Key::Left, Keyboard::Key::Right, Keyboard::Key::Up);
    ball.update(time);
    world.update();
}

void Game::pre_render() {
    RectangleShape st_rectangle({ 250.f,150.f });
    st_rectangle.setFillColor(Color::White);
    st_rectangle.setPosition({ 800 / 2 - 125,600 / 2 - 75 });
    window.clear();
    window.draw(st_rectangle);
    window.display();
}

void Game::render() {
    window.clear();
    world.draw(window);
    player1.draw(window);
    player2.draw(window);
    ball.draw(window);
    window.display();
}


