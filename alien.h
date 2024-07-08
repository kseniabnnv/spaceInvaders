#include <SFML/Graphics.hpp>

#ifndef ALIEN_H
#define ALIEN_H

class Alien
{
    public:
        Alien(sf::Texture&);
        void damage(int);
        int getHitpoints();
        bool isDead();
        void setPosition(sf::Vector2f);
        sf::Vector2f getPosition();
    private:
        //movement pattern?
        // right down
        // left down
        sf::Sprite sprite;
        int hitPoints;
};

#endif