#pragma once
#include "SFML/Graphics.hpp"
#include "Matrix.h"
#include "DEFINITIONS.h"
#include <vector>

class GameMenager : public sf::Drawable
{
public:
	GameMenager(sf::RenderWindow *window);
	~GameMenager();
	void init();
	void eventHandler(sf::Event evnt);
	void simulate();
	void update();
	void parser(std::string rules);
private:
	std::string rules;
	std::vector<int> liveNumber;
	std::vector<int> deadNumber;
	Matrix *matrix;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
	int pause;
	sf::RenderWindow *window;
};

