#include "pch.h"
#include "BoxCollider.h"
#include "Application.h"
#include "SpriteRenderer.h"

void InkEngine::BoxCollider::Setsize(bool bySprite, float x, float y)
{
   // app = InkEngine::Application::GetInstance();
    size.first = x;
    size.second = y;

    if (bySprite)
    {
       ent = app->GetMyEntity(this);
       SpriteRenderer* sr = ent->getAComponent<SpriteRenderer>();
       size = sr->GetSize();
    }


}

b2Shape* InkEngine::BoxCollider::GetColliderShape()
{
    Setsize(true);
    polyShape.SetAsBox((size.first/2),( size.second/2));
    return &polyShape;

}


