#include "GameMenager.h"



GameMenager::GameMenager(sf::RenderWindow *window) : pause(0), window(window)
{
	init();
	parser(_RULES);
}


GameMenager::~GameMenager()
{
}

void GameMenager::init()
{
	matrix = new Matrix(&liveNumber, &deadNumber, window);
	matrix->initCell();
}

void GameMenager::eventHandler(sf::Event evnt)
{
	if (evnt.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pause++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			pause = 0;
			matrix->randomizeState();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			pause = 0;
			matrix->setDefaultStates();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			pause = 0;
		}
	}
	if (evnt.type == sf::Event::MouseButtonPressed) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			matrix->changeOnClick(*window);
		}
	}
}

void GameMenager::simulate()
{
	matrix->update();
}

void GameMenager::update()
{
	if (pause > 0)
		simulate();
}

void GameMenager::parser(std::string rules)
{
	liveNumber.clear();
	deadNumber.clear();
	std::string separator = "/";
	unsigned int position = rules.find(separator);
	for (int i = 0; i < position; i++) {
		int n = rules[i] - '0';
		liveNumber.push_back(n);
	}
	for (int i = rules.length() - 1; i > position; i--) {
		int n = rules[i] - '0';
		deadNumber.push_back(n);
	}

}

void GameMenager::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*matrix);
}
