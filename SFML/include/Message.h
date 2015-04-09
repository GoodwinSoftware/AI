#ifndef MESSAGE_H
#define MESSAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Message : public sf::Drawable
{
private:

	sf::Font FontOpenSans; //!< Fonts (add more if you want)
	sf::Text TextMessage; //!< The message (you only need one really I think)

public:
	Message();

	void SetMessage(std::string sMessage, sf::Color mColour, unsigned int iSize, float fxPosition, float fyPosition); //!< Sets the message string, font, colour, size and position

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draws the message	
};

#endif