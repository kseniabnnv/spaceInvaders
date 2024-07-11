#ifndef GAME_H
#define GAME_H

#include "textureContainer.h"
#include "alienMatrix.h"
#include "player.h"

class Game
{
    public:
        static const int WINDOW_HEIGHT = 600;
        static const int WINDOW_WIDTH = 800;
        
        Game();
        void run();
        
    private:
        static const sf::Time TIME_PER_FRAME;

        int state;
        sf::RenderWindow window;
        TextureContainer textures;
        AlienMatrix alienMatrix;
        Player player;

        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key, bool);
        void update(sf::Time);
        void render();
};

#endif