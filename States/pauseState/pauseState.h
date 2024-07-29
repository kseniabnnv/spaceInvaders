#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "../state.h"


class PauseState : public State{
    public:
        PauseState(StateStack& stack, State::Resources resources);
        
        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void render(sf::RenderTarget& target);
};

#endif