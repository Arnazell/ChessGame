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

	void drawFields();
	// Przechowuje informacje o stanie gry
	std::array<Figure*, 64> board_state;

	// Informacja o atakach na pole
	std::array<int, 64> white_fields;
	std::array<int, 64> black_fields;
	//Dostep do grafiki
	SFML_manager* graphics;

};