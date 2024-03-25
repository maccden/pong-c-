#include "../include/player.hpp"

Player::Player(Vector2 playerPosition) : playerPosition(playerPosition), playerScore(0) {}

Player::~Player() {}

void Player::moveUp(const KeyboardKey &key)
{
    playerPosition.y -= IsKeyDown(key) ? PLAYER_SPEED : 0;
}

void Player::moveDown(const KeyboardKey &key)
{
    playerPosition.y += IsKeyDown(key) ? PLAYER_SPEED : 0;
}

Vector2 &Player::getPlayerPosition()
{
    return playerPosition;
}

Vector2 Player::getPlayerSize() const
{
    return PLAYER_SIZE;
}

void Player::setPlayerBoundary()
{
    playerPosition.y = Clamp(playerPosition.y, 0, GetScreenHeight() - PLAYER_SIZE.y);
}

void Player::drawPlayer()
{
    DrawRectangleV(playerPosition, PLAYER_SIZE, WHITE);
}

void Player::scoreUp()
{
    playerScore++;
}

int Player::getPlayerScore()
{
    return playerScore;
}