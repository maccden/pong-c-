#pragma once

#include "raylib.h"
#include "../include/player.hpp"

class Ball
{
    const static int RADIUS;
    const static float INCREMENT;
    const static Vector2 DEFAULT_SPEED;
    const Sound PLAYER = LoadSound("assets/sound/player.ogg"),
                WALL = LoadSound("assets/sound/wall.ogg"),
                SCORE = LoadSound("assets/sound/score.ogg");
    Vector2 speed, ballPos;
    void resetBall();

public:
    Ball();
    ~Ball();
    void updateBall(Player &p1, Player &p2);
    void drawBall();
    Vector2 getBallPos();
};