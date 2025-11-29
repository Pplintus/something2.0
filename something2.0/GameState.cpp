#include "GameState.h"
#include "Game.h"
#include <iostream>

//ÃËÀÂÍÎÅ ÌÅÍÞ
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

    settingsButton = new Text(*font);
    settingsButton->setString("SETTINGS");
    settingsButton->setCharacterSize(50);
    settingsButton->setPosition({ 245, 350 });

    exitButton = new Text(*font);
    exitButton->setString("EXIT");
    exitButton->setCharacterSize(50);
    exitButton->setPosition({ 320, 450 });

    stateTimer.restart();
}

MainMenuState::~MainMenuState() {
    delete title;
    delete playButton;
    delete exitButton;
    delete font;
}

void MainMenuState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }

    if (stateTimer.getElapsedTime().asSeconds() > COOLDOWN_TIME) {
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downPressed) {
            selected = (selected + 1) % 3;
            downPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            downPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upPressed) {
            selected = (selected - 1 + 3) % 3;
            upPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            upPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            if (selected == 0) game.setState(new PlayingState());
            else if (selected == 1) game.setState(new SettingsState());
            else if (selected == 2) game.window.close();
        }
    }
    
}

void MainMenuState::update(Game& game, float deltaTime) {
    playButton->setFillColor(selected == 0 ? Color::Red : Color::White);
    settingsButton->setFillColor(selected == 1 ? Color::Red : Color::White);
    exitButton->setFillColor(selected == 2 ? Color::Red : Color::White);
}

void MainMenuState::render(Game& game) {
    game.window.clear();

    game.window.draw(*title);
    game.window.draw(*playButton);
    game.window.draw(*settingsButton);
    game.window.draw(*exitButton);

    game.window.display();
}

//ÍÀÑÒÐÎÉÊÈ
SettingsState::SettingsState() {
    font = new Font();
    font->openFromFile("8bitoperatorregular.ttf");

    title = new Text(*font);
    title->setString("SETTINGS");
    title->setCharacterSize(50);
    title->setPosition({ 265, 80 });

    player1ColorText = new Text(*font);
    player1ColorText->setString("PLAYER 1");
    player1ColorText->setCharacterSize(50);
    player1ColorText->setPosition({ 265, 250 });

    player2ColorText = new Text(*font);
    player2ColorText->setString("PLAYER 2");
    player2ColorText->setCharacterSize(50);
    player2ColorText->setPosition({ 265, 350 });

    stateTimer.restart();
}

SettingsState::~SettingsState() {
    delete title;
    delete player1ColorText;
    delete player2ColorText;
    delete font;
}

void SettingsState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
    if (stateTimer.getElapsedTime().asSeconds() > COOLDOWN_TIME) {

        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downPressed) {
            selected = (selected + 1) % 2;
            downPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            downPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upPressed) {
            selected = (selected - 1 + 2) % 2;
            upPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            upPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))game.setState(new MainMenuState());


        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            if (selected == 0) game.setState(new Settings2State(1));
            else if (selected == 1) game.setState(new Settings2State(2));

        }
    }
}

void SettingsState::update(Game& game, float deltaTime) {
    player1ColorText->setFillColor(selected == 0 ? Color::Red : Color::White);
    player2ColorText->setFillColor(selected == 1 ? Color::Red : Color::White);
}

void SettingsState::render(Game& game) {
    game.window.clear();

    game.window.draw(*title);
    game.window.draw(*player1ColorText);
    game.window.draw(*player2ColorText);

    game.window.display();
}

//ß ùàñ âñêðîþñü
Settings2State::Settings2State(int numPlayer) {
    font = new Font();
    font->openFromFile("8bitoperatorregular.ttf");
    this->numPlayer = numPlayer;

    title = new Text(*font);
    title->setString("SETTINGS");
    title->setCharacterSize(50);
    title->setPosition({ 265, 80 });

    setCustom = new Text(*font);
    setCustom->setString("CHANGE COLOR");
    setCustom->setCharacterSize(50);
    setCustom->setPosition({ 200, 250 });

    setTexture = new Text(*font);
    setTexture->setString("LOAD TEXTURE");
    setTexture->setCharacterSize(50);
    setTexture->setPosition({ 200, 350 });

    stateTimer.restart();
}

