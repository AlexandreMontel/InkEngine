#pragma once
#include "AComponent.h"
#include "SFML/Graphics/View.hpp"
#include <iostream>

namespace InkEngine {
    class Application;    
    class Entity;
    class SpriteRenderer;

    class CamComponent :
        public InkEngine::AComponent, public sf::View {

    protected : 
       
        Application* app;
        Entity* ObjectToFollow;
        std::pair<float, float> size;
        sf::Vector2f ScreenSize;
        
    public:
        
        enum CameraType
        {
            DynamiCam,
            FolloCam,
            StatiCam,
        };

        CameraType CamType;

        bool cameraPrincipal,followObject;
        sf::View cameraView;
        

        CamComponent();

        virtual void Awake() override;

        virtual void Update(float deltaTime) override; 
        
        void Zoom(float zoomRate);

        void SetViewport(sf::FloatRect CamView);

        void CameraRotation(float rot);

        void SetObjectToFollow(Entity* EntTofollow);
        

    };
}

