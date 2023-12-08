#include "pch.h"
#include "Application.h"
#include <iostream>

InkEngine::Application* InkEngine::Application::_instance = nullptr;

InkEngine::Application::Application()
{
    _instance = this;
    gamePhysics = new Physics();
    CompCrea.initClass();
    
    _windows.create(sf::VideoMode(0, 0), "InkEngine");
    
    Init();
}

InkEngine::Application::~Application()
{

}

void InkEngine::Application::Init()
{
    
}

void InkEngine::Application::Loop()
{
    gamePhysics->Awake();

    for (Entity* ent : _Entities)
    {
        ent->Awake();        
    }
    for (AComponent* comp : _Component)
    {
        InkEngine::CamComponent* CamComponent = dynamic_cast <InkEngine::CamComponent*>(comp);
        if (CamComponent && CamComponent->cameraPrincipal)
        {
            _windows.setView(CamComponent->cameraView);
        }
    }

    sf::Clock clock;
    
    while (_windows.isOpen()) //framerate = nombre de fois ou tu fais ta boucle
    {
        sf::Event event;
        while (_windows.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _windows.close();
        }

        _windows.clear(); //début de la liste des trucs à affichage
        
        sf::Time elapsed = clock.restart();
       
        for (Entity* Entity : _Entities) //Update des Entities
        {      
            Entity->Update(elapsed.asSeconds());
        }        
        
        gamePhysics->Update(elapsed.asSeconds());
          

        for (Entity* Entity : _Entities)
        {
            _windows.draw(*Entity);
        }
        _windows.display(); //fin de l'affichage
    }
}

InkEngine::Entity* InkEngine::Application::CreateEntity(std::string entityName, std::string tag)
{
    Entity* ent = new Entity();   
    _Entities.push_back(ent);

    ent->SetName(entityName);
    ent->SetTag(tag);
    ent->SetID(_Entities.size() - 1);
    ent->GetID();

    return ent;
}

InkEngine::Entity* InkEngine::Application::GetGlobalEntity(std::string Name)
{
    for (Entity* ent : _Entities)
    {
        if (ent->GetName() == Name)
        {
            return ent;
        }
    }
    return nullptr; 
}

int InkEngine::Application::GenerateRandomInt()
{
    std::srand(time(nullptr));
    int x = rand();
    return x;
}

InkEngine::Entity* InkEngine::Application::GetMyEntity(AComponent* comp)
{
    std::string compID = comp->GetID();
    
    for (auto pair : _linkBetweenComponentAndEntity){
        
        std::string MyEntname =_linkBetweenComponentAndEntity.find(compID)->second;//récupe the Entity        

        for (Entity* ent : _Entities)
        {
            if (ent->GetName()== MyEntname)
            {
                return ent;
            }
        }
    }
    return nullptr;
}

InkEngine::Application* InkEngine::Application::GetInstance()
{
    if (_instance == nullptr) {
        _instance = new Application();
    }

    return _instance;
}


sf::RenderWindow* InkEngine::Application::GetWindow()
{
    return  &_windows;
}
void InkEngine::Application::setTheView(sf::View view)
{
    _windows.setView(view);
//    _windows.setSize(view.getSize());

}

void InkEngine::Application::SetWindowSize(sf::Vector2f V2F)
{
    sf::Vector2u V2U(V2F.x, V2F.y);
    _windows.setSize(V2U);
   //std::cout << "(" + std::to_string(_windows.getSize().x) + ";" + std::to_string(_windows.getSize().y) + ")" << std::endl;
}
