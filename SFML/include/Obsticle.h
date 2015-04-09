#ifndef OBSTICLE_H
#define OBSTICLE_H

#include "SpriteGameObject.h"

class Obsticle : public SpriteGameObject 
{
private:

public:
	Obsticle();
	Obsticle(sf::Texture textureIn); 
	~Obsticle();
};
#endif