Settings2State::~Settings2State() {
    delete title;
    delete setCustom;
    delete setTexture;
    delete font;
}

void Settings2State::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
    if (stateTimer.getElapsedTime().asSeconds() > COOLDOWN_TIME) {

        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downPressed) {
            selected = (selected + 1) % 2;
            downPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            downPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upPressed) {
            selected = (selected - 1 + 2) % 2;
            upPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            upPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))game.setState(new SettingsState());


        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            if (selected == 0) game.setState(new SetColorState(numPlayer));
            else if (selected == 1) {
                Texture t(OpenFileDialog());
                if (numPlayer == 1) {
                    game.player1Texture = t;
                    game.player1.character.setFillColor(Color::White);
                    game.player1.character.setTexture(&game.player1Texture);
                }
                else {
                    game.player2Texture = t;
                    game.player2.character.setFillColor(Color::White);
                    game.player2.character.setTexture(&game.player2Texture);
                }
                game.setState(new SettingsState());
            }

        }
    }
}

void Settings2State::update(Game& game, float deltaTime) {
    setCustom->setFillColor(selected == 0 ? Color::Red : Color::White);
    setTexture->setFillColor(selected == 1 ? Color::Red : Color::White);
}

void Settings2State::render(Game& game) {
    game.window.clear();

    game.window.draw(*title);
    game.window.draw(*setCustom);
    game.window.draw(*setTexture);

    game.window.display();
}

std::string Settings2State::OpenFileDialog() {
    // Èñïîëüçóåì ANSI âåðñèþ ôóíêöèé
    OPENFILENAMEA ofn;  // A-âåðñèÿ äëÿ ANSI
    char szFile[260] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "PNG Files\0*.png\0All Files\0*.*\0";  // Îáû÷íàÿ ANSI ñòðîêà
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameA(&ofn) == TRUE) {  // A-âåðñèÿ ôóíêöèè
        return std::string(szFile);
    }
    return "";
}



//ÂÛÁÎÐ ÖÂÅÒÀ
SetColorState::SetColorState(int numPlayer) {
    this->numPlayer = numPlayer;

    font = new Font();
    font->openFromFile("8bitoperatorregular.ttf");

    Blue = new Text(*font);
    Blue->setString("BLUE");
    Blue->setFillColor(Color::Blue);
    Blue->setCharacterSize(50);
    Blue->setPosition({ 220, 40 });
    colors[0] = Color::Blue;

    Red = new Text(*font);
    Red->setString("RED");
    Red->setFillColor(Color::Red);
    Red->setCharacterSize(50);
    Red->setPosition({ 220, 130 });
    colors[1] = Color::Red;

    Green = new Text(*font);
    Green->setString("GREEN");
    Green->setFillColor(Color::Green);
    Green->setCharacterSize(50);
    Green->setPosition({ 220, 220 });
    colors[2] = Color::Green;

    Yellow = new Text(*font);
    Yellow->setString("YELLOW");
    Yellow->setFillColor(Color::Yellow);
    Yellow->setCharacterSize(50);
    Yellow->setPosition({ 220, 310 });
    colors[3] = Color::Yellow;

    Magneta = new Text(*font);
    Magneta->setString("MAGNETA");
    Magneta->setFillColor(Color::Magenta);
    Magneta->setCharacterSize(50);
    Magneta->setPosition({ 220, 400 });
    colors[4] = Color::Magenta;

    Cyan = new Text(*font);
    Cyan->setString("CYAN");
    Cyan->setFillColor(Color::Cyan);
    Cyan->setCharacterSize(50);
    Cyan->setPosition({ 220, 490 });
    colors[5] = Color::Cyan;

    stateTimer.restart();
}

SetColorState::~SetColorState() {
    delete Blue;
    delete Red;
    delete Green;
    delete Yellow;
    delete Magneta;
    delete Cyan;
    delete font;
}

void SetColorState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
    if (stateTimer.getElapsedTime().asSeconds() > COOLDOWN_TIME) {
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downPressed) {
            selected = (selected + 1) % 6;
            downPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            downPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upPressed) {
            selected = (selected - 1 + 6) % 6;
            upPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            upPressed = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) game.setState(new SettingsState);

        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            if (numPlayer == 1) {
                game.player1.character.setFillColor(colors[selected]);
                game.setState(new SettingsState);
            }

            if (numPlayer == 2) {
                game.player2.character.setFillColor(colors[selected]);
                game.setState(new SettingsState);
            }
        }
    }

}

