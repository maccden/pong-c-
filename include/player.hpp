/**
 * @file player.hpp
 * @author Casteglione Matias
 * @brief This is the player implementation class
 * @version 0.1
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "raylib.h"
#include "raymath.h"

#define PLAYER_SIZE Vector2({10.f, 100.f})
#define PLAYER_SPEED 7.f

class Player
{
    Vector2 playerPosition;
    int playerScore;

public:
    Player(Vector2 playerPosition);
    ~Player();
    void moveUp(const KeyboardKey &key);
    void moveDown(const KeyboardKey &key);
    Vector2 &getPlayerPosition();
    Vector2 getPlayerSize() const;
    void setPlayerBoundary();
    void drawPlayer();

    /**
     * @brief This method does the score logic.
     * 
     */
    void scoreUp();
    int getPlayerScore();
};

#endif