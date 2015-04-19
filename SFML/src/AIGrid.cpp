#include "AIGrid.h"
#include "Config.h"
#include <fstream>
#include <sstream>

AIGrid::AIGrid()
{
	const int kiWidth = WINDOW_WIDTH/PATHFINDER_GRID_SIZE;
	const int kiHeight = WINDOW_HEIGHT/PATHFINDER_GRID_SIZE;
	setSize(kiWidth, kiHeight);
	iScore = 0;

	m_Grid[0][0].g_NodeType = AntHill;

	m_Grid[0][2].g_NodeType = Wall;
	m_Grid[1][2].g_NodeType = Wall;
	m_Grid[2][2].g_NodeType = Wall;
	m_Grid[3][2].g_NodeType = Wall;
	m_Grid[4][2].g_NodeType = Wall;
	m_Grid[5][2].g_NodeType = Wall;
	m_Grid[6][2].g_NodeType = Wall;
	m_Grid[7][2].g_NodeType = Wall;
	m_Grid[8][2].g_NodeType = Wall;
	m_Grid[9][2].g_NodeType = Wall;
	m_Grid[10][2].g_NodeType = Wall;
	m_Grid[11][2].g_NodeType = Wall;
	m_Grid[12][2].g_NodeType = Wall;
	m_Grid[13][2].g_NodeType = Wall;
	m_Grid[14][2].g_NodeType = Wall;
	m_Grid[15][2].g_NodeType = Wall;
	m_Grid[16][2].g_NodeType = Wall;
	m_Grid[17][2].g_NodeType = Wall;
	m_Grid[18][2].g_NodeType = Wall;
	m_Grid[25][2].g_NodeType = Wall;
	m_Grid[26][2].g_NodeType = Wall;
	m_Grid[27][2].g_NodeType = Wall;
	m_Grid[28][2].g_NodeType = Wall;
	m_Grid[29][2].g_NodeType = Wall;
	m_Grid[30][2].g_NodeType = Wall;
	m_Grid[31][2].g_NodeType = Wall;
	m_Grid[32][2].g_NodeType = Wall;

	m_Grid[1][4].g_NodeType = Food;


	m_Grid[5][7].g_NodeType = Wall;
	m_Grid[6][7].g_NodeType = Wall;
	m_Grid[7][7].g_NodeType = Wall;
	m_Grid[8][7].g_NodeType = Wall;
	m_Grid[9][7].g_NodeType = Wall;
	m_Grid[10][7].g_NodeType = Wall;
	m_Grid[11][7].g_NodeType = Wall;
	m_Grid[12][7].g_NodeType = Wall;
	m_Grid[13][7].g_NodeType = Wall;
	m_Grid[14][7].g_NodeType = Wall;
	m_Grid[15][7].g_NodeType = Wall;
	m_Grid[16][7].g_NodeType = Wall;
	m_Grid[17][7].g_NodeType = Wall;
	m_Grid[18][7].g_NodeType = Wall;
	m_Grid[19][7].g_NodeType = Wall;
	m_Grid[20][7].g_NodeType = Wall;
	m_Grid[21][7].g_NodeType = Wall;
	m_Grid[22][7].g_NodeType = Wall;
	m_Grid[25][7].g_NodeType = Wall;
	m_Grid[26][7].g_NodeType = Wall;
	m_Grid[27][7].g_NodeType = Wall;
	m_Grid[28][7].g_NodeType = Wall;
	m_Grid[29][7].g_NodeType = Wall;
	m_Grid[30][7].g_NodeType = Wall;
	m_Grid[31][7].g_NodeType = Wall;
	m_Grid[32][7].g_NodeType = Wall;

	m_Grid[0][11].g_NodeType = Wall;
	m_Grid[1][11].g_NodeType = Wall;
	m_Grid[2][11].g_NodeType = Wall;
	m_Grid[3][11].g_NodeType = Wall;
	m_Grid[4][11].g_NodeType = Wall;
	m_Grid[5][11].g_NodeType = Wall;
	m_Grid[6][11].g_NodeType = Wall;
	m_Grid[7][11].g_NodeType = Wall;
	m_Grid[8][11].g_NodeType = Wall;
	m_Grid[9][11].g_NodeType = Wall;
	m_Grid[10][11].g_NodeType = Wall;
	m_Grid[11][11].g_NodeType = Wall;
	m_Grid[12][11].g_NodeType = Wall;
	m_Grid[13][11].g_NodeType = Wall;
	m_Grid[14][11].g_NodeType = Wall;
	m_Grid[15][11].g_NodeType = Wall;
	m_Grid[16][11].g_NodeType = Wall;
	m_Grid[17][11].g_NodeType = Wall;
	m_Grid[18][11].g_NodeType = Wall;
	m_Grid[19][11].g_NodeType = Wall;
	m_Grid[20][11].g_NodeType = Wall;
	m_Grid[21][11].g_NodeType = Wall;
	m_Grid[22][11].g_NodeType = Wall;
	m_Grid[25][11].g_NodeType = Wall;
	m_Grid[26][11].g_NodeType = Wall;
	m_Grid[32][11].g_NodeType = Wall;


	m_Grid[0][13].g_NodeType = Food;
	m_Grid[1][13].g_NodeType = Food;
	m_Grid[2][13].g_NodeType = Food;
	m_Grid[3][13].g_NodeType = Food;
	m_Grid[4][13].g_NodeType = Food;
	m_Grid[5][13].g_NodeType = Food;
	m_Grid[6][13].g_NodeType = Food;
	m_Grid[7][13].g_NodeType = Food;
	m_Grid[8][13].g_NodeType = Food;
	m_Grid[9][13].g_NodeType = Food;
	m_Grid[10][13].g_NodeType = Food;
	m_Grid[11][13].g_NodeType = Food;
	m_Grid[12][13].g_NodeType = Food;
	m_Grid[13][13].g_NodeType = Food;
	m_Grid[14][13].g_NodeType = Food;
	m_Grid[15][13].g_NodeType = Food;
	m_Grid[16][13].g_NodeType = Food;
	m_Grid[17][13].g_NodeType = Food;
	m_Grid[18][13].g_NodeType = Food;
	m_Grid[19][13].g_NodeType = Food;
	m_Grid[20][13].g_NodeType = Food;
	m_Grid[21][13].g_NodeType = Food;
	m_Grid[22][13].g_NodeType = Food;
	m_Grid[25][13].g_NodeType = Food;
	m_Grid[26][13].g_NodeType = Food;
	m_Grid[27][13].g_NodeType = Food;
	m_Grid[28][13].g_NodeType = Food;
	m_Grid[29][13].g_NodeType = Food;
	m_Grid[30][13].g_NodeType = Food;
	m_Grid[31][13].g_NodeType = Food;
	m_Grid[32][13].g_NodeType = Food;

	m_Grid[20][12].g_NodeType = Food;
	m_Grid[21][12].g_NodeType = Food;
	m_Grid[22][12].g_NodeType = Food;
	m_Grid[25][12].g_NodeType = Food;
	m_Grid[26][12].g_NodeType = Food;
	m_Grid[27][12].g_NodeType = Food;
	m_Grid[28][12].g_NodeType = Food;
	m_Grid[29][12].g_NodeType = Food;
	m_Grid[30][12].g_NodeType = Food;
	m_Grid[31][12].g_NodeType = Food;
	m_Grid[32][12].g_NodeType = Food;
}

