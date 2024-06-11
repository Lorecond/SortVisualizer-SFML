#pragma once

#include "ItemList.h"

class Game
{
public:
	/*
		Game loop
	*/
	// Running
	const bool running() const;
	// Events
	void handleEvents();
	// Update
	void update();
	// Render
	void render();

	Game();
	~Game();

private:
	// Window
	sf::RenderWindow* m_window;
	sf::VideoMode m_videoMode;
	sf::Event* m_event;
	void initWindow();

	// List of item
	ItemList* m_itemList;
	bool m_isShuffling;
	bool m_isSorting;
	void initList();
};