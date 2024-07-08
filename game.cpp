#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game.h"


const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f); 

Game::Game()
{
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
    this->window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));

    this->playerSpeed = 400.f;
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;

    //load textures
    this->textures.load(TextureContainer::TextureType::Player, "Media\\Textures\\player.png");
    this->textures.load(TextureContainer::TextureType::Alien, "Media\\Textures\\alien.png");

    //load player texture and set its position
    this->player.setTexture(this->textures.get(TextureContainer::TextureType::Player));
    this->player.scale(sf::Vector2f(0.15f, 0.15f));
    float playerWidth = this->player.getGlobalBounds().width;
    float playerHeight = this->player.getGlobalBounds().height;

    float windowWidth = static_cast<float>(WINDOW_WIDTH); 
    float windowHeight = static_cast<float>(WINDOW_HEIGHT); 
    float playerX = (windowWidth - playerWidth) / 2.f;
    float playerY = windowHeight - playerHeight; 
    this->player.setPosition(playerX, playerY);

    //initialize aliens and set their position
    this->alienMatrix.setupAliens(this->textures.get(TextureContainer::TextureType::Alien), 50.f, 50.f);
    this->alienMatrix.setPosition((WINDOW_WIDTH - this->alienMatrix.getAlienWidth() * AlienMatrix::COLS) / 2.f, 50);
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