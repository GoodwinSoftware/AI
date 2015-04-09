#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

enum GameObjectType 
{
	UnassignedGO = 0,
	AntGO,
	CharacterGO,
	ObsticleGO,
	FoodGO,
	AntEaterGO,
};

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