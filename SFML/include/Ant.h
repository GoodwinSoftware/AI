#ifndef ANT_H
#define ANT_H

#include "Character.h"

class Ant : public Character 
{
public:
	Ant();
	Ant(sf::Texture& text);
	~Ant();
};

#endif