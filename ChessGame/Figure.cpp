#include "Figure.h"
#include "SFML/Graphics.hpp"

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------
Figure::Figure(Team team, int xind, int yind, PieceType type, SFML_manager* graphics, Assets* resources, Board* board)
	: m_team(team), m_xind(xind), m_yind(yind), m_type(type), graphics(graphics), resources(resources), board(board)
{
	// Umieszczenie figury na planszy
	board->board_state[xind + yind * 8] = this;
}

void Figure::draw()
{
	graphics->window.draw(*this);
}

void Figure::update()
{
	// Sprawdzanie klikniecia
	if (this->getGlobalBounds().contains(static_cast<sf::Vector2f>(graphics->mousePosition)))
	{
		this->on_click();
	}


}

void Figure::on_click()
{
	this->setColor(sf::Color::Magenta);
}
