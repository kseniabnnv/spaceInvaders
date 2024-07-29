/**
 * Abstract base class for all states in the game
 */

#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "stateTypes.hpp"
#include "../Resources/textureContainer.h"
#include "stateStack.h"

class StateStack;   //forward declaration

class State{
    public:
        //using Ptr = std::unique_ptr<State>;
        struct Resources{
            TextureContainer* textures;
            sf::RenderWindow* window;
            //Player* player;
        };
        State(StateStack& stack, Resources resources);


        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(sf::Time deltaTime) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
        virtual ~State() = default;

    protected:
        Resources getResources();
        void requestStackPush(States state);
        void requestStackPop();
        void requestStateClear();
    private:
        Resources resources;
        StateStack* stack;
    
};

#endif