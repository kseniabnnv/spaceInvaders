#ifndef STATESTACK_H
#define STATESTACK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "stateTypes.hpp"
#include "state.h"

class State;

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
        //std::vector<std::unique_ptr<State>> stack; //store actual states here
        std::map<States, std::unique_ptr<State>> statesMap;
        //std::vector<PendingChange> pendingChangesList;

        void processPendingChanges();
};  

#endif