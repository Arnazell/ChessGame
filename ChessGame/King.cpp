#include <iostream>
#include "King.h"


// Notatka: wiele razy ³adujemy t¹ sam¹ teksturê;)

King::King(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, KING, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_king_black;
	}
	else
	{
		m_texture = resources->texture_king_white;
	}

	this->setTexture(m_texture);

}

void King::generate_move_space()
{
	deocupy_board();
	m_attack_space.clear();
	m_movement_space.clear();

	// Nowe podejscie:
	std::array< sf::Vector2i, 8> moverules;

	moverules[0] = sf::Vector2i(m_xind - 1, m_yind + 1);
	moverules[1] = sf::Vector2i(m_xind, m_yind + 1);
	moverules[2] = sf::Vector2i(m_xind + 1, m_yind + 1);

	moverules[3] = sf::Vector2i(m_xind + 1, m_yind);
	moverules[4] = sf::Vector2i(m_xind - 1, m_yind);


	moverules[5] = sf::Vector2i(m_xind - 1, m_yind - 1);
	moverules[6] = sf::Vector2i(m_xind, m_yind - 1);
	moverules[7] = sf::Vector2i(m_xind +1, m_yind - 1);

	for (auto move : moverules)
	{
		// jesli ruch jest zgodny z zasadami
		if ((move.x >= 0) && (move.x <= 7) && (move.y >= 0) && (move.y <= 7))
		{
			// przy gnerowwawaniu uchoww wzglednij tylko te na niezajetych przez wroga polach
			bool friendly_area = true;
			if (this->m_team == WHITE)
			{
				if (board->black_fields[move.x + move.y * 8] != 0)
				{
					friendly_area = false;
				}
			}
			else if (this->m_team == BLACK)
			{
				if (board->white_fields[move.x + move.y * 8] != 0)
				{
					friendly_area = false;
				}
			}
			// jesli ruch nie wystawia krola na bicie - obszr jest bezpieczny
			if (friendly_area)
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
	occupy_board();
}

void King::ganerate_attack_space()
{
	;
}


