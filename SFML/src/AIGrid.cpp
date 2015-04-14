#include "AIGrid.h"
#include "Config.h"


AIGrid::AIGrid()
{
	const int kiWidth = WINDOW_WIDTH/PATHFINDER_GRID_SIZE;
	const int kiHeight = WINDOW_HEIGHT/PATHFINDER_GRID_SIZE;
	setSize(kiWidth, kiHeight);
	m_Grid[0][1].g_bWalkable = false;
	m_Grid[1][1].g_bWalkable = false;
	m_Grid[2][1].g_bWalkable = false;
	m_Grid[3][1].g_bWalkable = false;
	m_Grid[4][1].g_bWalkable = false;
	m_Grid[5][1].g_bWalkable = false;
	m_Grid[6][1].g_bWalkable = false;
	m_Grid[7][1].g_bWalkable = false;
	m_Grid[8][1].g_bWalkable = false;
	m_Grid[9][1].g_bWalkable = false;
	m_Grid[10][1].g_bWalkable = false;
	m_Grid[11][1].g_bWalkable = false;
	m_Grid[12][1].g_bWalkable = false;
	m_Grid[13][1].g_bWalkable = false;
	m_Grid[14][1].g_bWalkable = false;
	m_Grid[15][1].g_bWalkable = false;
	m_Grid[16][1].g_bWalkable = false;
	m_Grid[17][1].g_bWalkable = false;
	m_Grid[18][1].g_bWalkable = false;
	m_Grid[19][1].g_bWalkable = false;
	m_Grid[20][1].g_bWalkable = false;
}

bool AIGrid::isNodeAtPositionWalkable(Vector2<int> nodeNum) const
{
	return m_Grid[nodeNum.x()][nodeNum.y()].g_bWalkable;
}

std::vector<AISearchNode> AIGrid::getAdjacentNodes(AISearchNode* node) const
{
	std::vector<AISearchNode> nodes;
	AISearchNode newNode;
	newNode.parentNode = node;
	newNode.g_G = newNode.parentNode->g_G + 5;
	//Top node
	if (node->g_Position.y() > 0) {
		Vector2<int> topNodePos = Vector2<int>(node->g_Position.x(), node->g_Position.y()-1);
		if (isNodeAtPositionWalkable(topNodePos)) {
			newNode.g_Position = topNodePos;
			nodes.emplace_back(newNode);
		}
	}
	//Left
	if (node->g_Position.x() > 0) {
		Vector2<int> leftNodePos = Vector2<int>(node->g_Position.x()-1, node->g_Position.y());
		if (isNodeAtPositionWalkable(leftNodePos)) {
			newNode.g_Position = leftNodePos;
			nodes.emplace_back(newNode);
		}
	}
	//Right
	if (node->g_Position.x() < (getWidth() - 1)) {
		Vector2<int> rightNodePos = Vector2<int>(node->g_Position.x()+1, node->g_Position.y());
		if (isNodeAtPositionWalkable(rightNodePos)) {
			newNode.g_Position = rightNodePos;
			nodes.emplace_back(newNode);
		}
	}
	//Bottom
	if (node->g_Position.y() < (getHeight() - 1)) {
		Vector2<int> topNodePos = Vector2<int>(node->g_Position.x(), node->g_Position.y()+1);
		if (isNodeAtPositionWalkable(topNodePos)) {
			newNode.g_Position = topNodePos;
			nodes.emplace_back(newNode);
		}
	}
	return nodes;
}

Vector2<int> AIGrid::getNodePositionFromPixelPosition(Vector2<float> position) const
{
	Vector2<float> newPos = position/PATHFINDER_GRID_SIZE;
	return Vector2<int>(floor(newPos.x()), floor(newPos.y()));
}

Vector2<float> AIGrid::getPixelPosOfNodeTopLeft (Vector2<int> nodePos) const
{
	const Vector2<float> pixelPos = Vector2<float>((float)(nodePos.x() * PATHFINDER_GRID_SIZE), (float)(nodePos.y() * PATHFINDER_GRID_SIZE));
	return pixelPos;
}

Vector2<float> AIGrid::getPixelPosOfNodeCenter (Vector2<int> nodePos) const
{
	Vector2<float> pixelPos = getPixelPosOfNodeTopLeft(nodePos);
	const Vector2<float> nodeHalfSize = Vector2<float>(PATHFINDER_GRID_SIZE/2, PATHFINDER_GRID_SIZE/2);
	return pixelPos + nodeHalfSize;
}

void AIGrid::setSize(const unsigned int kuiRowSize , const unsigned int kuiColumnSize) 
{
	m_Grid.resize(kuiRowSize);
	for (unsigned int i = 0; i < kuiRowSize; i++) {
		m_Grid[i].resize(kuiColumnSize);
	}
	m_iSize.setX(kuiRowSize);
	m_iSize.setY(kuiColumnSize);
	for (unsigned int y = 0; y < getHeight(); y++) {
		for (unsigned int x = 0; x < getWidth(); x++) {
			m_Grid[x][y] = AINode();
		}
	}
};

void AIGrid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (unsigned int y = 0; y < getHeight(); y++) {
		for (unsigned int x = 0; x < getWidth(); x++) {
			Vector2<int> nodePos = Vector2<int>(x, y);
			if (!isNodeAtPositionWalkable(nodePos))
			{
				Vector2<float> position = getPixelPosOfNodeTopLeft(nodePos);
				sf::RectangleShape newRect;
				newRect.setFillColor(sf::Color::Black);
				newRect.setPosition(position.x(), position.y());
				newRect.setSize(sf::Vector2f(PATHFINDER_GRID_SIZE, PATHFINDER_GRID_SIZE));
				target.draw(newRect);
			}
		}
	}
}

AIGrid::~AIGrid()
{
}