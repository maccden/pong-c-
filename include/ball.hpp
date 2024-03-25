/**
 * @file ball.hpp
 * @author Casteglione Matias
 * @brief This is the ball implementation class
 * @version 0.1
 * @date 2024-03-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BALL_HEADER
#define BALL_HEADER

#include "../include/player.hpp"

#define BALL_RADIUS 10
#define BALL_SPEED Vector2({5, 5})
#define BALL_SPEED_INCREMENT 1.1f

class Ball
{
    const Sound PLAYER_SOUND = LoadSound("assets/sound/player.ogg"),
                WALL_SOUND = LoadSound("assets/sound/wall.ogg"),
                SCORE_SOUND = LoadSound("assets/sound/score.ogg");
    Vector2 ballSpeed, ballPosition;
    void resetBallPosition();

public:
    /**
     * @brief Construct a new Ball object
     *
     */
    Ball();

    /**
     * @brief Destroy the Ball object
     *
     */
    ~Ball();
    void updateBallFrame(Player &playerOne, Player &playerTwo);
    void drawBall();
    Vector2 getBallPosition();
};

#endif