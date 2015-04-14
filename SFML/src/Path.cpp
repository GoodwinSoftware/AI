#include "Path.h"

Path::Path()
{
}

Path::~Path()
{

}

void Path::addNodePosition(Vector2<int> nodePos)
{
	m_aPath.emplace_back(nodePos);
}

Vector2<int> Path::getNextPosition()
{
	Vector2<int> nextPos = m_aPath.back();
	printf("Path Next Pos: %i, %i \n", nextPos.x(), nextPos.y());
	if (m_aPath.size() > 1)
		m_aPath.pop_back();
	return nextPos;
}