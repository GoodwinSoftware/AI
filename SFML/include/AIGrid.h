#ifndef AIGRID_H
#define AIGRID_H

#include "Vector2.h"
#include <memory>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>


enum NodeTypes {
	Empty = 0,
	Grass = 1,
	Wall = 2,
	Food = 3,
	AntHill = 4,
};

class AINode {
public:
	AINode() {
		g_NodeType = Grass;
	}
	NodeTypes g_NodeType;
};

struct AISearchNode {
public:
	AISearchNode* parentNode;
	Vector2<int> g_Position;
	float g_G;
	int g_H;

	AISearchNode() { parentNode = 0; g_G = 0.0f; g_H = 0.0f; };
	AISearchNode(Vector2<int> position) {  g_Position = position; parentNode = 0; g_G = 0.0f; g_H = 0.0f; };
	float getF() const { return g_G + g_H; };
	void getManhattenDistance(Vector2<int> destinationNode)  
	{
		const int k_iXDist = abs(g_Position.x() - destinationNode.x());
		const int k_iYDist = abs(g_Position.y() - destinationNode.y());
		g_H =  k_iXDist + k_iYDist;
	};
	bool operator==(const AISearchNode& kOtherNode) const { if (g_Position == kOtherNode.g_Position) return true; return false; };
};

class AIGrid : public sf::Drawable
{
public:
	AIGrid();
	~AIGrid();
	int iScore;

	void loadFromFile(const char* filePath);
	NodeTypes getNodeTypeOfNodeAtPosition(Vector2<int> nodePos) const;
	void setNodeTypeOfNodeAtPosition(Vector2<int> nodePos, NodeTypes type);

	bool isNodeAtPositionFood(Vector2<int> nodeNum) const;
	bool isNodeAtPositionWalkable(Vector2<int> nodeNum) const;

	void foodAtPositionPickedUp(Vector2<int> nodeNum);

	Vector2<int> getClosestFood(Vector2<int> nodeNum);
	Vector2<int> getAntHillNode() const;
	Vector2<int> getNodePositionFromPixelPosition(Vector2<float> position) const;
	Vector2<float> getPixelPosOfNodeTopLeft (Vector2<int> nodeNum) const;
	Vector2<float> getPixelPosOfNodeCenter (Vector2<int> nodeNum) const;

	std::vector<AISearchNode> AIGrid::getAdjacentNodes(AISearchNode* node) const;

	void setSize(const unsigned int kuiRowSize /*!< Row Size*/, const unsigned int kuiColumnSize/*Column Size*/);
	const int getWidth() const { return m_iSize.x(); };
	const int getHeight() const { return m_iSize.y(); };

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the Object
private:
	Vector2<int> m_iSize;
	std::vector<std::vector<AINode>> m_Grid;
};

#endif