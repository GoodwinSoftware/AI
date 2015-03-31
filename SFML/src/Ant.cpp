#include "Ant.h"

Ant::Ant() 
{
	m_GameObjectType = AntGO;	
}

Ant::Ant(sf::Texture& text) 
{
	m_GameObjectType = AntGO;	
	SetTexture(text);
}

Ant::~Ant() 
{


}