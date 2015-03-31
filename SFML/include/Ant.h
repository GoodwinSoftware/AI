#ifndef ANT_H
#define ANT_H

#include "SpriteGameObject.h"

class Ant : public SpriteGameObject {
public:
	Ant();
	Ant(sf::Texture& text);
	~Ant();
};

#endif