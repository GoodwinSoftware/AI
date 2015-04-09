/**
 @file SpriteManager.cpp
 */

#include "SpriteManager.h"

SpriteManager::SpriteManager() //!< Default Constructor
{
}

sf::Texture SpriteManager::getTexture(const std::string& sName /* !< Name of the texture */) //!< Retrieve a texture with name
{
    for (auto i = m_Textures.begin(); i != m_Textures.end(); i++) 
	{
        if (i->m_name == sName) 
		{
            return i->m_texture;
        }
    }

	//If texture not found load from 
    if (loadImage(sName)) 
	{
        return m_Textures.back().m_texture;
    } 
	else 
	{
        printf("SPRITE MANAGER ERROR: Returning null Texture \n");
    }

    return sf::Texture();
}

bool SpriteManager::loadImage(const std::string& sName /* !< Name of the texture */) //!< Load a texture from a file
{
    ImageWithName newImage;
    newImage.m_name = sName;

    if (!newImage.m_texture.loadFromFile(sName)) 
	{
        printf("SPRITE MANAGER - Failed to load image: %s \n", sName.c_str());
        return false;
    }
	
	printf("SPRITE MANAGER - Loaded image: %s \n", sName.c_str());
    
    m_Textures.push_back(newImage);
    return true;
}