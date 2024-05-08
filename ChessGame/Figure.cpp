#include "Figure.h"
#include "SFML/Graphics.hpp"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------
Figure::Figure(Team team, int xind, int yind, PieceType type, SFML_manager* graphics)
	: m_team(team), m_xind(xind), m_yind(yind), m_type(type), graphics(graphics)
{

}
