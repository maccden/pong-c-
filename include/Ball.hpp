#pragma once

#include "raylib.h"
#include "../include/Player.hpp"

class Ball
{
    const static int RADIUS;
    const static float INCREMENT;
    const static Vector2 DEFAULT_SPEED;
    const Sound PLAYER = LoadSound("sound/player.ogg"),
                WALL = LoadSound("sound/wall.ogg"),
                SCORE = LoadSound("sound/score.ogg");
    Vector2 speed, ballPos;
    void resetBall();

public:
    Ball();
    ~Ball();
    void updateBall(Player &p1, Player &p2);
    void drawBall();
    Vector2 getBallPos();
};