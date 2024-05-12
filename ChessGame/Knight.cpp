#include <iostream>
#include "Knight.h"


// Notatka: wiele razy �adujemy t� sam� tekstur�;)

Knight::Knight(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, PAWN, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_knight_black;
	}
	else
	{
		m_texture = resources->texture_knight_white;
	}

	this->setTexture(m_texture);

}

void Knight::generate_move_space()
{
	m_attack_space.clear();
	m_movement_space.clear();

	// Nowe podejscie:
	std::array< sf::Vector2i, 8> moverules;

	moverules[0] = sf::Vector2i(m_xind+1, m_yind-2);
	moverules[1] = sf::Vector2i(m_xind-1, m_yind-2 );

	moverules[2] = sf::Vector2i(m_xind + 1, m_yind + 2);
	moverules[3] = sf::Vector2i(m_xind - 1, m_yind + 2);

	moverules[4] = sf::Vector2i(m_xind + 2, m_yind - 1);
	moverules[5] = sf::Vector2i(m_xind + 2, m_yind + 1);

	moverules[6] = sf::Vector2i(m_xind - 2, m_yind - 1);
	moverules[7] = sf::Vector2i(m_xind - 2, m_yind + 1);

	for (auto move : moverules)
	{
		// jesli ruch miesci sie w planszy
		if ((move.x >= 0) && (move.x < 8) && (move.y >= 0) && (move.y < 8))
		{
			// jesli na wybranym polu jest figura
			if (board->board_state[move.x + move.y * 8])
			{
				// gdy jest przeciwnikiem
				if (board->board_state[move.x + move.y * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(move);
				}
			}
			else
			{
				m_movement_space.emplace_back(move);
			}
		}	
	}
}

void Knight::ganerate_attack_space()
{
	;
}

