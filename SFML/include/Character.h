#ifndef CHARACTER_H
#define CHARACTER_H
#define _USE_MATH_DEFINES

#include "SpriteGameObject.h"
#include "math.h"
#include <cmath>

class Character : public SpriteGameObject
{
public:
	Character(); //!< Default constructor
	~Character(); //!< Default destructor

	int GetHealth() const { return m_iHealth; }; //!< Returns the characters health
	void DamageCharacter(int iDamage) { m_iHealth -= iDamage; };  //!< Damages the character by an integer
	bool IsCharacterDead() const { if (m_iHealth <= 0) return true; else return false; }; //!< Returns true if the character is dead

	void GoToPosition(Vector2<float> newDest);

	void UpdateCharacterLogic();
protected:
	int m_iHealth; //!< Character Health
	float m_fMovementSpeed; //!< Character movement speed

	Vector2<float> m_DestinationPosition; //!< Character destination vector
};

#endif