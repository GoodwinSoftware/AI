#ifndef SCENE_H
#define SCENE_H

#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "SpriteManager.h"
#include "AntEater.h"
#include "Ant.h"
#include "Obsticle.h"
#include "Message.h"
#include "AIGrid.h"
#include "PathFinder.h"

class Scene 
{
private:
	static enum GameState{StartScreen, Running}; //!< Game States

	sf::RenderWindow m_Window; //!< Game Window
	sf::Clock m_gameTimer; //!< Game Timer
	sf::Time m_CurrentFrame; //!< Current Frame (as time)

	AIGrid m_AIGrid;
	Message TestMessage; //!< Messages
	PathFinder m_PathFinder; //!< Path Finder

	GameState m_GameState; //!< Gamestate
	Message StartScreenMessage, ScoreDisplay; //!< Messages

	int i_Score; //!< Score
	std::string s_Score; //!< Score display

	float m_fCurrentFrame; //!< Current frame (as float)
	float m_fAccumulator; //!< Time accumulator
    float m_fPreviousFrame; //!< Previous frame time
	float m_fPreviousAntSpawn; //!< Previous ant spwan time

	float m_fMarkTime; //!< Marks the time for ant eater
	float m_fMarkX[2], m_fMarkY[2]; //!< Marks the x and y position for ant eater movement
	bool bAntEater; //!< If ant eater is spawned = true


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