void SetColorState::update(Game& game, float deltaTime) {
    Blue->setOutlineColor(selected == 0 ? Color::White : Color::Black);
    Blue->setOutlineThickness(selected == 0 ? 2.f : 0.f);
    Red->setOutlineColor(selected == 1 ? Color::White : Color::Black);
    Red->setOutlineThickness(selected == 1 ? 2.f : 0.f);
    Green->setOutlineColor(selected == 2 ? Color::White : Color::Black);
    Green->setOutlineThickness(selected == 2 ? 2.f : 0.f);
    Yellow->setOutlineColor(selected == 3 ? Color::White : Color::Black);
    Yellow->setOutlineThickness(selected == 3 ? 2.f : 0.f);
    Magneta->setOutlineColor(selected == 4 ? Color::White : Color::Black);
    Magneta->setOutlineThickness(selected == 4 ? 2.f : 0.f);
    Cyan->setOutlineColor(selected == 5 ? Color::White : Color::Black);
    Cyan->setOutlineThickness(selected == 5 ? 2.f : 0.f);
}

void SetColorState::render(Game& game) {
    game.window.clear();

    game.window.draw(*Blue);
    game.window.draw(*Red);
    game.window.draw(*Green);
    game.window.draw(*Yellow);
    game.window.draw(*Magneta);
    game.window.draw(*Cyan);

    game.window.display();
}

//ÏÀÓÇÀ
PauseState::PauseState() {
    font = new Font();
    font->openFromFile("8bitoperatorregular.ttf");

    pause = new Text(*font);
    pause->setString("PAUSE");
    pause->setCharacterSize(50);
    pause->setPosition({ 300, 80 });

    gameContinue = new Text(*font);
    gameContinue->setString("CONTINUE");
    gameContinue->setCharacterSize(50);
    gameContinue->setPosition({ 255, 250 });

    mainMenu = new Text(*font);
    mainMenu->setString("MAIN MENU");
    mainMenu->setCharacterSize(50);
    mainMenu->setPosition({ 230, 350 });

    exitGame = new Text(*font);
    exitGame->setString("EXIT");
    exitGame->setCharacterSize(50);
    exitGame->setPosition({ 320, 450 });

    stateTimer.restart();
}

PauseState::~PauseState() {
    delete exitGame;
    delete gameContinue;
    delete mainMenu;
    delete font;
}

void PauseState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
    if (stateTimer.getElapsedTime().asSeconds() > COOLDOWN_TIME) {
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downPressed) {
            selected = (selected + 1) % 3;
            downPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            downPressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upPressed) {
            selected = (selected - 1 + 3) % 3;
            upPressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            upPressed = false;
        }


        if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
            if (selected == 0) game.setState(new PlayingState());
            else if (selected == 1) {
                game.setState(new MainMenuState());
                game.restart();
            }
            else if (selected == 2) game.window.close();

        }
    }
}

void PauseState::update(Game& game, float dt) {
    gameContinue->setFillColor(selected == 0 ? Color::Red : Color::White);
    mainMenu->setFillColor(selected == 1 ? Color::Red : Color::White);
    exitGame->setFillColor(selected == 2 ? Color::Red : Color::White);
}

void PauseState::render(Game& game) {
    game.window.clear();

    game.window.draw(*pause);
    game.window.draw(*gameContinue);
    game.window.draw(*mainMenu);
    game.window.draw(*exitGame);

    game.window.display();
}

//ÑÀÌÀ ÈÃÐÀ
void PlayingState::handleInput(Game& game) {
    while (const std::optional event = game.window.pollEvent()) {
        if (event->is<Event::Closed>())
            game.window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) game.setState(new PauseState);
}

void PlayingState::update(Game& game, float dt) {
    game.player1.move(dt, Keyboard::Key::A, Keyboard::Key::D, Keyboard::Key::W);
    game.player2.move(dt, Keyboard::Key::Left, Keyboard::Key::Right, Keyboard::Key::Up);

    game.ball.update(dt);
    game.world.update();
}

void PlayingState::render(Game& game) {
    game.window.clear();

    game.world.draw(game.window);
    game.player1.draw(game.window);
    game.player2.draw(game.window);
    game.ball.draw(game.window);

    game.window.display();
}

