#include "Obsticle.h"

Obsticle::Obsticle() 
{
	m_GameObjectType = ObsticleGO;
}

Obsticle::Obsticle(sf::Texture textureIn) 
{
	SetTexture(textureIn);
}

Obsticle::~Obsticle() 
{
}
