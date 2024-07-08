#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable{
    public:
        Player();
        bool isDead();
        void setup(sf::Texture&, float, float);
        void updateMovementDirection(sf::Keyboard::Key, bool);
        void updatePosition(sf::Time);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;

        sf::Sprite sprite;
        int hitPoints;
        float playerSpeed;
        bool movingUp;
        bool movingDown;
        bool movingRight;
        bool movingLeft;
};