/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "camera2D.h"
#include "player.h"
#include <filesystem>

#include <iostream>
#include <sstream>
#include <fstream>


// Game-related State data
SpriteRenderer  *Renderer;
Camera2D *camera;

Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height), gameObjects()
{ 

}

Game::~Game()
{
    delete Renderer;
    delete camera;
}

void Game::Init()
{
    std::cout << std::filesystem::current_path() << std::endl;
    camera = new Camera2D(glm::vec2(this->Width, this->Height), glm::vec2(0, 0));
    // load shaders
    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader spriteShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(spriteShader);
    // load textures
    ResourceManager::LoadTexture("textures/tiles.png", true, "tiles");
    ResourceManager::LoadTexture("textures/mario.png", true, "mario");
    Texture2D mario = ResourceManager::GetTexture("mario");
    gameObjects.push_back(Player(glm::vec2(100.0f, 100.0f), glm::vec2(100.0f, 200.0f), mario,glm::vec3(1.0f, 1.0f, 1.0f)));
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(GLFWwindow *window, float dt)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->ProcessKeyboard(UPWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->ProcessKeyboard(DOWNWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->ProcessKeyboard(LEFT, dt);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->ProcessKeyboard(RIGHT, dt);
}

void Game::Render()
{
    Texture2D texture = ResourceManager::GetTexture("tiles");
    glm::mat4 view = camera->GetViewMatrix();
    ResourceManager::GetShader("sprite").SetMatrix4("view", view);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Renderer->DrawSprite(texture, glm::vec2(i * 40.0f, 600 - j * 40.0f), glm::vec2(40.0f, 40.0f));
        }
    }
    for(GameObject obj : gameObjects)
    {
     //   obj->Draw(*Renderer);
        obj.Draw(*Renderer);

    }
}