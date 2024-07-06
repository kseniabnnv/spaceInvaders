#include <SFML/Graphics.hpp>

class Alien
{
    public:
        Alien(sf::Texture& texture);
        void setVelocity();
        sf::Vector2f getVelocity();
        int damage(int points);
        int getHitpoints();
        bool isDead();
    private:
        //movement pattern?
        // right down
        // left down
        sf::Sprite sprite;
        int hitPoints;
};