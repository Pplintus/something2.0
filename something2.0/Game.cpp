#include "Game.h"

Game::Game() {
    window.create(VideoMode({800,600}), "Something");
    window.setFramerateLimit(60);
}


void Game::run() {
    Clock clock;
    while (window.isOpen()) {

        float time = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()){

            if (event->is<Event::Closed>())
                window.close();
        }

        update(time);
        render();
    }
}

void Game::update(float time) {
    player1.move(time, Keyboard::Key::A, Keyboard::Key::D, Keyboard::Key::W/*, Keyboard::Key::W, Keyboard::Key::S*/);
    player2.move(time, Keyboard::Key::Left, Keyboard::Key::Right, Keyboard::Key::Up/*, Keyboard::Key::Up, Keyboard::Key::Down*/);
}

void Game::render() {
    window.clear();
    world.draw(window);
    player1.draw(window);
    player2.draw(window);
    window.display();
}