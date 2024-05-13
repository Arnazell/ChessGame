#include "Figure.h"
#include "SFML/Graphics.hpp"
#include <iostream>

// --------------------------------------------------------------------------------------
// Konstruktor
// --------------------------------------------------------------------------------------
Figure::Figure(Team team, int xind, int yind, PieceType type, SFML_manager* graphics, Assets* resources, Board* board)
	: m_team(team), m_xind(xind), m_yind(yind), m_type(type), graphics(graphics), resources(resources), board(board), clicked(false)
{
	// Umieszczenie figury na planszy
	board->board_state[xind + yind * 8] = this;
}

void Figure::draw()
{
	graphics->window.draw(*this);
	// gdy figura jest wybrana drukuj ruchy
}

void Figure::update()
{
	;
}

void Figure::generate_move_space()
{
	;
}

void Figure::move(int xind, int yind)
{
	// ustaw bierzace pole na planszy na null
	board->board_state[m_xind + m_yind * 8] = nullptr;
	
	m_xind = xind;
	m_yind = yind;

	setPosition(xind * 128, yind * 128);
	board->board_state[m_xind + m_yind * 8] = this;

	// odswiez wszystkei pionki
	for (auto figure : board->board_state)
	{
		if (figure)
		{
			figure->generate_move_space();
		}
	}
}

void Figure::print_moves()
{
	// Rysowanie kwadratów na podstawie tablicy indeksów
	sf::RectangleShape movesquare(sf::Vector2f(128, 128));
	sf::RectangleShape attacksquare(sf::Vector2f(128, 128));


	movesquare.setFillColor(sf::Color::Yellow);
	attacksquare.setFillColor(sf::Color::Red);

	for (auto move : m_movement_space)
	{
		movesquare.setPosition(move.x * 128, move.y * 128);
		graphics->window.draw(movesquare);
	}

	
	for (auto attack : m_attack_space)
	{
		attacksquare.setPosition(attack.x * 128, attack.y * 128);
		graphics->window.draw(attacksquare);
	}

}

void Figure::occupy_board()
{
	if (this->m_team == WHITE)
	{
		// zajmij ruchy (jesli to pionek to nie)
		if (this->m_type != PAWN)
		{
			for (auto move : m_movement_space)
			{
				board->white_fields[move.x + move.y * 8]++;
			}
		}
		else if (this->m_type == PAWN)
		{
			for (auto optionalatack : m_optional_attack_space)
			{
				board->white_fields[optionalatack.x + optionalatack.y * 8]++;
			}
		}
		// zajmij ataki
		for (auto attack : m_attack_space)
		{
			board->white_fields[attack.x + attack.y * 8]++;
		}
		//system("cls");
		board->drawFields();
	}
	else
	{
		// zajmij ruchy
		if (this->m_type != PAWN)
		{
			for (auto move : m_movement_space)
			{
				board->black_fields[move.x + move.y * 8]++;
			}
		}
		else if (this->m_type == PAWN)
		{
			for (auto optionalatack : m_optional_attack_space)
			{
				board->black_fields[optionalatack.x + optionalatack.y * 8]++;
			}
		}
		// zajmij ataki
		for (auto attack : m_attack_space)
		{
			board->black_fields[attack.x + attack.y * 8]++;
		}
		//system("cls");
		board->drawFields();
	}
}

void Figure::deocupy_board()
{
	if (this->m_team == WHITE)
	{
		// ZWOLNIJ ruchy
		if (this->m_type != PAWN)
		{
			for (auto move : m_movement_space)
			{
				board->white_fields[move.x + move.y * 8]--;
			}
		}
		else if (this->m_type == PAWN)
		{
			for (auto optionalatack : m_optional_attack_space)
			{
				board->white_fields[optionalatack.x + optionalatack.y * 8]--;
			}
		}
		// zajmij ataki
		for (auto attack : m_attack_space)
		{
			board->white_fields[attack.x + attack.y * 8]--;
		}
		//system("cls");
		board->drawFields();
	}
	else
	{
		// zajmij ruchy
		if (this->m_type != PAWN)
		{
			for (auto move : m_movement_space)
			{
				board->black_fields[move.x + move.y * 8]--;
			}
		}
		else if (this->m_type == PAWN)
		{
			for (auto optionalatack : m_optional_attack_space)
			{
				board->black_fields[optionalatack.x + optionalatack.y * 8]--;
			}
		}

		// zajmij ataki
		for (auto attack : m_attack_space)
		{
			board->black_fields[attack.x + attack.y * 8]--;
		}
		//system("cls");
		board->drawFields();
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
