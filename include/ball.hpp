/**
 * @file ball.hpp
 * @author Casteglione Matias
 * @brief This file contains the ball class.
 * @version 0.1
 * @date 2024-03-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BALL_HEADER
#define BALL_HEADER

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

    /**
     * @brief This method updates the ball position.
     *
     * @param p1 Player one
     * @param p2 Player two
     */
    void updateBall(Player &p1, Player &p2);

    /**
     * @brief This method draws the ball.
     *
     */
    void drawBall();

    /**
     * @brief Get the Ball Pos object.
     *
     * @return Vector2
     */
    Vector2 getBallPos();
};

#endif