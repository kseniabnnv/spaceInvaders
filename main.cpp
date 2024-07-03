//#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "game.h"

int main()
{
    //redirect sfml err to cout
    sf::err().rdbuf(std::cout.rdbuf());
    Game game;
    game.run();

    return 0;
}