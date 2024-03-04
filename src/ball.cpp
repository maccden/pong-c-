#include "../include/ball.hpp"

const int Ball::RADIUS = 10;
const Vector2 Ball::DEFAULT_SPEED = {5, 5};
const float Ball::INCREMENT = 1.1f;

Ball::Ball() : speed(DEFAULT_SPEED), ballPos({(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}) {}

Ball::~Ball()
{
    UnloadSound(PLAYER);
    UnloadSound(WALL);
    UnloadSound(SCORE);
}

void Ball::drawBall()
{
    DrawCircleV(ballPos, RADIUS, WHITE);
}

void Ball::updateBall(Player &p1, Player &p2)
{
    ballPos.x += speed.x;
    ballPos.y += speed.y;

    if ((ballPos.y - RADIUS) <= 0 || (ballPos.y + RADIUS) >= GetScreenHeight())
    {
        speed.y = -speed.y;
        PlaySound(WALL);
    }

    if (CheckCollisionCircleRec(ballPos, RADIUS, {p2.getPlayerPos().x, p2.getPlayerPos().y, p2.getPlayerSize().x, p2.getPlayerSize().y}) ||
        CheckCollisionCircleRec(ballPos, RADIUS, {p1.getPlayerPos().x, p1.getPlayerPos().y, p1.getPlayerSize().x, p1.getPlayerSize().y}))
    {
        PlaySound(PLAYER);
        speed.x = -speed.x;
        speed.x *= INCREMENT;
    }

    if (ballPos.x < 0)
    {
        PlaySound(SCORE);
        p2.scoreUp();
        resetBall();
    }

    if (ballPos.x > GetScreenWidth())
    {
        PlaySound(SCORE);
        p1.scoreUp();
        resetBall();
    }
}

Vector2 Ball::getBallPos()
{
    return ballPos;
}

void Ball::resetBall()
{
    ballPos = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    speed.x = -DEFAULT_SPEED.x * (speed.x < 0 ? -1 : 1);
}