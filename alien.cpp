#include "alien.h"
#include <SFML/Graphics.hpp>

void Alien::setup(sf::Texture& texture){
    this->sprite.setTexture(texture);
    //this->sprite.setScale(xScale, yScale);
}

void Alien::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(this->sprite, states);
}


void Alien::damage(int points){
    this->hitPoints -= points;
}

bool Alien::isDead(){
    return (this->hitPoints <= 0);
}

int Alien::getHitpoints(){
    return this->hitPoints;
}

// void Alien::setPosition(sf::Vector2f newPosition){
//     this->sprite.setPosition(newPosition);
// }

// sf::Vector2f Alien::getPosition(){
//     return this->sprite.getPosition();
// }