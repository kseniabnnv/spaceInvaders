#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../state.h"

class MenuState : public State{
    public:
        MenuState(StateStack& stack, State::Resources resources);
        
        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void render(sf::RenderTarget& target);
};

#endif