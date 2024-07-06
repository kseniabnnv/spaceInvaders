#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "textureContainer.h"

void TextureContainer::load(TextureType type, const std::string& filename){
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    if(!texture->loadFromFile(filename)){
        std::cout << "Unable to load texture file " << filename << std::endl;
    }
    this->textureMap[type] = std::move(texture);
}

sf::Texture& TextureContainer::get(TextureType type){
    return *(this->textureMap.at(type))
}