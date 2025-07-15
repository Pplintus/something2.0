#include "Game.h"

Game::Game() {
    window.create(VideoMode({800,600}), "Something");
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
    player.update(time);
}

void Game::render() {
    window.clear();
    world.draw(window);
    player.draw(window);
    window.display();
}