#include "GameState.h"
#include "Game.h"
#include <iostream>


MainMenuState::MainMenuState() {
    font = new Font();
    font->openFromFile("8bitoperatorregular.ttf");

    title = new Text(*font);
    title->setString("VOLLEYBALL");
    title->setCharacterSize(50);
    title->setPosition({ 220, 80 });

    playButton = new Text(*font);
    playButton->setString("PLAY");
    playButton->setCharacterSize(50);
    playButton->setPosition({ 320, 250 });

    exitButton = new Text(*font);
    exitButton->setString("EXIT");
    exitButton->setCharacterSize(50);
    exitButton->setPosition({ 320, 350 });
}

MainMenuState::~MainMenuState() {
    delete title;
    delete playButton;
    delete exitButton;
    delete font;
}

void MainMenuState::handleInput(Game& game) {
    if (Keyboard::isKeyPressed(Keyboard::Key::Down))
        selected = 1;

    if (Keyboard::isKeyPressed(Keyboard::Key::Up))
        selected = 0;

    if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
        if (selected == 0) {
            game.setState(new PlayingState());
        }
        else if (selected == 1) {
            game.window.close();
        }
    }
}

void MainMenuState::update(Game& game, float deltaTime) {
    playButton->setFillColor(selected == 0 ? Color::Red : Color::White);
    exitButton->setFillColor(selected == 1 ? Color::Red : Color::White);
}

void MainMenuState::render(Game& game) {
    game.window.clear();

    game.window.draw(*title);
    game.window.draw(*playButton);
    game.window.draw(*exitButton);

    game.window.display();
}

// ------------------------- PLAYING STATE -------------------------

void PlayingState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
}

void PlayingState::update(Game& game, float dt) {
    game.player1.move(dt, Keyboard::Key::A, Keyboard::Key::D, Keyboard::Key::W);
    game.player2.move(dt, Keyboard::Key::Left, Keyboard::Key::Right, Keyboard::Key::Up);

    game.ball.update(dt);
    game.world.update();

    if (game.world.n1 == 5 || game.world.n2 == 5) {
        // Здесь позже подключим GameOverState
    }
}

void PlayingState::render(Game& game) {
    game.window.clear();

    game.world.draw(game.window);
    game.player1.draw(game.window);
    game.player2.draw(game.window);
    game.ball.draw(game.window);

    game.window.display();
}
