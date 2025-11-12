#include "Game.h"

Game::Game() {
    window.create(VideoMode({800,600}), "Something");
    window.setFramerateLimit(60);
}


void Game::run() {
    Clock clock;
    float st = true;
    while (window.isOpen()) {

        float time = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent()){

            if (event->is<Event::Closed>())
                window.close();
        }
        

        //if (Mouse::isButtonPressed(Mouse::Button::Left) /*&& Mouse::getPosition().x >= 800 / 2 - 125 && Mouse::getPosition().y <= 600 / 2 - 75*/) { st = true; }
        

        if(st){
            render();
            update(time); 
        }
        else { pre_render(); }
        
    }
}

void Game::update(float time) {
    player1.move(time, Keyboard::Key::A, Keyboard::Key::D, Keyboard::Key::W/*, Keyboard::Key::W, Keyboard::Key::S*/);
    player2.move(time, Keyboard::Key::Left, Keyboard::Key::Right, Keyboard::Key::Up/*, Keyboard::Key::Up, Keyboard::Key::Down*/);
    ball.update(time);
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

void Game::stwindow() {

}
