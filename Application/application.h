#ifndef APPLICATION_H
#define APPLICATION_H

#include "../States/stateStack.h"
#include "../Entities/alienMatrix.h"


class Application{
    public:
        static const sf::Time TIME_PER_FRAME;
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
        //AlienMatrix alienMatrix;
        //Player player;
};

#endif