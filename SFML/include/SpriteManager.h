/**
 @file SpriteManager.h
 */

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <map>
#include <SFML/GRAPHICS.hpp>

/*! \class SpriteManager
 \brief a manager for textures
 */

struct ImageWithName 
{
	sf::Texture m_texture;
	std::string m_name;
};

class SpriteManager 
{
private:
	std::vector<ImageWithName> m_Textures; //!< Vector of textures with names
    bool loadImage(const std::string& sName /*!< Name of the texture */); //!< Load a texture from a file

public:
    SpriteManager(); //!< Default Constructor
    sf::Texture getTexture(const std::string& sName/*!< Name of the texture */); //!< Retrieve a texture with name
};

#endif /* defined(__Pinball__SpriteLoader__) */
