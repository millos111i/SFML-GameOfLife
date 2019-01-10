#include "MatrixCell.h"



MatrixCell::MatrixCell(int positionX, int positionY, bool alive, std::vector<int> *liveNumber, std::vector<int> *deadNumber) :neighborsNumbers(0), liveNumber(liveNumber), deadNumber(deadNumber)
{
	this->alive = alive;
	rectangle = new sf::RectangleShape(sf::Vector2f{ _X,_Y });
	rectangle->setFillColor(sf::Color::White);
	rectangle->setPosition((float)positionX * _X, (float)positionY * _Y);
}


MatrixCell::~MatrixCell()
{
	delete rectangle;
}

void MatrixCell::setDead()
{
	alive = false;
	rectangle->setFillColor(sf::Color::White);
}

void MatrixCell::setAlive()
{
	alive = true;
	rectangle->setFillColor(sf::Color::Black);
}

bool MatrixCell::isAlive()
{
	return alive;
}

void MatrixCell::setNewState()
{
	alive = !alive;
	if (alive == false) {
		rectangle->setFillColor(sf::Color::White);
	}
	else {
		rectangle->setFillColor(sf::Color::Black);
	}
}

void MatrixCell::changeState()
{
	if (alive) {
		if (!liveContain(neighborsNumbers)) {
			alive = false;
			rectangle->setFillColor(sf::Color::White);
		}
	}
	else {
		if (deadContain(neighborsNumbers)) {
			alive = true;
			rectangle->setFillColor(sf::Color::Black);
		}
	}
}

void MatrixCell::addNeighbors(MatrixCell* neighbour)
{
	neighbors.push_back(neighbour);
}


void MatrixCell::update()
{
	neighborsNumbers = 0;
	for (auto n : neighbors) {
		if (n->alive) {
			neighborsNumbers++;
		}
	}
}

bool MatrixCell::liveContain(int n)
{
	for (auto i : (*liveNumber)) {
		if (i == n) return true;
	}
	return false;
}

bool MatrixCell::deadContain(int n)
{
	for (auto i : (*deadNumber)) {
		if (i == n) return true;
	}
	return false;
}

void MatrixCell::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(*rectangle);
}
