#pragma once
#include "SFML_manager.h"
#include "Array"
#include "Figure.h"


class Figure;

class Board
{
public:
	// Konstruktor
	Board(SFML_manager* graphics);

	// Rysuj plansze
	void drawBoard();

	// Przechowuje informacje o stanie gry
	std::array<Figure*, 64> board_state;

	//Dostep do grafiki
	SFML_manager* graphics;

};