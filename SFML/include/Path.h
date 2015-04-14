#ifndef PATH_H
#define PATH_H

#include "Vector2.h"
#include <vector>

class Path
{
public:
	Path();
	~Path();
	void addNodePosition(Vector2<int> nodePos);
	Vector2<int> getNextPosition();
private:
	std::vector<Vector2<int>> m_aPath;
};

#endif