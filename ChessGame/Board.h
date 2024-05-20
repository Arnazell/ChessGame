#pragma once
#include "SFMLmanager.h"
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

	// Wyswietla stan planszy w konsoli (ilosc atakow na kazde pole)
	void drawFields();

	// Rodzaje figur
	enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN, EMPTY };

	// Przechowuje informacje o stanie gry
	std::array<Figure*, 64> board_state;

	// Informacja o atakach na pole
	std::array<int, 64> white_fields;
	std::array<int, 64> black_fields;

	// Informacja o szachu
	bool check;

	// sprawdz szach
	bool check_check();

	//Dostep do grafiki
	SFML_manager* graphics;

};