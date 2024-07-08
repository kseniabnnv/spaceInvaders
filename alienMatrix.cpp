#include "alienMatrix.h"

//initialize a grid of aliens with given height and width
AlienMatrix::AlienMatrix(){

}

void AlienMatrix::setup(sf::Texture& alienTexture, float spriteHeight, float spriteWidth){
    sf::Vector2u textureSize = alienTexture.getSize();
    this->alienHeight = spriteHeight;
    this->alienWidth = spriteWidth;

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            this->aliens[row][col] = std::make_unique<sf::Sprite>();
            this->aliens[row][col]->setTexture(alienTexture);
            this->aliens[row][col]->setScale(
                spriteWidth / static_cast<float> (textureSize.x),
                spriteHeight / static_cast<float> (textureSize.y)
            );

            //set position within the matrix
            //initial position will be relative to the matrix's origin (0,0)
            this->aliens[row][col]->setPosition(
                static_cast<float>(col) * spriteWidth, 
                static_cast<float>(row) * spriteHeight
            );
        }
    }
}

void AlienMatrix::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            target.draw(*this->aliens[row][col], states);
        }
    }
}

float AlienMatrix::getAlienHeight(){
    return this->alienHeight;
}

float AlienMatrix::getAlienWidth(){
    return this->alienWidth;
}