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

	SetupObjects();
	GameLoop();
}

Scene::~Scene() 
{
}

void Scene::AddAnt(float fX, float fY)
{
	m_aAnts.emplace_back(Ant());
	m_aAnts.back().SetPosition(fX, fY);
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
	AddAntEater(100, 50);

	// Messages
	TestMessage.SetMessage("Test1", sf::Color::Red, 32, WINDOW_WIDTH / 2, 40);
}

void Scene::GameLoop() 
{
	while (m_Window.isOpen()) 
	{
		InputEvent();

		// Timer
		const sf::Time kCurrentFrame = m_gameTimer.getElapsedTime();
        const float kfCurrentFrame = kCurrentFrame.asSeconds();
        m_fAccumulator += kfCurrentFrame - m_fPreviousFrame;
        m_fPreviousFrame = kfCurrentFrame;
    
        if (m_fAccumulator > 0.1) 
		{
            m_fAccumulator = 0.1f;
        }

        while (m_fAccumulator > UPDATE_INTERVAL)
		{
			UpdateObjects();
			m_fAccumulator -= UPDATE_INTERVAL;
        }

		m_Window.clear(sf::Color::White);

		DrawObjects();

		m_Window.display();
	}
}

void Scene::DrawObjects() 
{
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
	}

	//Update the ants
	for (auto i = m_aAnts.begin(); i != m_aAnts.end(); i++)
	{
		i->UpdateGraphics();
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
			m_aAnts[0].GoToPosition(Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
		} else if ((Event.type == sf::Event::MouseMoved))
		{
			m_aAnts[0].GoToPosition(Vector2<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
		}
	}
}