#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game;

///////////////////////////////Менюшка///////////////////////////////

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput(Game& game) = 0;
    virtual void update(Game& game, float deltaTime) = 0;
    virtual void render(Game& game) = 0;
};

enum class StateType {
    MAIN_MENU,
    PLAYING,
    GAME_OVER
};

class MainMenuState : public GameState {
private:
    Font* font;
    Text* title;
    Text* playButton;
    Text* exitButton;

    int selected = 0;

public:
    MainMenuState();
    ~MainMenuState();
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;
};

class PlayingState : public GameState {
public:
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;
};
