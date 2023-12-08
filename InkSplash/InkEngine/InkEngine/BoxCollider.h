#pragma once
#include "Collider.h"


namespace InkEngine {
    class Application;
    class Entity;
    class BoxCollider :
        public Collider
    {
    protected:
        Entity* ent;
        Application* app;
        b2PolygonShape polyShape;
        std::pair<float,float> size;

    public:

        void Setsize(bool bySprite, float x = 100,float y = 100 );
        virtual b2Shape* GetColliderShape() override;



    };
}

