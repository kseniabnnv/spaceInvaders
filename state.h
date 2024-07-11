#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <memory>

class State{
    public:
        using Ptr = std::shared_ptr<State>;

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(sf::Time deltaTime) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
        virtual ~State() = default;
};

#endif STATE_H