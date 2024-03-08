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
    Player(Vector2 playerPos);
    ~Player();
    void up(const KeyboardKey &key);
    void down(const KeyboardKey &key);
    Vector2 &getPlayerPos();
    static const Vector2 getPlayerSize();
    void setBoundary();
    void drawPlayer();
    void scoreUp();
    int getScore();
};

#endif