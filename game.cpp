#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game.h"


const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f); 

Game::Game()
{
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));

    //load textures
    this->textures.load(TextureContainer::TextureType::Player, "Media\\Textures\\player.png");
    this->textures.load(TextureContainer::TextureType::Alien, "Media\\Textures\\alien.png");

    //load player texture and set its position
    this->player.setup(this->textures.get(TextureContainer::TextureType::Player));

    //initialize aliens and set their position
    this->alienMatrix.setup(this->textures.get(TextureContainer::TextureType::Alien), 50.f, 50.f);
    this->alienMatrix.setPosition((WINDOW_WIDTH - this->alienMatrix.getAlienWidth() * AlienMatrix::COLS) / 2.f, 50);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    this->player.updateMovementDirection(key, isPressed);
}

//process user input
void Game::processEvents(){
sf::Event event;
    while (this->window.pollEvent(event))
    {
        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                this->window.close();
                break;
        }
    }
}

//updates the game logic
//deltaTime: how much time has elapsed since last update
void Game::update(sf::Time deltaTime){
    this->player.updatePosition(deltaTime);
}

//render the game to the screen
void Game::render(){
    this->window.clear();
    this->window.draw(this->player);
    this->window.draw(this->alienMatrix);
    this->window.display();
}

void Game::run(){
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
        render();
    }
}