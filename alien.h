#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>

class Alien : public sf::Drawable, public sf::Transformable
{
    public:
        void setup(sf::Texture&);
        void damage(int);
        int getHitpoints();
        bool isDead();
        //void setPosition(sf::Vector2f);
        //sf::Vector2f getPosition();
    private:
        sf::Sprite sprite;
        int hitPoints;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;
};

#endif