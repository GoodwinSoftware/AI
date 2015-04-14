#ifndef AIGOAL_H
#define AIGOAL_H

#include <list>
#include "Character.h"
#include "AIGrid.h"

class PathFinder
{
public:
	PathFinder();
	PathFinder(AIGrid* grid);
	~PathFinder();

	void CharacterToNode(Character* ant, Vector2<int> endPos);
	void CharacterToLocation(Character* ant, Vector2<float> endPixelPos);
	Path FindPath(Vector2<int> startPos, Vector2<int> endPos);
private:
	AIGrid* m_SearchGrid;
	Vector2<int> m_StartPos;
	Vector2<int> m_EndPos;
	bool MakeNextDecision();
	std::list<AISearchNode> m_aOpenList;
	std::list<AISearchNode> m_aClosedList;

};



#endif