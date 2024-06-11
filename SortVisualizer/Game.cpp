#include "Game.h"

// Running
const bool Game::running() const
{
	return this->m_window->isOpen();
}
// Events
void Game::handleEvents()
{
	/*
		imput manager responsible for closing the window
	*/
	while (this->m_window->pollEvent(*this->m_event))
	{
		switch (this->m_event->type)
		{
		case sf::Event::Closed:
			this->m_window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->m_event->key.code == sf::Keyboard::Escape)
				this->m_window->close();
			break;
		}

		/*
			Other imput event
			F1 = shuffle
			F2 = sort
			F3 stop
		*/
		switch (this->m_event->type)
		{
		case sf::Event::KeyPressed:
			if (this->m_event->key.code == sf::Keyboard::F1)
			{
				if (!this->m_isShuffling && !this->m_isSorting)
				{
					this->m_isShuffling = true;
					this->m_itemList->visualizeShuffle();
				}
			}
			if (this->m_event->key.code == sf::Keyboard::F2)
			{
				if (!this->m_isShuffling && !this->m_isSorting)
				{
					this->m_isSorting = true;
					this->m_itemList->visualizeSort();
				}
			}
			if (this->m_event->key.code == sf::Keyboard::F3)
				this->m_itemList->stop();
			break;
		}
	}
}
// Update
void Game::update()
{
	this->m_itemList->update(this->m_videoMode);
}
// Render
void Game::render()
{
	// Clears the screen
	this->m_window->clear(sf::Color::Black);

	// Draws on the screen
	this->m_itemList->render(this->m_window);

	// Displays the objects on the screen
	this->m_window->display();
}

// ////////////////////////////////////////////////
Game::Game()
{
	/*
		Initialize the Game Variables
	*/

	// Window
	this->initWindow();

	// List
	this->initList();
}
Game::~Game()
{
	/*
		Delete the dynamically allocated memory
	*/

	// Window
	delete this->m_window;
	// Event
	delete this->m_event;
	// List
	delete this->m_itemList;
}
// ////////////////////////////////////////////////

// Init window
void Game::initWindow()
{
	/*
		Initialize variables for window and events
	*/
	this->m_videoMode.width = 1200;
	this->m_videoMode.height = 800;

	this->m_window = new sf::RenderWindow(this->m_videoMode, "SortVisualizer", sf::Style::Close);
	this->m_window->setFramerateLimit(60);

	this->m_event = new sf::Event;
}

// Init list
void Game::initList()
{
	/*
		Initialize variables for list
	*/
	this->m_itemList = new ItemList(this->m_videoMode, &this->m_isShuffling, &this->m_isSorting, 10, 100);

	this->m_isShuffling = false;
	this->m_isSorting = false;
}
