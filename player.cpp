#include "player.h"

Player::Player(){
    this->playerSpeed = 400.f;
    this->hitPoints = 100;
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
}

void Player::setup(sf::Texture& playerTexture, float windowWidth, float windowHeight){
    //load player texture
    this->sprite.setTexture(playerTexture);
    this->sprite.scale(sf::Vector2f(0.15f, 0.15f));

    //set the position at the middle of the bottom of the screen
    float playerWidth = this->sprite.getGlobalBounds().width;
    float playerHeight = this->sprite.getGlobalBounds().height;
    float playerX = (windowWidth - playerWidth) / 2.f;
    float playerY = windowHeight - playerHeight; 
    this->sprite.setPosition(playerX, playerY);
}

bool Player::isDead(){
    return (this->hitPoints <= 0);
}

void Player::updateMovementDirection(sf::Keyboard::Key key, bool isPressed){
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

void Player::updatePosition(sf::Time deltaTime){
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
    this->sprite.move(movement * deltaTime.asSeconds());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(this->sprite);
}