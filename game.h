#include <SFML/Graphics.hpp>
#include "textureContainer.h"
#include "alienMatrix.h"

#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        Game();
        void run();
        
    private:
        static const sf::Time TIME_PER_FRAME;
        static const int WINDOW_HEIGHT = 600;
        static const int WINDOW_WIDTH = 800;

        int state;
        sf::RenderWindow window;
        TextureContainer textures;
        AlienMatrix alienMatrix;
        sf::Sprite player;

        float playerSpeed;
        bool movingUp;
        bool movingDown;
        bool movingRight;
        bool movingLeft;

        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key, bool);
        void update(sf::Time);
        void render();
};

#endif