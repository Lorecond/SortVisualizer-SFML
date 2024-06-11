#pragma once

#include <SFML\Graphics.hpp>

class Item
{
public:
	// Update
	void update(sf::Vector2f pos);
	// Render
	void render(sf::RenderWindow* window);

	// Get functions
	int getItemNumber();

	// Set functions
	void setColor(sf::Color color);

	Item(sf::Vector2f size, sf::Vector2f pos, int n);

private:
	// Item variables
	sf::RectangleShape m_itemBlock;
	int m_itemNumber;
};