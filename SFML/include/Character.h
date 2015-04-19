#ifndef CHARACTER_H
#define CHARACTER_H
#define _USE_MATH_DEFINES

#include "SpriteGameObject.h"
#include "math.h"
#include "AIGrid.h"
#include <cmath>
#include "Path.h"

class Character : public SpriteGameObject
{
public:
	Character(); //!< Default constructor
	Character(AIGrid* grid); //!< Default constructor

	~Character(); //!< Default destructor

	int GetHealth() const { return m_iHealth; }; //!< Returns the characters health
	void DamageCharacter(int iDamage) { m_iHealth -= iDamage; };  //!< Damages the character by an integer
	bool IsCharacterDead() const { if (m_iHealth <= 0) return true; else return false; }; //!< Returns true if the character is dead

	void SetNodePosition(Vector2<int> nodePos);

	void UpdateCharacterLogic();
	void setPath(Path newPath, Vector2<int> finalPos);
protected:
	bool m_bIsIdle;
	virtual void CharacterLogic() {};

	AIGrid* m_SearchGrid;

	int m_iHealth; //!< Character Health
	float m_fMovementSpeed; //!< Character movement speed
	Path m_Path;
	void GoToNode(Vector2<int> newDest);
	Vector2<int> m_DestinationNode; //!< Character destination vector
	Vector2<int> m_GoalDestinationNode; 
};

#endif