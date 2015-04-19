#include "Ant.h"
#include "PathFinder.h"

Ant::Ant() 
{
	m_GameObjectType = AntGO;
	m_fMovementSpeed = 50.0f;
	m_iHealth = 100.0f;
	m_DestinationNode = Vector2<int>();
	m_bHasFood = false;
}

Ant::Ant(AIGrid* grid)
{
	m_GameObjectType = AntGO;
	m_SearchGrid = grid;
	m_iHealth = 100.0f;
	m_fMovementSpeed = 90.0f;
	m_DestinationNode = Vector2<int>();
	m_bHasFood = false;
}

Ant::Ant(sf::Texture& text) 
{
	m_GameObjectType = AntGO;	
	SetTexture(text);
	m_fMovementSpeed = 10.0f;
	m_iHealth = 100.0f;
}

void Ant::CharacterLogic()
{
	if (m_bHasFood && m_SearchGrid->getAntHillNode() == m_SearchGrid->getNodePositionFromPixelPosition(getPosition()))
	{
		m_bHasFood = false;
		m_bIsIdle = true;
		m_SearchGrid->iScore++;
	}

	if (!m_bHasFood && m_SearchGrid->isNodeAtPositionFood(m_SearchGrid->getNodePositionFromPixelPosition(getPosition())))
	{
		m_bHasFood = true;
		m_bIsIdle = true;
		m_SearchGrid->foodAtPositionPickedUp(m_SearchGrid->getNodePositionFromPixelPosition(getPosition()));
	}


	if (m_bIsIdle && m_bHasFood)
	{
		PathFinder pathFinder = PathFinder(m_SearchGrid);
		pathFinder.CharacterToNode(this, m_SearchGrid->getAntHillNode());
	} else if (m_bIsIdle)
	{
		PathFinder pathFinder = PathFinder(m_SearchGrid);
		pathFinder.CharacterToNode(this, m_SearchGrid->getClosestFood(m_SearchGrid->getNodePositionFromPixelPosition(getPosition())));
		//Find food
	} else {

	}
}

Ant::~Ant() 
{
}