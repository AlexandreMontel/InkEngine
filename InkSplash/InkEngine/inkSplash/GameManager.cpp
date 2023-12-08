#include "InkEngine/pch.h"
#include "inkSplash/GameManager.h"
#include <SFML/Graphics.hpp>
#include <InkEngine/Application.h>
#include <InkEngine/CamComponent.h>
#include <InkEngine/Manifestant.h>
#include <InkEngine/SpriteRenderer.h>
#include "inkSplash/Crowd.h"
#include <InkEngine/MovementInput.h>
#include <InkEngine/RigidBody.h>
#include <InkEngine/BoxCollider.h>
#include <iostream>

void InkEngine::GameManager::Awake()
{
   // app = InkEngine::Application::GetInstance();
    
}

void  InkEngine::GameManager::NewManifestant() {

    InkEngine::Entity* Manifestant;
   
    Manifestant = app->CreateEntity("Manifestant", "Manifestant");
    
    app->CompCrea.CreateSpriteRenderer(Manifestant, "Manifestant2.png", InkEngine::SpriteRenderer::Center);
    app->CreateComponentAndAttachToEntity<InkEngine::BoxCollider>(Manifestant);
    app->CreateComponentAndAttachToEntity<InkEngine::Manifestant>(Manifestant);
    app->CompCrea.CreateRigidbody(Manifestant, b2_kinematicBody, 1);

    Manifestant->setPosition(0, 0);
}

