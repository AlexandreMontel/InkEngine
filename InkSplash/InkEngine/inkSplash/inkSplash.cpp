#include <SFML/Graphics.hpp>
#include <InkEngine/Application.h>
#include <InkEngine/CamComponent.h>
#include <InkEngine/Manifestant.h>
#include <InkEngine/SpriteRenderer.h>
#include "inkSplash/Crowd.h"
#include "inkSplash/GameManager.h"
#include <InkEngine/MovementInput.h>
#include <InkEngine/RigidBody.h>
#include <InkEngine/BoxCollider.h>
#include <iostream>

InkEngine::Application app;
InkEngine::Crowd;
InkEngine::GameManager;

void NewManifestant() {

    InkEngine::Entity* Manifestant;
    Manifestant = app.CreateEntity("Manifestant", "Manifestant");
    app.CompCrea.CreateSpriteRenderer(Manifestant, "Manifestant2.png", InkEngine::SpriteRenderer::Center);
    app.CreateComponentAndAttachToEntity<InkEngine::BoxCollider>(Manifestant);
    app.CreateComponentAndAttachToEntity<InkEngine::Manifestant>(Manifestant);
    app.CompCrea.CreateRigidbody(Manifestant, b2_kinematicBody, 1);

    Manifestant->setPosition(0, 0);
}

int main()
{
    InkEngine::Entity* BackGround;
    InkEngine::Entity* PlayerObject;
    InkEngine::Entity* Man;

    InkEngine::Entity* Camera;
        
    BackGround = app.CreateEntity("BackGround","Background");
    app.CompCrea.CreateSpriteRenderer(BackGround, "Fond.png", InkEngine::SpriteRenderer::Center);

   
    PlayerObject = app.CreateEntity("Player","Manif");
    app.CompCrea.CreateSpriteRenderer(PlayerObject, "Manifestant1.png",InkEngine::SpriteRenderer::Center);
    app.CompCrea.CreateRigidbody(PlayerObject, b2_dynamicBody, 1);
    
    app.CreateComponentAndAttachToEntity<InkEngine::BoxCollider>(PlayerObject);
    app.CreateComponentAndAttachToEntity<InkEngine::MovementInput>(PlayerObject);
    app.CreateComponentAndAttachToEntity<InkEngine::Crowd>(PlayerObject);


    NewManifestant();
   
    Camera = app.CreateEntity("Camera","Cam");
    app.CompCrea.CreateCameraComponent(Camera, InkEngine::CamComponent::FolloCam,BackGround);
    app.CreateComponentAndAttachToEntity<InkEngine::GameManager>(Camera);
    
    app.Loop();
    
    return 0;
}


