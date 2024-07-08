#include <array>
#include <memory>
#include <SFML/Graphics.hpp>

#ifndef ALIENMATRIX_H
#define ALIENCMATRIX_H

class AlienMatrix : public sf::Drawable, public sf::Transformable{
    public:
        AlienMatrix();
        void setupAliens(sf::Texture&, float, float);
        float getAlienHeight();
        float getAlienWidth();

        static const int ROWS = 5;
        static const int COLS = 8;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;

        float alienHeight;
        float alienWidth;
        std::array<std::array<std::unique_ptr<sf::Sprite>, COLS>, ROWS> aliens;
};

#endif