#include "../include/ball.hpp"

Ball::Ball() : ballSpeed(BALL_SPEED), ballPosition({(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}) {}

Ball::~Ball()
{
    UnloadSound(PLAYER_SOUND);
    UnloadSound(WALL_SOUND);
    UnloadSound(SCORE_SOUND);
}

void Ball::drawBall()
{
    DrawCircleV(ballPosition, BALL_RADIUS, WHITE);
}

void Ball::updateBallFrame(Player &playerOne, Player &playerTwo)
{
    ballPosition.x += ballSpeed.x;
    ballPosition.y += ballSpeed.y;

    if ((ballPosition.y - BALL_RADIUS) <= 0 || (ballPosition.y + BALL_RADIUS) >= GetScreenHeight())
    {
        ballSpeed.y = -ballSpeed.y;
        PlaySound(WALL_SOUND);
    }

    if (CheckCollisionCircleRec(ballPosition, BALL_RADIUS, {playerTwo.getPlayerPosition().x, playerTwo.getPlayerPosition().y, playerTwo.getPlayerSize().x, playerTwo.getPlayerSize().y}) ||
        CheckCollisionCircleRec(ballPosition, BALL_RADIUS, {playerOne.getPlayerPosition().x, playerOne.getPlayerPosition().y, playerOne.getPlayerSize().x, playerOne.getPlayerSize().y}))
    {
        PlaySound(PLAYER_SOUND);
        ballSpeed.x = -ballSpeed.x;
        ballSpeed.x *= BALL_SPEED_INCREMENT;
    }

    if (ballPosition.x < 0)
    {
        PlaySound(SCORE_SOUND);
        playerTwo.scoreUp();
        resetBallPosition();
    }

    if (ballPosition.x > GetScreenWidth())
    {
        PlaySound(SCORE_SOUND);
        playerOne.scoreUp();
        resetBallPosition();
    }
}

Vector2 Ball::getBallPosition()
{
    return ballPosition;
}

void Ball::resetBallPosition()
{
    ballPosition = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    ballSpeed.x = -BALL_SPEED.x * (ballSpeed.x < 0 ? -1 : 1);
}