#pragma once
#include "MatrixCell.h"
#include "SFML/Graphics.hpp"
#include "MatrixCell.h"
#include "DEFINITIONS.h"



class Matrix : public sf::Drawable
{
public:
	Matrix(std::vector<int> *liveNumber, std::vector<int> *deadNumber, sf::RenderWindow *window);
	~Matrix();
	void initCell();
	void randomizeState();
	void setNeighbors();
	void update();
	void setDefaultStates();
	void changeOnClick(sf::RenderWindow &window);

private:
	std::vector<int> *liveNumber;
	std::vector<int> *deadNumber;
	MatrixCell *vCells[_ROWS][_COLS];
	virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
	sf::RenderWindow *window;
};

