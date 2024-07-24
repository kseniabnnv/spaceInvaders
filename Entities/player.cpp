#include "player.h"
#include "game.h"

Player::Player(){
    this->playerSpeed = 400.f;
    this->hitPoints = 100;
    this->movingUp = false;
    this->movingDown = false;
    this->movingRight = false;
    this->movingLeft = false;
}

void Player::setup(sf::Texture& playerTexture){
    //load player texture
    this->sprite.setTexture(playerTexture);
    this->sprite.scale(sf::Vector2f(0.15f, 0.15f));

    //set the position at the middle of the bottom of the screen
    this->playerWidth = this->sprite.getGlobalBounds().width;
    this->playerHeight = this->sprite.getGlobalBounds().height;
    float playerX = (static_cast<float>(Game::WINDOW_WIDTH) - playerWidth) / 2.f;
    float playerY = static_cast<float>(Game::WINDOW_HEIGHT) - playerHeight; 
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
    moveWithBoundRestrictions(movement * deltaTime.asSeconds());
}

void Player::moveWithBoundRestrictions(sf::Vector2f movement){
    //calculate where the player will end up after we move with the given vector
    sf::Vector2f position = this->sprite.getPosition();
    sf::Vector2f newPosition = position + movement;

    //if the player will end up outside the window, 
    //decrease the vector so that the player ends up on right on the edge
    if(newPosition.x + this->playerWidth > Game::WINDOW_WIDTH || newPosition.x <= 0){
        movement.x = 0;
    } 
    if(newPosition.y + this->playerHeight > Game::WINDOW_HEIGHT || newPosition.y <= 0){
        movement.y = 0;
    } 

    this->sprite.move(movement);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(this->sprite);
}