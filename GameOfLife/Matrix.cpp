#include "Matrix.h"



Matrix::Matrix(std::vector<int> *liveNumber, std::vector<int> *deadNumber, sf::RenderWindow *window) : liveNumber(liveNumber), deadNumber(deadNumber), window (window)
{
}


Matrix::~Matrix()
{
}

void Matrix::initCell()
{
	srand(time(NULL));
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			MatrixCell* cell = new MatrixCell(i, j, false, liveNumber, deadNumber);
			vCells[i][j] = cell;
		}
	}
	setNeighbors();
}

void Matrix::randomizeState()
{
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			bool random = rand() % 2;
			if (random == false) vCells[i][j]->setAlive();
			else vCells[i][j]->setDead();
			vCells[i][j]->setNewState();
		}
	}
}

void Matrix::setNeighbors()
{
	for (int x = 0; x < _ROWS; x++) {
		for (int y = 0; y < _COLS; y++) {
			if (x != 0 && x != _ROWS - 1) {
				if (y != 0 && y != _COLS - 1) {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y - 1]);
				}
				else if (y == 0) {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y + 1]);
				}
				else {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y - 1]);
				}
			}
			else if (x == 0) {
				if (y != 0 && y != _COLS - 1) {
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y - 1]);
				}
				else if (y == 0) {
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y + 1]);
				}
				else {
					vCells[x][y]->addNeighbors(vCells[x + 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x + 1][y - 1]);
				}
			}
			else {
				if (y != 0 && y != _COLS - 1) {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y - 1]);
				}
				else if (y == 0) {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y + 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y + 1]);
				}
				else {
					vCells[x][y]->addNeighbors(vCells[x - 1][y]);
					vCells[x][y]->addNeighbors(vCells[x][y - 1]);
					vCells[x][y]->addNeighbors(vCells[x - 1][y - 1]);
				}
			}
		}
	}
}

void Matrix::update()
{
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			vCells[i][j]->update();
		}
	}
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			vCells[i][j]->changeState();
		}
	}
}

void Matrix::setDefaultStates()
{
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			vCells[i][j]->setDead();
		}
	}
}

void Matrix::changeOnClick(sf::RenderWindow &window)
{
	int mouseX = sf::Mouse::getPosition(window).x/_X;
	int mouseY = sf::Mouse::getPosition(window).y/_Y;
	if (mouseX >= 0 && mouseX < _ROWS) {
		if (mouseY >= 0 && mouseY < _COLS) {
			vCells[mouseX][mouseY]->setNewState();
		}
	}
}


void Matrix::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	for (unsigned int i = 0; i < _ROWS; i++) {
		for (unsigned int j = 0; j < _COLS; j++) {
			target.draw(*vCells[i][j]);
		}
	}
}
