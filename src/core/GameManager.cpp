#include "GameManager.h"

#include <string>
#include <vector>

#include "raylib.h"

#include "utils/GameUtils.h"
#include "screens/MainMenuScreen.h";
#include "screens/CreditScreen.h"
#include "screens/GameplayScreen.h"

#pragma region GLOBAL VARIABLES

int screenWidth = 1024;
int screenHeight = 720;

const char gameIconUrl[] = "";

Image gameIcon;

static GameState gameState = GameState::MainMenu;

#pragma endregion

#pragma region SCREENS

MainMenuScreen* mainMenuScreen;
CreditScreen* creditScreen;
GameplayScreen* gameplayScreen;

#pragma endregion


// Initialize game variables
static void InitGame()
{
    InitAudioDevice();

    mainMenuScreen = new MainMenuScreen();
    creditScreen = new CreditScreen();
    gameplayScreen = new GameplayScreen();

    //HideCursor();
}

// Update game (one frame)
static void UpdateGame()
{
    switch (gameState)
    {
    case GameState::MainMenu:
        mainMenuScreen->update(gameState);
        break;
    case GameState::Gameplay:
        gameplayScreen->update(gameState);
        break;
    case GameState::Tutorial:
        break;
    case GameState::Credits:
        creditScreen->update(gameState);
        break;
    }
}

// Draw game (one frame)
static void DrawGame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    // Hacer toda la la logica del juego

    switch (gameState)
    {
    case GameState::MainMenu:
        mainMenuScreen->draw();
        break;
    case GameState::Gameplay:
        gameplayScreen->draw();
        break;
    case GameState::Tutorial:
        break;
    case GameState::Credits:
        creditScreen->draw();
        break;
    }

    EndDrawing();
}

// Update and Draw (one frame)
static void UpdateDrawGameFrame()
{
    UpdateGame();
    DrawGame();
}

// Unload game variables
static void UnloadGame()
{
    delete mainMenuScreen;
    delete creditScreen;

    CloseAudioDevice();
}

void Run()
{

    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Flappy Bird xD");
    gameIcon = LoadImage(gameIconUrl);
    SetWindowIcon(gameIcon);

    InitGame();

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose() && gameState != GameState::Quit)    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawGameFrame();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}
