#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <windows.h>
#include <commdlg.h>
#include <string>
#include "Player.h"
#pragma comment(lib, "comdlg32.lib")
using namespace sf;

class Game;

///////////////////////////////Ã≈Õﬁÿ ¿???///////////////////////////////

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput(Game& game) = 0;
    virtual void update(Game& game, float deltaTime) = 0;
    virtual void render(Game& game) = 0;
};

class MainMenuState : public GameState {
private:
    Clock stateTimer;
    float COOLDOWN_TIME = 0.2f;
    bool upPressed = false;
    bool downPressed = false;
    Font* font;
    Text* title;
    Text* playButton;
    Text* settingsButton;
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

class PauseState : public GameState {
private:
    Clock stateTimer;
    float COOLDOWN_TIME = 0.2f;
    bool upPressed = false;
    bool downPressed = false;
    Font* font;
    Text* pause;
    Text* gameContinue;
    Text* mainMenu;
    Text* exitGame;
    int selected = 0;
public:
    PauseState();
    ~PauseState();
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;
};

class SettingsState : public GameState {
private:
    Clock stateTimer;
    float COOLDOWN_TIME = 0.2f;
    bool upPressed = false;
    bool downPressed = false;
    Font* font;
    Text* title;
    Text* player1ColorText;
    Text* player2ColorText;
    int selected = 0;

public:
    SettingsState();
    ~SettingsState();
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;

};

class Settings2State : public GameState {
private:
    Clock stateTimer;
    float COOLDOWN_TIME = 0.2f;
    bool upPressed = false;
    bool downPressed = false;
    Font* font;
    Text* title;
    Text* setCustom;
    Text* setTexture;
    int selected = 0;
    int numPlayer;
    std::string OpenFileDialog();

public:
    Settings2State(int numPlayer);
    ~Settings2State();
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;

    
};

class SetColorState : public GameState {
private:
    Clock stateTimer;
    float COOLDOWN_TIME = 0.2f;
    bool upPressed = false;
    bool downPressed = false;
    Font* font;
    Text* Blue;
    Text* Red;
    Text* Green;
    Text* Yellow;
    Text* Magneta;
    Text* Cyan;
    int selected = 0;
    int numPlayer;

    std::map<int, Color> colors;


public:
    SetColorState(int numPlayer); //1 - 1? ?????, 2 - 2? ?????
    ~SetColorState();
    void handleInput(Game& game) override;
    void update(Game& game, float deltaTime) override;
    void render(Game& game) override;
};
