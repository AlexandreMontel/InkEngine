#pragma once
#include "AComponent.h"
#include "box2d/box2d.h"
#include "RigidBody.h"

namespace InkEngine {
    class Collider : public AComponent 
    {

    protected:

        b2FixtureDef b2FixtureDef;
        b2Fixture* fixture;

    public :
        void CreateFixture(b2Body* rBBody);
        virtual b2Shape* GetColliderShape() = 0;
        

        void SetDensity();
        void SetFriction();
    };
}

