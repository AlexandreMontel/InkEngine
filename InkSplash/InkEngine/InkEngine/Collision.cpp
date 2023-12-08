#include "pch.h"
#include "Collision.h"

InkEngine::RigidBody* InkEngine::Collision::GetMyRb()
{
    return MyRb;
    
}

InkEngine::RigidBody* InkEngine::Collision::GetOtherRb()
{
    return OtherRb;
}

void InkEngine::Collision::SetMyRb(RigidBody* rB)
{
    MyRb = rB;

}

void InkEngine::Collision::SetOtherRb(RigidBody* rB)
{
    OtherRb = rB;


}


