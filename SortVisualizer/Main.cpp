#include "Game.h"

int main()
{
	// Init Game
	Game game;

	// Game loop
	while (game.running())
	{
		// Events
		game.handleEvents();

		// Update
		game.update();

		// Render
		game.render();
	}

	// End
	return 0;
}