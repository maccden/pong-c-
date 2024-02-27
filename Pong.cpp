#include "include/Player.hpp"
#include "include/Ball.hpp"

typedef enum GameScreen
{
    PAUSA = 0,
    GAME
} GameScreen;

int main(int argc, char const *argv[])
{
    const int SCREEN_W = 800, SCREEN_H = 600, FONT_SIZE_1 = 40, FONT_SIZE_2 = 20, TEXT_MARGIN_Y = 20;

    InitWindow(SCREEN_W, SCREEN_H, "Pong!");
    SetTargetFPS(60);
    InitAudioDevice();

    GameScreen currentScreen = GAME;
    Player p1({25, SCREEN_H / 2 - Player::getPlayerSize().y / 2}),
        p2({(float)SCREEN_W - 35, SCREEN_H / 2 - Player::getPlayerSize().y / 2});
    Ball ball;

    while (!WindowShouldClose())
    {
        // update de los variables de cada menu
        switch (currentScreen)
        {
        case PAUSA:
        {
            if (IsKeyPressed(KEY_P))
                currentScreen = GAME;
            break;
        }
        case GAME:
        {
            if (IsKeyPressed(KEY_P))
                currentScreen = PAUSA;
            break;
        }
        default:
            break;
        }

        // movimientos
        p1.up(KEY_W);
        p1.down(KEY_S);
        p2.up(KEY_I);
        p2.down(KEY_K);

        // boundary
        p1.setBoundary();
        p2.setBoundary();

        BeginDrawing();
        {
            // cambio de menus
            switch (currentScreen)
            {
            case PAUSA:
            {
                ClearBackground(BLACK);
                DrawText("PAUSA", SCREEN_W / 2 - MeasureText("PAUSA", FONT_SIZE_1) / 2, SCREEN_H / 2 - FONT_SIZE_1 / 2, FONT_SIZE_1, WHITE);
                break;
            }
            case GAME:
            {
                ClearBackground(BLACK);
                DrawLine(SCREEN_W / 2, 0, SCREEN_W / 2, SCREEN_H, GRAY);
                p1.drawPlayer();
                p2.drawPlayer();
                ball.drawBall();
                ball.updateBall(p1, p2);
                DrawText(TextFormat("%i", p1.getScore()), SCREEN_W / 4 - MeasureText(TextFormat("%i", p1.getScore()), FONT_SIZE_1) / 2, TEXT_MARGIN_Y, FONT_SIZE_1, GRAY);
                DrawText(TextFormat("%i", p2.getScore()), SCREEN_W / 1.3 - MeasureText(TextFormat("%i", p2.getScore()), FONT_SIZE_1) / 2, TEXT_MARGIN_Y, FONT_SIZE_1, GRAY);
                DrawText("Player 1: 'W' Up, 'S' Down, Player 2: 'I' Up, 'K' Down.", 10, SCREEN_H - TEXT_MARGIN_Y, FONT_SIZE_2, GRAY);
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