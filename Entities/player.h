#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable{
    public:
        Player();
        bool isDead();
        void setup(sf::Texture&);
        void updateMovementDirection(sf::Keyboard::Key, bool);
        void updatePosition(sf::Time);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;
        void moveWithBoundRestrictions(sf::Vector2f);

        sf::Sprite sprite;
        float playerWidth;
        float playerHeight;
        int hitPoints;
        float playerSpeed;
        bool movingUp;
        bool movingDown;
        bool movingRight;
        bool movingLeft;
};

#endif