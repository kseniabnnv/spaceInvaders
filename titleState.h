#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "state.h"

class TitleState : public State{
    public:
        virtual void handleEvent(const sf::Event& event);
        virtual void update(sf::Time deltaTime);
        virtual void render(sf::RenderTarget& target);

};

#endif