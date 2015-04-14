#include "Character.h"

Character::Character()
{
	m_iHealth = 0;
	m_fMovementSpeed = 0.0f;
	m_DestinationNode = Vector2<int>();
}

Character::Character(AIGrid* grid)
{
	m_SearchGrid = grid;
	m_iHealth = 0;
	m_fMovementSpeed = 0.0f;
	m_DestinationNode = Vector2<int>();
}

Character::~Character()
{

}

void Character::SetNodePosition(Vector2<int> nodePos)
{
	SetPosition(m_SearchGrid->getPixelPosOfNodeCenter(nodePos));
}

void Character::setPath(Path newPath) { 
	m_Path = newPath;
	Vector2<int> currentNodePos = m_SearchGrid->getNodePositionFromPixelPosition(getPositionCenter());
	printf("Path Start Pos: %i, %i \n", currentNodePos.x(), currentNodePos.y());
	GoToNode(m_Path.getNextPosition());
}

void Character::GoToNode(Vector2<int> newDest)
{
	Vector2<int> currentNodePos = m_SearchGrid->getNodePositionFromPixelPosition(getPosition());
	//Left
	if (newDest.x() < currentNodePos.x())
	{
		fAngle = -90;
		SetVelocity(-m_fMovementSpeed, 0);
	} else if (newDest.x() > currentNodePos.x())
	{
		fAngle = 90;
		SetVelocity(m_fMovementSpeed, 0);
	} else if (newDest.y() > currentNodePos.y())
	{
		fAngle = 180;
		SetVelocity(0, m_fMovementSpeed);
	} else if (newDest.y() < currentNodePos.y())
	{
		fAngle = 0;
		SetVelocity(0, -m_fMovementSpeed);
	}
	m_DestinationNode = newDest;
}

void Character::UpdateCharacterLogic() 
{
	if (m_SearchGrid->getNodePositionFromPixelPosition(getPosition()) == m_DestinationNode)
	{
		GoToNode(m_Path.getNextPosition());
	}
	UpdateGraphics();
}
