#include "Message.h"

Message::Message()
{
	if (!FontOpenSans.loadFromFile("fonts/OpenSans.ttf"))
	{
		std::cout<<"FONT ERROR: Font file OpenSans.ttf could not be loaded."<<std::endl;
	}
}

void Message::SetMessage(std::string sMessage, sf::Color mColour, unsigned int iSize, float fxPosition, float fyPosition)
{
	// Message
	TextMessage.setString(sMessage);
	TextMessage.setFont(FontOpenSans);
	TextMessage.setColor(mColour); // black, white, red, green, blue, yellow, magenta, cyan, transparent (black) || Color::Color(red, green, blue, alpha) all ranging from 0 to 255
	TextMessage.setCharacterSize(iSize);
	TextMessage.setPosition(fxPosition, fyPosition); 
}

void Message::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(TextMessage);
}
