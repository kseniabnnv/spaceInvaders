#ifndef APPLICATION_H
#define APPLICATION_H

#include "stateStack.h"
#include "alienMatrix.h"

class Application{
    public:
        static const sf::Time Application::TIME_PER_FRAME;
        static const int WINDOW_HEIGHT = 600;
        static const int WINDOW_WIDTH = 800;

        Application();
        void run();
        void processEvents();
        void update(sf::Time);
        void draw();
    private:
        StateStack stack;
        sf::RenderWindow window;
        TextureContainer textures;
        AlienMatrix alienMatrix;
        Player player;
};

#endif