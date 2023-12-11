#include "pch.h"
#include "Physics.h"
#include "Application.h"
#include "RigidBody.h"

InkEngine::Physics::Physics()
{
    //world->SetContactListener(&CollListen);
}

void InkEngine::Physics::Awake()
{
    app = InkEngine::Application::GetInstance();
    
    world->SetContactListener(&CollListen);
}




void InkEngine::Physics::Update(float deltaTime)
{
    for (AComponent* Comp : app->_Component)
    {
        InkEngine::RigidBody* RbComp = dynamic_cast <InkEngine::RigidBody*>(Comp);

        if (RbComp)
        {
            RbComp->SetBodyPos();
           //std::cout << "RB is Dynamic = " + std::to_string(RbComp->IsDynamic()) << std::endl;
        }
    }

    world->Step(deltaTime, 8, 3);

    for (AComponent* Comp : app->_Component)
    {
        InkEngine::RigidBody* RbComp = dynamic_cast <InkEngine::RigidBody*>(Comp);

        if (RbComp)
        {
            RbComp->SetEntityPos();
        }
    }

}
const void InkEngine::Physics::WorldScale()
{
    
}
