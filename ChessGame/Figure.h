#pragma once
#include <SFML/Graphics.hpp>
#include "SFML_manager.h"
#include "Assets.h"
#include "Board.h"

// --------------------------------------------------------------------------------------
// Figura - klasa bazowa z ktorej dziedziczy kazda z figur szachowych
// --------------------------------------------------------------------------------------

class Board;

class Figure : public sf::Sprite
{
public:

	const int SIZE = 128;

	enum Team { BLACK, WHITE, NONE };

	enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN, EMPTY };

	enum MoveType { NORMAL, CASTLE, ENPASSANT, NEWPIECE, INIT };


	// Konstruktor
	Figure(Team team, int xind, int yind, PieceType type, SFML_manager* graphics, Assets* resources, Board* board);

	// Destruktor

	// Wyswietlanie
	virtual void draw();

	// aktualizowanie
	virtual void update();

	// Interakcja
	void on_click();
	bool clicked = false;



protected:

	// Dostep do grafiki
	SFML_manager* graphics;

	// Dostep do zasobow
	Assets* resources;

	// Dostep do planszy
	Board* board;

	// Druzyna
	Team m_team;

	// Typ figury
	PieceType m_type;

	// Pozycja na mapie
	unsigned int m_xind;
	unsigned int m_yind;

	// Obraz
	sf::Texture m_texture;

};