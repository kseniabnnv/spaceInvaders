#include "application.h"

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

Application::Application(){
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
}

void Application::processEvents(){
    sf::Event event;
    while(this->window.pollEvent(event)){
        this->stack.handleEvent(event);
    }
}

void Application::update(sf::Time deltaTime){
    this->stack.update(deltaTime);
}

void Application::draw(){
    this->stack.draw();
}

void Application::run(){
    sf::Clock clock; //start the clock
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(this->window.isOpen()){
        processEvents();
        timeSinceLastUpdate += clock.restart();

        //fixed timestamps
        while(timeSinceLastUpdate > TIME_PER_FRAME){
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        draw();
    } 
}
