#pragma once
#include "Physics.h"
#include "AComponent.h"
#include "box2d/box2D.h"


namespace InkEngine {
    class Application; 
    class Entity;

    class RigidBody : public InkEngine::AComponent {
       
    protected: 
        
        b2Vec2* b2Pos = nullptr;

        Application* app;
        Entity* Ent;

        b2BodyDef bodyDef;
        b2Body* Body = nullptr;

    public:
        RigidBody();
        virtual void Awake() override;
        virtual void Update(float deltaTime) override;
        
        //setters:
        void SetBodyType(b2BodyType bodyType);
        void SetBodyPos();
        void SetLinearVelocity();
        void SetAngularVelocity();
        bool IsDynamic();
        void CreationOfFixture();

        //Getters :
        void GetBodyPos();
        void GetBodyRot();
        void GetLinearVelocity();
        void GetAngularVelocity();
        b2Body* GetBody();

        void setGravity(int i);


        void SetEntityPos();

    };
}
