#pragma once
#include <SFML/Graphics.hpp>
#include "SFMLmanager.h"
#include "Assets.h"
#include "Board.h"


class Board;


// --------------------------------------------------------------------------------------
// Figura - klasa bazowa z ktorej dziedziczy kazda z figur szachowych
// --------------------------------------------------------------------------------------
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

	// generowanie ruchow
	virtual void generate_move_space();
	
	// ruch
	void move(int xind, int yind);

	// drukowanie ruchow
	void print_moves();

	// zajmowanie planszy
	void occupy_board();

	// odblokowywanie planszy
	void deocupy_board();

	// Interakcja
	void click();
	void unclick();

	bool clicked;
	

public:

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

	// przestrzen ruchow
	std::vector<sf::Vector2i> m_movement_space;

	// przestrzen ataku - ATAKOWANE FIGURY
	std::vector<sf::Vector2i> m_attack_space;

	// opcjonalna przestrzen ataku - mozliwe do zaatakowania pola (dla pionka)
	std::vector<sf::Vector2i> m_optional_attack_space;

	// Obraz
	sf::Texture m_texture;

};