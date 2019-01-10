#include "AppController.h"
#include "DEFINITIONS.h"


AppController::AppController() : window({ SCREEN_WIDTH, SCREEN_HEIGHT }, "GameOfLife", sf::Style::Close | sf::Style::Titlebar)
{
	game = new GameMenager(&window);
	window.setFramerateLimit(FPS_LIMIT);
}


AppController::~AppController()
{
}

void AppController::run()
{
	while (window.isOpen()) {

		processEvents();
		update();
		render();
	}
}

void AppController::processEvents()
{
	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed)	window.close();
		game->eventHandler(evnt);
	}
}

void AppController::update()
{
	game->update();
}

void AppController::render()
{
	window.clear(sf::Color::Red);
	window.draw(*game);
	window.display();
}
