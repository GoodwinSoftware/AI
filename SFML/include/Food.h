#ifndef FOOD_H
#define FOOD_H

#include "SpriteGameObject.h"

class Food : public SpriteGameObject 
{
public:
	Food();
	Food(sf::Texture textureIn);
	~Food();
};

#endif