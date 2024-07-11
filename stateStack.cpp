#include "stateStack.h"

StateStack::StateStack(){
    //create and put all the states in the vector
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