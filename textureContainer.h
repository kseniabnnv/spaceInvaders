#include <map>
#include <memory>

/**
 * Maps texture names to the appropriate sfml texture objects
 * 
 */
class TextureContainer
{
    public:
    enum Textures{
        Background,
        Player,
        Enemy
    }

    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> textureMap;
};