#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game.h"

const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f); 

Game::Game(){
    this->window.create(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window.setSize(sf::Vector2u(800, 600));

    this->playerSpeed = 400.f;
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;

    if(!this->texture.loadFromFile("Media\\Textures\\alien.png")){
        std::cout << "Unable to load texture file" << std::endl;
    }
    this->player.setTexture(this->texture);
    player.scale(sf::Vector2f(0.5f, 0.5f));
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(key == sf::Keyboard::W){
        this->movingUp = isPressed;
    } else if (key == sf::Keyboard::S){
        this->movingDown = isPressed;
    } else if (key == sf::Keyboard::A){
        this->movingLeft = isPressed;
    } else if (key == sf::Keyboard::D){
        this->movingRight = isPressed;
    }
}

//process user input
void Game::processEvents(){
sf::Event event;
    while (this->window.pollEvent(event))
    {
        std::cout << "Hello" << std::endl;
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
    sf::Vector2f movement(0.f, 0.f);
    if(movingUp){
        std::cout << "Moving up!";
        movement.y -= this->playerSpeed;
    }
    if(movingDown){
        movement.y += this->playerSpeed;
    }
    if(movingRight){
        movement.x += this->playerSpeed;
    }
    if(movingLeft){
        movement.x -= this->playerSpeed;
    }
    this->player.move(movement * deltaTime.asSeconds());
}

//render the game to the screen
void Game::render(){
    this->window.clear();
    this->window.draw(this->player);
    this->window.display();
}

void Game::run(){
    sf::Clock clock; //start the clock
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
     sf::err() << "SFML Application is running...\n";

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