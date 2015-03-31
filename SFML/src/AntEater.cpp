#include "AntEater.h"

AntEater::AntEater()
{
	m_GameObjectType = AntEaterGO;
}

AntEater::AntEater(sf::Texture texture)
{
	m_GameObjectType = AntEaterGO;
	SetTexture(texture);
}

AntEater::~AntEater()
{

}