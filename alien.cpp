#include "alien.h"
#include <SFML/Graphics.hpp>

Alien::Alien(sf::Texture& texture){
    this->sprite.setTexture(texture);
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

void Alien::setPosition(sf::Vector2f newPosition){
    this->sprite.setPosition(newPosition);
}

sf::Vector2f Alien::getPosition(){
    return this->sprite.getPosition();
}