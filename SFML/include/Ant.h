#ifndef ANT_H
#define ANT_H

#include "Character.h"

class Ant : public Character 
{
public:
	Ant();
	Ant(AIGrid* grid);
	Ant(sf::Texture& text);
	~Ant();
protected:
	bool m_bHasFood;
	virtual void CharacterLogic();
};

#endif