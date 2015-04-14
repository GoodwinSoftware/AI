#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Config.h"
#include <memory>

class GameObject 
{
public:
	GameObject();
	~GameObject();
	GameObjectType getGameObjectType() const { return m_GameObjectType; };
protected:
	GameObjectType m_GameObjectType;
};

#endif GAMEOBJECT_H