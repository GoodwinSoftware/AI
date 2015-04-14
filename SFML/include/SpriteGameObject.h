#ifndef SPRITE_GAMEOBJECT_H
#define SPRITE_GAMEOBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class  SpriteGameObject : public GameObject, public sf::Drawable
{
public:
	SpriteGameObject();
	~SpriteGameObject();

	void SetPosition(Vector2<float> newPos) { fPosition = newPos; };
	void SetPosition(float fnewX, float fnewY) { fPosition = Vector2<float>(fnewX, fnewY); };
	Vector2<float> getPosition() const { return fPosition; };
	Vector2<float> getPositionCenter() const { return fPosition + Vector2<float>(m_texture.getSize().x /2, m_texture.getSize().y/2); };

	void SetVelocity(Vector2<float> newVel) { fVelocity = newVel; };
	void SetVelocity(float fnewX, float fnewY) { fVelocity = Vector2<float>(fnewX, fnewY); };
	Vector2<float> getVelocity() const { return fVelocity; };

	void SetAngle(float fNewAngle) { fAngle = fNewAngle; };
	void AddAngle(float fNewAngle) { fAngle += fNewAngle; };
	float GetAngle() const { return fAngle; };

	void UpdateGraphics(); //!< Updates the graphics of the object
	void SetTexture(const sf::Texture& text); //!< Sets the texture of the object
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the Object

protected:

	void integrate();
	sf::Texture m_texture; //!< Sprite texture
	sf::Sprite m_Sprite; //!< Sprite of the game object
	Vector2<float> fPosition;
	Vector2<float> fVelocity;
	float fAngle;
};


#endif