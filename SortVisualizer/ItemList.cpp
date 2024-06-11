#include "ItemList.h"

// Update
void ItemList::update(sf::VideoMode vm)
{
	/*
		Update the position of each element based on the position on the list
	*/
	for (int i = 0; i < this->m_nItem; i++)
	{
		this->m_itemList[i]->update(sf::Vector2f(i * (vm.width / this->m_nItem), vm.height));
	}
}
// Render
void ItemList::render(sf::RenderWindow* window)
{
	/*
		Render every item of the list
	*/
	for (auto& i : this->m_itemList)
	{
		i->render(window);
	}
}

// Starts the threads
void ItemList::visualizeShuffle()
{
	this->m_shuffle.launch();
}
void ItemList::visualizeSort()
{
	this->m_sort.launch();
}
void ItemList::stop()
{
	this->m_shuffle.terminate();
	this->m_sort.terminate();

	*this->m_isShuffling = false;
	*this->m_isSorting = false;
}

// ////////////////////////////////////////////////
ItemList::ItemList(sf::VideoMode vm, bool* shu, bool* sor, int t)
	: m_shuffle(&ItemList::shuffle, this), m_sort(&ItemList::sort, this), m_time(t)
{
	/*
		Initialize the variables and the threads
	*/
	this->initList(vm);
	this->m_isShuffling = shu;
	this->m_isSorting = sor;
}
ItemList::~ItemList()
{
	for (auto& i : this->m_itemList)
	{
		delete i;
	}
}
// ////////////////////////////////////////////////

// Init
void ItemList::initList(sf::VideoMode vm)
{
	/*
		Initialize the list
	*/
	this->m_nItem = 200;

	sf::Vector2f d;

	d.x = vm.width / this->m_nItem;
	d.y = vm.height / this->m_nItem;


	for (int i = 0; i < this->m_nItem; i++)
	{
		this->m_itemList.push_back(new Item(sf::Vector2f(d.x - 0.5, d.y + i * d.y), sf::Vector2f(i * d.x, vm.height), i));
	}
}

// Shuffle
void ItemList::shuffle()
{
	/*
		Swap every item of the list with an other random item of the list
	*/

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, this->m_nItem - 1);
	int r;

	for (int i = 0; i < this->m_nItem; i++)
	{
		r = dis(gen);
		
		std::swap(this->m_itemList[i], this->m_itemList[r]);

		// Visualize the moved elements by changing their color to red
		this->itemMoved(this->m_itemList[i], this->m_itemList[r]);
	}	

	// End
	*this->m_isShuffling = false;
}

// Sorting 
void ItemList::sort()
{
	/*
		Sorting algorithm
	*/

	std::vector<Item*> temp(this->m_nItem);

	for (int i = 0; i < this->m_nItem; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < this->m_nItem; j++)
		{
			// Visualize the selected elements by changing their color to blue
			this->itemSelected(this->m_itemList[j], this->m_itemList[minIndex]);;

			if (this->m_itemList[j]->getItemNumber() < this->m_itemList[minIndex]->getItemNumber())
				minIndex = j;
		}
		temp[i] = this->m_itemList[minIndex];

		std::swap(this->m_itemList[minIndex], this->m_itemList[i]);

		// Visualize the moved elements by changing their color to red
		this->itemMoved(this->m_itemList[minIndex], this->m_itemList[i]);
	}
	this->m_itemList.swap(temp);

	// End
	*this->m_isSorting = false;
}

// Visualize
void ItemList::itemSelected(Item* a, Item* b)
{
	// Set their color to blue
	a->setColor(sf::Color::Blue);
	b->setColor(sf::Color::Blue);

	// Wait so it can be seen
	Sleep(m_time);

	// Set their color to default, green
	a->setColor(sf::Color::Green);
	b->setColor(sf::Color::Green);
}
void ItemList::itemMoved(Item* a, Item* b)
{
	// Set their color to red
	a->setColor(sf::Color::Red);
	b->setColor(sf::Color::Red);

	// Wait so it can be seen
	Sleep(m_time);

	// Set their color to default, green
	a->setColor(sf::Color::Green);
	b->setColor(sf::Color::Green);
}
