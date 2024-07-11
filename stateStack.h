#ifndef STATESTACK_H
#define STATESTACK_H

#include <SFML/Graphics.hpp>
#include "stateTypes.hpp"
#include "state.h"

class StateStack {
    public:
        enum Action{
            Push,
            Pop,
            Clear
        };

        StateStack();

        void update(sf::Time deltaTime);
        void draw();
        void handleEvent(const sf::Event& event);

        void pushState(States stateType);
        void popState();
        void clearStates();

        bool isEmpty();

    private:
        struct PendingChange{
            Action action;
            States stateType;
        };
        std::vector<State::Ptr> stack;
        std::vector<PendingChange> pendingChangesList;

        void processPendingChanges();
};  

#endif