void AIGrid::loadFromFile(const char* filePath)
{
	/*
	FILE* pLevelFile = fopen(filePath, "r");
	if (!pLevelFile)
	{
		printf("Error loading file \n");
		return;
	}

	const int kiBufferSize = 33;

	char cBuffer[256];
	double iBuffer[kiBufferSize];
	int iLineCount = 0;
	while (fscanf(pLevelFile, "%s", cBuffer) != EOF)
	{
		scanf(cBuffer, "%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d_%d", iBuffer[0], iBuffer[1], iBuffer[2], iBuffer[3], iBuffer[4], iBuffer[5], iBuffer[6], iBuffer[7], iBuffer[8], iBuffer[9], iBuffer[10], iBuffer[11], iBuffer[12], iBuffer[13], iBuffer[14], iBuffer[15],  iBuffer[16], iBuffer[17], iBuffer[18], iBuffer[19], iBuffer[20], iBuffer[21], iBuffer[22], iBuffer[23], iBuffer[24], iBuffer[25], iBuffer[26], iBuffer[27], iBuffer[28], iBuffer[29], iBuffer[30], iBuffer[31],  iBuffer[32]);
		if (iLineCount == 16)
			break;
		for (int x = 0; x < kiBufferSize; x++)
		{
			printf("%i ", iBuffer[x]);
			setNodeTypeOfNodeAtPosition(Vector2<int>(x, iLineCount), (NodeTypes)(int)iBuffer[x]);
		}
		printf("\n");
		iLineCount++;
	}

	fclose(pLevelFile);*/
}

