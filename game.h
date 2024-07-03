#include <SFML/Graphics.hpp>

#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        Game();
        void run();
        
    private:
        static const sf::Time TIME_PER_FRAME;

        int state;
        sf::RenderWindow window;
        sf::Texture texture;
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