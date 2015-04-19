#include "PathFinder.h"

PathFinder::PathFinder()
{
	m_aClosedList = std::list<AISearchNode>();
	m_aOpenList = std::list<AISearchNode>();
}

PathFinder::PathFinder(AIGrid* grid)
{
	m_SearchGrid = grid;
	m_StartPos = Vector2<int>();
	m_EndPos = Vector2<int>();
	m_aClosedList = std::list<AISearchNode>();
	m_aOpenList = std::list<AISearchNode>();
}

void PathFinder::CharacterToNode(Character* character, Vector2<int> endPos)
{
	character->setPath(FindPath(m_SearchGrid->getNodePositionFromPixelPosition(character->getPosition()), endPos), endPos);
}

void PathFinder::CharacterToLocation(Character* character, Vector2<float> endPixelPos)
{
	Vector2<int> destinationPoint =  m_SearchGrid->getNodePositionFromPixelPosition(endPixelPos);
	character->setPath(FindPath(m_SearchGrid->getNodePositionFromPixelPosition(character->getPosition()), destinationPoint), destinationPoint);
}

Path PathFinder::FindPath(Vector2<int> startPos, Vector2<int> endPos)
{
	m_StartPos = startPos;
	m_EndPos = endPos;

	m_aClosedList.emplace_back(AISearchNode(startPos));
	m_aClosedList.back().getManhattenDistance(m_EndPos);

	bool b = false;
	while (!b)
	{
		b = MakeNextDecision();
	}

	//Generate the path
	b = false;
	Path newPath;
	AISearchNode currentNode = m_aClosedList.back();
	Vector2<int> currentNodePos;
	while (currentNode.g_Position != startPos)
	{
		newPath.addNodePosition(currentNode.g_Position);
		currentNode = *currentNode.parentNode;
	}

	m_aClosedList.clear();
	m_aOpenList.clear();

	return newPath;
}

bool PathFinder::MakeNextDecision()
{
	//Get new nodes adjacent to the most recently added node on the closed list
	std::vector<AISearchNode> newNodes;
	newNodes = m_SearchGrid->getAdjacentNodes(&m_aClosedList.back());
	for (auto newNodeIterator = newNodes.begin(); newNodeIterator != newNodes.end(); ++newNodeIterator)
	{
		AISearchNode newOpenNode = *newNodeIterator;
		newOpenNode.getManhattenDistance(m_EndPos);
		m_aOpenList.emplace_back(newOpenNode);
	}

	//Check for Duplicates
	std::vector<AISearchNode> duplicateNodes = std::vector<AISearchNode>();
	for (auto openListIterator = m_aOpenList.begin(); openListIterator != m_aOpenList.end(); ++openListIterator)
	{
		Vector2<int> position = openListIterator->g_Position;
		for (auto closedListIterator = m_aClosedList.begin(); closedListIterator != m_aClosedList.end(); ++closedListIterator)
		{
			if (closedListIterator->g_Position == position)
			{
				AISearchNode nodeToRemoveFromOpenList = *openListIterator;
				duplicateNodes.emplace_back(nodeToRemoveFromOpenList);
			}
		}
	}
	//Remove Duplicates
	for (auto duplicateIterator = duplicateNodes.begin(); duplicateIterator != duplicateNodes.end(); ++duplicateIterator)
	{
		AISearchNode nodeToRemoveFromOpenList = *duplicateIterator;
		m_aOpenList.remove(nodeToRemoveFromOpenList);
	}




	//Find the node with the lowest F value in the open list
	float fLowestF = 0.0f;
	AISearchNode closestNode;
	for (auto openListIterator = m_aOpenList.begin(); openListIterator != m_aOpenList.end(); ++openListIterator)
	{
		if (fLowestF == 0.0f)
		{
			fLowestF = openListIterator->getF();
			closestNode = *openListIterator;
		} else {
			float fNewF = openListIterator->getF();
			if (fNewF < fLowestF)
			{
				closestNode = *openListIterator;
			}
		}
	}
	//Move it to the back of the closed list and remove it from the open list
	m_aOpenList.remove(closestNode);
	m_aClosedList.emplace_back(closestNode);

	//If the node is the target the PathFinder is finished
	if(closestNode.g_H < 1)
	{
		return true;
	}

	return false;
}

PathFinder::~PathFinder()
{
}