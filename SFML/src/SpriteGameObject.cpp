#include "SpriteGameObject.h"
#include "Config.h"
SpriteGameObject:: SpriteGameObject()
{
	fAngle = 0;
	fVelocity = Vector2<float>();
	fPosition = Vector2<float>();
}

 SpriteGameObject::~ SpriteGameObject()
{

}

 void SpriteGameObject::integrate() {
	 fPosition += fVelocity * UPDATE_INTERVAL;
 }

 void SpriteGameObject::UpdateGraphics() {
	 integrate();
	 m_Sprite.setPosition(fPosition.x(), WINDOW_HEIGHT - fPosition.y());
	 m_Sprite.setRotation(fAngle);
 }

 void SpriteGameObject::SetTexture(const sf::Texture& tex /*!< New texture */) //!< Sets the texture of the sprite
{
    m_texture = tex;
    m_Sprite.setTexture(m_texture);
    m_Sprite.setOrigin(m_texture.getSize().x /2, m_texture.getSize().y /2);
}


void SpriteGameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const //!< Draw the AntEater
{
	target.draw(m_Sprite);
}