#include "stateStack.h"
#include "titleState.h"
#include "stateTypes.hpp"
//#include "menuState.h"
//#include "pauseState.h"
//#include "gameState.h"

StateStack::StateStack(){
    //create all the states and put in the map
    this->statesMap[TitleScreen] = std::unique_ptr<TitleState>(new TitleState());
    //push titleScreen on the stack
}

//run update function of the top state
void StateStack::update(sf::Time deltaTime){

}

//run draw function of the top state
void StateStack::draw(){

}

//deliver the event to the top stack (last in the vector)
void StateStack::handleEvent(const sf::Event& event){

    processPendingChanges();
}

void StateStack::pushState(States stateType){

}

void StateStack::popState(){

}

void StateStack::clearStates(){

}

void StateStack::processPendingChanges(){

}

bool StateStack::isEmpty(){
    //close the window if the state is empty
}