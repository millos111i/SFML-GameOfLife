#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"
#include<vector>

class MatrixCell: public sf::Drawable
{
public:
	MatrixCell(int positionX, int positionY, bool alive, std::vector<int> *liveNumber, std::vector<int> *deadNumber);
	~MatrixCell();
	void setDead();
	void setAlive();
	bool isAlive();
	void setNewState();
	void changeState();
	void addNeighbors(MatrixCell *neighbors);
	void update();

private:
	std::vector<int> *liveNumber;
	std::vector<int> *deadNumber;
	bool liveContain(int n);
	bool deadContain(int n);
	int neighborsNumbers;
	std::vector<MatrixCell*> neighbors;
	bool alive;
	sf::RectangleShape *rectangle;
	sf::Color color;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
};

