/**
 * Abstract base class for all states in the game
 */

#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "stateTypes.hpp"
#include "textureContainer.h"
#include "player.h"

class State{
    public:
        using Ptr = std::shared_ptr<State>;
        struct Resources{
            TextureContainer* textures;
            sf::RenderWindow* window;
            Player* player;
        };

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(sf::Time deltaTime) = 0;
        virtual void render(sf::RenderTarget& target) = 0;
        virtual ~State() = default;

    protected:
    
};

#endif STATE_H