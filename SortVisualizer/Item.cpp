#include "Item.h"

// Update
void Item::update(sf::Vector2f pos)
{
	/*
		Update the item position
	*/
	this->m_itemBlock.setPosition(pos);
}
// Render
void Item::render(sf::RenderWindow* window)
{
	/*
		Draw the item
	*/
	window->draw(this->m_itemBlock);
}

// Get functions
int Item::getItemNumber()
{
	/*
		Return the number of the element
	*/

	return this->m_itemNumber;
}

// Set functions
void Item::setColor(sf::Color color)
{
	/*
		Set the color of the element
	*/

	this->m_itemBlock.setFillColor(color);
}

// ////////////////////////////////////////////////
Item::Item(sf::Vector2f size, sf::Vector2f pos, int n)
{
	/*
		Initialize the variables of the item
		Initialize the outline thickness and color, the color of the item and the size
		Initialize the origin of the item on is bottom left point and set the position
		Initialize the number of the item
	*/
	this->m_itemBlock.setOutlineThickness(0.5f);
	this->m_itemBlock.setOutlineColor(sf::Color::White);
	this->m_itemBlock.setFillColor(sf::Color::Green);
	this->m_itemBlock.setSize(size);

	this->m_itemBlock.setOrigin(sf::Vector2f(this->m_itemBlock.getPosition().x, this->m_itemBlock.getPosition().x + this->m_itemBlock.getSize().y));
	this->m_itemBlock.setPosition(pos);
	
	this->m_itemNumber = n;
}
// ////////////////////////////////////////////////