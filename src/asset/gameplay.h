#pragma once

#include "../Entity/scriptable_entity.h"
#include "../Entity/Component/components.h"

class GamePlay : public ScriptableEntity
{
public:
    void OnCreate();
    void OnDestroy();
    void OnUpdate(float dt);
    void ResetTimer();
    void CreatePipes();

private:
    float timer;
};