#include "Figure.h"
#include "SFML/Graphics.hpp"
#include <iostream>

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
	// gdy figura jest wybrana drukuj ruchy
	if (clicked)
	{
		for (auto el : m_movement_space)
		{
			std::cout << el.y;
		}
	}
}

void Figure::update()
{
	;
}

void Figure::print_moves()
{
	// Rysowanie kwadratów na podstawie tablicy indeksów
	sf::RectangleShape square(sf::Vector2f(128, 128));
	square.setFillColor(sf::Color::Green);
	for (auto move : m_movement_space)
	{
		square.setPosition(move.x * 128, move.y * 128);
		graphics->window.draw(square);
	}
}

void Figure::click()
{
	if (m_type != NONE)
	{
		setColor(sf::Color::Red);
		generate_move_space();
	}
	clicked = true;
}

void Figure::unclick()
{
	setColor(sf::Color::White);
	clicked = false;
}