bool AIGrid::isNodeAtPositionFood(Vector2<int> nodeNum) const
{
	if (m_Grid[nodeNum.x()][nodeNum.y()].g_NodeType == Food)
		return true;
	return false;
}

bool AIGrid::isNodeAtPositionWalkable(Vector2<int> nodeNum) const
{
	if (m_Grid[nodeNum.x()][nodeNum.y()].g_NodeType == Wall)
		return false;
	return true;
}

void AIGrid::foodAtPositionPickedUp(Vector2<int> nodeNum) 
{
	if (getNodeTypeOfNodeAtPosition(nodeNum) == Food) {
		setNodeTypeOfNodeAtPosition(nodeNum, Grass);
	}
}

Vector2<int> AIGrid::getClosestFood(Vector2<int> nodeNum)
{
	int iManhattenDistance = 0;
	Vector2<int> closestFoodLocation = Vector2<int>();
	for (unsigned int y = 0; y < getHeight(); y++) {
		for (unsigned int x = 0; x < getWidth(); x++) {
			Vector2<int> currentLoc = Vector2<int>(x, y);
			if (getNodeTypeOfNodeAtPosition(currentLoc) == Food)
			{
				if (iManhattenDistance == 0)
				{
					const int k_iXDist = abs(nodeNum.x() - currentLoc.x());
					const int k_iYDist = abs(nodeNum.y() - currentLoc.y());
					iManhattenDistance =  k_iXDist + k_iYDist;
					closestFoodLocation = currentLoc;
				} else {
					const int k_iXDist = abs(nodeNum.x() - currentLoc.x());
					const int k_iYDist = abs(nodeNum.y() - currentLoc.y());
					int tempDist =  k_iXDist + k_iYDist;
					if (tempDist < iManhattenDistance) {
						iManhattenDistance = tempDist;
						closestFoodLocation = currentLoc;
					}
				}
			}
		}
	}
	return closestFoodLocation;
}

NodeTypes AIGrid::getNodeTypeOfNodeAtPosition(Vector2<int> nodePos) const
{
	return m_Grid[nodePos.x()][nodePos.y()].g_NodeType;
}

void AIGrid::setNodeTypeOfNodeAtPosition(Vector2<int> nodePos, NodeTypes type)
{
	m_Grid[nodePos.x()][nodePos.y()].g_NodeType = type;
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

Vector2<int> AIGrid::getAntHillNode() const
{
	for (unsigned int y = 0; y < getHeight(); y++) {
		for (unsigned int x = 0; x < getWidth(); x++) {
			Vector2<int> nodePos = Vector2<int>(x,y);
			if (getNodeTypeOfNodeAtPosition(nodePos) == AntHill)
			{
				return nodePos;
			}
		}
	}
	return Vector2<int>(0,0);
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
			Vector2<float> pixelPosition = getPixelPosOfNodeTopLeft(nodePos);

			sf::RectangleShape newRect;
			newRect.setPosition(pixelPosition.x(), pixelPosition.y());
			newRect.setSize(sf::Vector2f(PATHFINDER_GRID_SIZE, PATHFINDER_GRID_SIZE));

			switch (getNodeTypeOfNodeAtPosition(nodePos))
			{
			case Wall:
				newRect.setFillColor(sf::Color::Magenta);
				target.draw(newRect);
				break;
			case Grass:
				newRect.setFillColor(sf::Color::Green);
				target.draw(newRect);
				break;
			case AntHill:
				newRect.setFillColor(sf::Color::Black);
				target.draw(newRect);
				break;
			case Food:
				newRect.setFillColor(sf::Color::Cyan);
				target.draw(newRect);
				break;
			default:
				break;
			}
		}
	}
}

AIGrid::~AIGrid()
{
}