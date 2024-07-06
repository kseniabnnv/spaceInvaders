#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity(sf::Texture& texture);
        void setVelocity();
        sf::Vector2f getVelocity();
    private:
        sf::Sprite sprite;
};