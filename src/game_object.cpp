#include "game_object.h"


GameObject::GameObject() 
    : position(0.0f, 0.0f), size(1.0f, 1.0f), color(1.0f), rotation(0.0f), sprite() { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color) 
    : position(pos), size(size), color(color), rotation(0.0f), sprite(sprite) { }

void GameObject::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->sprite, this->position, this->size, this->rotation, this->color);
}