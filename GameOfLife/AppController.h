#pragma once
#include "SFML/Graphics.hpp"
#include "GameMenager.h"
class AppController
{
public:
	AppController();
	~AppController();
	void run();
	void processEvents();
	void update();
private:
	sf::RenderWindow window;
	void render();
	GameMenager *game;
};

