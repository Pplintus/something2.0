#include "Game.h"
using namespace sf;

Game::Game() {
    window.create(VideoMode({ 800, 600 }), "Something");
}


void Game::runGame() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }
        render();
    }
}


void Game::render() {
    window.clear();
    window.display();
}