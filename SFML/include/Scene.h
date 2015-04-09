#ifndef SCENE_H
#define SCENE_H

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "SpriteManager.h"
#include "AntEater.h"
#include "Ant.h"
#include "Obsticle.h"
#include "Message.h"

class Scene 
{
private:
	sf::RenderWindow m_Window; //!< Game Window
	sf::Clock m_gameTimer; //!< Game Timer

	Message TestMessage; //!< Messages

	float m_fAccumulator; //!< Time accumulator
    float m_fPreviousFrame; //!< Previous frame time

	SpriteManager m_TextureManager; //!< Texture manager
	std::vector<AntEater> m_aAntEaters; //!< List of ant eaters
	std::vector<Ant> m_aAnts; //!< List of ants
	std::vector<Obsticle> m_aObsticles; //!< List of obsticles

	void AddAnt(float fX, float fY);
	void AddAntEater(float fX, float fY);
	void CheckDeadAnts();
	void DrawObjects();
	void UpdateObjects();
	void GameLoop();
	void InputEvent();
	void SetupObjects();

public:
	Scene();
	~Scene();
};

#endif