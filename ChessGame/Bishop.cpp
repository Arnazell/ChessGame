#include <iostream>
#include "Bishop.h"


// Notatka: wiele razy ³adujemy t¹ sam¹ teksturê;)

Bishop::Bishop(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, BISHOP, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_bishop_black;
	}
	else
	{
		m_texture = resources->texture_bishop_white;
	}

	this->setTexture(m_texture);

}

void Bishop::generate_move_space()
{
	deocupy_board();
	m_movement_space.clear();
	m_attack_space.clear();
	

	// generuj na lewo w gore
	for (int x = m_xind - 1, y = m_yind - 1; (x >= 0 && y >= 0); x--, y--)
	{
		// jesli na danym polu stala figura
		if (board->board_state[x + y * 8])
		{
			// zaatakuj gdy byla obca
			if (board->board_state[x + y * 8]->m_team != m_team)
			{
				m_attack_space.emplace_back(x, y);
			}
			break;
		}
		else
		{
			m_movement_space.emplace_back(x, y);
		}
	}


	// generuj na prawo w gore
	for (int x = m_xind + 1, y = m_yind - 1; (x >= 0 && y >= 0); x++, y--)
	{
		// jesli na danym polu stala figura
		if (board->board_state[x + y * 8])
		{
			// zaatakuj gdy byla obca
			if (board->board_state[x + y * 8]->m_team != m_team)
			{
				m_attack_space.emplace_back(x, y);
			}
			break;
		}
		else
		{
			m_movement_space.emplace_back(x, y);
		}
	}

	// generuj na prawo w dol
		for (int x = m_xind + 1, y = m_yind + 1; (x <= 7 && y <= 7); x++, y++)
		{
			// jesli na danym polu stala figura
			if (board->board_state[x + y * 8])
			{
				// zaatakuj gdy byla obca
				if (board->board_state[x + y * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(x, y);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(x, y);
			}
		}


		// generuj na lewo w dol
		for (int x = m_xind - 1, y = m_yind + 1; (x <= 7 && y <= 7); x--, y++)
		{
			// jesli na danym polu stala figura
			if (board->board_state[x + y * 8])
			{
				// zaatakuj gdy byla obca
				if (board->board_state[x + y * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(x, y);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(x, y);
			}
		}
		occupy_board();
}

void Bishop::ganerate_attack_space()
{
	;
}


