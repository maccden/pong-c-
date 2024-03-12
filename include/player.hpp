/**
 * @file player.hpp
 * @author Casteglione Matias
 * @brief This file contains the player class.
 * @version 0.1
 * @date 2024-03-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "utils.h"

class Player
{
    const static Vector2 PLAYER_SIZE;
    const static float SPEED;
    Vector2 playerPos;
    int score;

public:
    /**
     * @brief Construct a new Player object
     *
     * @param playerPos Initial player position.
     */
    Player(Vector2 playerPos);

    /**
     * @brief Destroy the Player object
     * 
     */
    ~Player();

    /**
     * @brief This method does the logic for upper movement.
     * 
     * @param key Key from keyboard. 
     */
    void up(const KeyboardKey &key);

    /**
     * @brief This method does the logic for lower movement.
     *
     * @param key Key from keyboard.
     */
    void down(const KeyboardKey &key);

    /**
     * @brief Get the Player Pos object
     * 
     * @return Vector2& 
     */
    Vector2 &getPlayerPos();

    /**
     * @brief Get the Player Size object
     * 
     * @return const Vector2 
     */
    static const Vector2 getPlayerSize();

    /**
     * @brief Set the Boundary object
     * 
     */
    void setBoundary();

    /**
     * @brief This method draws the ball.
     *
     */
    void drawPlayer();

    /**
     * @brief This method does the score logic.
     * 
     */
    void scoreUp();

    /**
     * @brief Get the Score object
     * 
     * @return int 
     */
    int getScore();
};

#endif