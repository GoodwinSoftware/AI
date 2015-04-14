#include "Ant.h"

Ant::Ant() 
{
	m_GameObjectType = AntGO;
	m_fMovementSpeed = 50.0f;
	m_iHealth = 100.0f;
	m_DestinationNode = Vector2<int>();
}

Ant::Ant(AIGrid* grid)
{
	m_SearchGrid = grid;
	m_iHealth = 100.0f;
	m_fMovementSpeed = 30.0f;
	m_DestinationNode = Vector2<int>();
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