#pragma once

#include "Item.h"
#include <SFML/System.hpp>
#include <vector>
#include <random>
#include <Windows.h>

class ItemList
{
public:
	// Update
	void update(sf::VideoMode vm);
	// Render
	void render(sf::RenderWindow* window);

	// Starts the threads
	void visualizeShuffle();
	void visualizeSort();
	void stop();

	ItemList(sf::VideoMode vm, bool* shu, bool* sor, int t);
	~ItemList();
private:
	// Item List 
	std::vector<Item*> m_itemList;
	int m_nItem;
	void initList(sf::VideoMode vm);

	// Visualize 
	int m_time;
	void itemSelected(Item* a, Item* b);
	void itemMoved(Item* a, Item* b);

	// Shuffle
	void shuffle();
	bool* m_isShuffling;
	sf::Thread m_shuffle;

	// Sorting 
	void sort();
	bool* m_isSorting;
	sf::Thread m_sort;
};