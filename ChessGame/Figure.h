#pragma once
#include <SFML/Graphics.hpp>


// --------------------------------------------------------------------------------------
// Figura - klasa bazowa z ktorej dziedziczy kazda z figur szachowych
//
// --------------------------------------------------------------------------------------
class Figure : public sf::Sprite
{
public:

	enum Team { BLACK, WHITE, NONE };

	enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN, EMPTY };

	enum MoveType { NORMAL, CASTLE, ENPASSANT, NEWPIECE, INIT };

	// Konstruktor
	Figure(Team team, unsigned int xpos, unsigned int ypos, PieceType type);

	// Destruktor

protected:
	// Druzyna
	Team m_team;

	// Typ figury
	PieceType m_type;

	// Pozycja na mapie
	unsigned int m_xpos;
	unsigned int m_ypos;

	// Teksruta figury
	sf::Texture m_Texture;

	// Zajmowany obszar
	sf::IntRect m_Rect;

	// 
	// Przestrzen mozliwych ruchow




};