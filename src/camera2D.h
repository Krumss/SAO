#ifndef CAMERA2D_H
#define CAMERA2D_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtx/string_cast.hpp>

#include <vector>

#include <iostream>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    UPWARD,
    DOWNWARD,
    LEFT,
    RIGHT
};

class Camera2D
{
public:
    glm::vec2 position;
    glm::vec2 wh;
    float zoom;
    float speed = 25.0f;

    Camera2D(glm::vec2 wh, glm::vec2 pos = glm::vec2(0.0f, 0.0f))
        : position(pos), wh(wh) { }

    Camera2D(unsigned int w, unsigned int h, float posX, float posY)
    {
        position = glm::vec2(posX, posY);
        wh = glm::vec2(w, h);
    }

    glm::mat4 GetViewMatrix()
    {
        return glm::lookAt(glm::vec3(position, 0.0), glm::vec3(position, 0.0) + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = speed * deltaTime;
        if (direction == UPWARD)
            position += glm::vec2(0.0f, 1.0f) * velocity;
        if (direction == DOWNWARD)
            position -= glm::vec2(0.0f, 1.0f) * velocity;
        if (direction == LEFT)
            position -= glm::vec2(1.0f, 0.0f) * velocity;
        if (direction == RIGHT)
            position += glm::vec2(1.0f, 0.0f) * velocity;
    }
};



#endif