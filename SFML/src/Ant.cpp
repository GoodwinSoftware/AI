#include "Ant.h"

Ant::Ant() 
{
	m_GameObjectType = AntGO;
	m_fMovementSpeed = 10.0f;
	m_iHealth = 100.0f;
}

Ant::Ant(sf::Texture& text) 
{
	m_GameObjectType = AntGO;	
	SetTexture(text);
	m_fMovementSpeed = 10.0f;
	m_iHealth = 100.0f;
}

Ant::~Ant() 
{
}