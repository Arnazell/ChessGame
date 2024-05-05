#include "Figure.h"
#include "SFML/Graphics.hpp"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------
Figure::Figure(Team team, unsigned int xpos, unsigned int ypos, PieceType type)
	: m_team(team), m_xpos(xpos), m_ypos(ypos), m_type(type)
{

}
