#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../state.h"

class GameState : public State{
    public:
        GameState(StateStack& stack, State::Resources resources);
        
        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void render(sf::RenderTarget& target);
};

#endif