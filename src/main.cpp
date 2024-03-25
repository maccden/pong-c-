#include "../include/ball.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FONT_SIZE 40
#define SCORE_TEXT_MARGIN_Y 20

typedef enum GameScreen
{
    PAUSE_SCREEN,
    GAME_SCREEN
} GameScreen;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong!");
    SetTargetFPS(60);
    InitAudioDevice();

    GameScreen currentGameScreen = GAME_SCREEN;
    Player playerOne({25, SCREEN_HEIGHT / 2 - PLAYER_SIZE.y / 2}),
        playerTwo({SCREEN_WIDTH - 35, SCREEN_HEIGHT / 2 - PLAYER_SIZE.y / 2});
    Ball ball;

    while (!WindowShouldClose())
    {
        // update de los variables de cada menu
        switch (currentGameScreen)
        {
        case PAUSE_SCREEN:
        {
            if (IsKeyPressed(KEY_P))
                currentGameScreen = GAME_SCREEN;
            break;
        }
        case GAME_SCREEN:
        {
            if (IsKeyPressed(KEY_P))
                currentGameScreen = PAUSE_SCREEN;
            break;
        }
        default:
            break;
        }

        // movimientos
        playerOne.moveUp(KEY_W);
        playerOne.moveDown(KEY_S);
        playerTwo.moveUp(KEY_I);
        playerTwo.moveDown(KEY_K);

        // boundary
        playerOne.setPlayerBoundary();
        playerTwo.setPlayerBoundary();

        BeginDrawing();
        {
            // cambio de menus
            switch (currentGameScreen)
            {
            case PAUSE_SCREEN:
            {
                ClearBackground(BLACK);
                DrawText("PAUSE", SCREEN_WIDTH / 2 - MeasureText("PAUSE", FONT_SIZE) / 2, SCREEN_HEIGHT / 2 - FONT_SIZE / 2, FONT_SIZE, WHITE);
                break;
            }
            case GAME_SCREEN:
            {
                ClearBackground(BLACK);
                DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, GRAY);
                ball.updateBallFrame(playerOne, playerTwo);
                ball.drawBall();
                playerOne.drawPlayer();
                playerTwo.drawPlayer();
                DrawText(TextFormat("%i", playerOne.getPlayerScore()), SCREEN_WIDTH / 4 - MeasureText(TextFormat("%i", playerOne.getPlayerScore()), FONT_SIZE) / 2, SCORE_TEXT_MARGIN_Y, FONT_SIZE, GRAY);
                DrawText(TextFormat("%i", playerTwo.getPlayerScore()), SCREEN_WIDTH / 1.3 - MeasureText(TextFormat("%i", playerTwo.getPlayerScore()), FONT_SIZE) / 2, SCORE_TEXT_MARGIN_Y, FONT_SIZE, GRAY);
                break;
            }
            default:
                break;
            }
        }
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}