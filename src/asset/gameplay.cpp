#include "gameplay.h"
#include "../input.h"
#include <iostream>


void GamePlay::OnCreate()
{
    std::cout << "OnCreate GamePlay" << std::endl;
    ResetTimer();
}

void GamePlay::OnDestroy()
{
}

void GamePlay::OnUpdate(float dt)
{
    if (timer <= 0)
    {
        ResetTimer();
    }
    else
    {
        timer -= dt;
    }
    
}

void GamePlay::ResetTimer()
{
    timer = 1.0f;
}

void GamePlay::CreatePipes()
{
    
}