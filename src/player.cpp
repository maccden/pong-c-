#include "../include/player.hpp"

const Vector2 Player::PLAYER_SIZE = {10.0f, 100.0f};
const float Player::SPEED = 7.0f;

Player::Player(Vector2 playerPos) : playerPos(playerPos), score(0) {}

Player::~Player() {}

void Player::up(const KeyboardKey &key)
{
    playerPos.y -= IsKeyDown(key) ? SPEED : 0;
}

void Player::down(const KeyboardKey &key)
{
    playerPos.y += IsKeyDown(key) ? SPEED : 0;
}

Vector2 &Player::getPlayerPos()
{
    return playerPos;
}

const Vector2 Player::getPlayerSize()
{
    return PLAYER_SIZE;
}

void Player::setBoundary()
{
    playerPos.y = Clamp(playerPos.y, 0, GetScreenHeight() - PLAYER_SIZE.y);
}

void Player::drawPlayer()
{
    DrawRectangleV(playerPos, PLAYER_SIZE, WHITE);
}

void Player::scoreUp()
{
    score++;
}

int Player::getScore()
{
    return score;
}