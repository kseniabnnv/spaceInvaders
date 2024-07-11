#ifndef TEXTURECONTAINER_H
#define TEXTURECONTAINER_H

#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

/**
 * Maps texture names to the appropriate sfml texture objects
 * 
 */
class TextureContainer
{
    public:
        enum class TextureType{
            Background,
            Player,
            Alien
        };

        void load(TextureType type, const std::string& filename);
        sf::Texture& get(TextureType type);

    private:
        std::map<TextureType, std::unique_ptr<sf::Texture>> textureMap;
};

#endif