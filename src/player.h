#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

class Player : public GameObject
{
public:

    Player();
    Player(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color);
    void move(bool toRight);

private:
    float speed;
};

#endif