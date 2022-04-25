#include "player.h"

Player::Player()
    : GameObject(), speed(10.0f) { }

Player::Player(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color)
    : GameObject(pos, size, sprite, color), speed(1.0f) { }

void Player::move(bool toRight)
{
    position += toRight ? glm::vec2(1.0f, 0.0f) * speed : glm::vec2(-1.0f, 0.0f) * speed;
}