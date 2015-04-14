#include "Scene.h"
#include "Config.h"


Scene::Scene() 
{
	m_fAccumulator = 0.0f;
	m_fPreviousFrame = 0.0f;

	sf::ContextSettings windowSettings;
	windowSettings.antialiasingLevel = ANTIALIASING_LEVEL;
	m_Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), WINDOW_NAME, sf::Style::Default, windowSettings);
	m_TextureManager = SpriteManager();
	m_GameState = GameState::StartScreen;

	m_AIGrid = AIGrid();

	m_PathFinder = PathFinder(&m_AIGrid);
	SetupObjects();
	GameLoop();
}

Scene::~Scene() 
{
}

void Scene::AddAnt(float fX, float fY)
{
	m_aAnts.emplace_back(Ant(&m_AIGrid));
	m_aAnts.back().SetNodePosition(Vector2<int>(0,0));
	//m_aAnts.back().SetPosition(fX, fY);
	m_aAnts.back().SetVelocity(10, 10);
	m_aAnts.back().SetTexture(m_TextureManager.getTexture(ANT_IMAGE_NAME));
}

void Scene::AddAntEater(float fX, float fY)
{
	m_aAntEaters.emplace_back(AntEater());
	m_aAntEaters.back().SetPosition(fX, fY);
	m_aAntEaters.back().SetTexture(m_TextureManager.getTexture(ANTEATER_IMAGE_NAME));
}

void Scene::SetupObjects() 
{
	// Objects
	AddAnt(50, 50);
	m_PathFinder.CharacterToNode(&m_aAnts.back(),  Vector2<int>(5, 10));
	AddAntEater(100, 50);

	// Messages
	StartScreenMessage.SetMessage("Click To Start", sf::Color::Red, 32, WINDOW_WIDTH / 2 - 92, 40);

	// Variables
	bAntEater = false;
	m_fMarkTime = 0;
	m_fMarkX[0] = -100;
	m_fMarkY[0] = -100;
	i_Score = 0;
}

void Scene::GameLoop() 
{
	while (m_Window.isOpen()) 
	{
		InputEvent();
		m_Window.clear(sf::Color::White);

		if (m_GameState == GameState::StartScreen)
		{
			m_Window.draw(StartScreenMessage);
		}
		else if (m_GameState == GameState::Running)
		{
			// Timer
			m_CurrentFrame = m_gameTimer.getElapsedTime();
			// Timer
			m_CurrentFrame = m_gameTimer.getElapsedTime();
			m_fCurrentFrame = m_CurrentFrame.asSeconds();
			 m_fAccumulator += m_fCurrentFrame - m_fPreviousFrame;
			m_fPreviousFrame = m_fCurrentFrame;
    
			if (m_fAccumulator > 0.1) 
			{
				m_fAccumulator = 0.1f;
			}

			while (m_fAccumulator > UPDATE_INTERVAL)
			{
				UpdateObjects();
				m_fAccumulator -= UPDATE_INTERVAL;
			}

			DrawObjects();
			s_Score = static_cast<std::ostringstream*>( &(std::ostringstream() << i_Score) )->str();
			ScoreDisplay.SetMessage(s_Score, sf::Color::Blue, 32, 10, 10);
			m_Window.draw(ScoreDisplay);
		}
		m_Window.display();
	}
}

void Scene::DrawObjects() 
{
	m_Window.draw(m_AIGrid);
	//Draw the ant eaters
	for (auto i = m_aAntEaters.begin(); i != m_aAntEaters.end(); i++)
	{
		m_Window.draw(*i);
	}

	//Draw the ants
	for (auto i = m_aAnts.begin(); i != m_aAnts.end(); i++)
	{
		m_Window.draw(*i);
	}

	//Draw the obsticles
	for (auto i = m_aObsticles.begin(); i != m_aObsticles.end(); i++)
	{
		m_Window.draw(*i);
	}

	//Draw the example message
	m_Window.draw(TestMessage);
}

void Scene::CheckDeadAnts()
{
	for (auto i = m_aAnts.begin(); i != m_aAnts.end(); i++)
	{
		
	}
}

void Scene::UpdateObjects() 
{
	// Update the ant eaters
	for (auto i = m_aAntEaters.begin(); i != m_aAntEaters.end(); i++)
	{
		i->UpdateGraphics();
		if (m_fCurrentFrame - m_fMarkTime >= 4)
		{
			m_aAntEaters[0].SetPosition(Vector2<float>(-100, -100));
			bAntEater = false;
			m_fMarkX[0] = -100;
		}
		if (m_fMarkX[0] > 0)
		{
			if (m_fMarkX[0] < m_fMarkX[1])
			{
				m_fMarkX[0] += 1;
			}
			else if (m_fMarkX[0] > m_fMarkX[1])
			{
				m_fMarkX[0] -= 1;
			}
			if (m_fMarkY[0] < m_fMarkY[1])
			{
				m_fMarkY[0] += 1;
			}
			else if (m_fMarkY[0] > m_fMarkY[1])
			{
				m_fMarkY[0] -= 1;
			}
			m_aAntEaters[0].SetPosition(Vector2<float>(m_fMarkX[0], m_fMarkY[0]));
		}
	}

	//Update the ants
	for (auto i = m_aAnts.begin(); i != m_aAnts.end(); i++)
	{
		i->UpdateCharacterLogic();
	}
}

void Scene::InputEvent() 
{
	sf::Event Event;

	while (m_Window.pollEvent(Event))
	{
		if (Event.type == sf::Event::Closed) 
		{
			m_Window.close();
		} 
		else if ((Event.type == sf::Event::KeyPressed)) 
		{
			if (Event.key.code == sf::Keyboard::Escape) 
			{
				m_Window.close();
			}
		} else if ((Event.type == sf::Event::MouseButtonPressed))
		{
			if (m_GameState == GameState::Running)
			{
				if (bAntEater == false)
				{
					m_aAntEaters[0].SetPosition(Vector2<float>(sf::Mouse::getPosition().x - 400, sf::Mouse::getPosition().y - 280));
					m_fMarkX[0] = sf::Mouse::getPosition().x - 400; 
					m_fMarkY[0] = sf::Mouse::getPosition().y - 280;
					m_fMarkTime = m_fCurrentFrame;
					bAntEater = true;
				}

				m_fMarkX[1] = sf::Mouse::getPosition().x - 400; 
				m_fMarkY[1] = sf::Mouse::getPosition().y - 280;
			}
			else if (m_GameState == GameState::StartScreen)
			{
				m_GameState = GameState::Running;
			}
		} else if ((Event.type == sf::Event::MouseMoved))
		{
			//m_aAnts[0].GoToPosition(Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
		}
	}
}