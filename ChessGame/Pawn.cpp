#include <iostream>
#include "Pawn.h"


// Notatka: wiele razy ładujemy tą samą teksturę;)

Pawn::Pawn(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, PAWN, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_pawn_black;
	}
	else
	{
		m_texture = resources->texture_pawn_white;
	}
	
	this->setTexture(m_texture);
	
}

void Pawn::generate_move_space()
{
	m_movement_space.clear();
	if (m_team== BLACK)
	{
		std::cout << "Nla";
		// generuj ruchy dla czarnych pionkow
		if (m_yind < 7)
		{
			if (board->board_state[m_xind + (m_yind + 1) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind + 1);
			}
		}
		if (m_yind < 6)
		{
			if (board->board_state[m_xind + (m_yind + 2) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind + 2);
			}
		}
	}
	else if (m_team == WHITE)
	{
		std::cout << "bialy";
		// generuj ruchy dla bialych pionkow
		if (m_yind > 0)
		{
			if (board->board_state[m_xind + (m_yind - 1) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind - 1);
			}
		}
		if (m_yind > 1)
		{
			if (board->board_state[m_xind + (m_yind - 2) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind - 2);
			}
		}
	}
}


