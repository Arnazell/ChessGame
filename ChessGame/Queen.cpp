#include <iostream>
#include "Queen.h"


// Notatka: wiele razy ³adujemy t¹ sam¹ teksturê;)

Queen::Queen(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, QUEEN, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_queen_black;
	}
	else
	{
		m_texture = resources->texture_queen_white;
	}

	this->setTexture(m_texture);


}

void Queen::generate_move_space()
{
	deocupy_board();
	m_movement_space.clear();
	m_attack_space.clear();

	// Generuj tak jak dla wiezy
	{
		// generuj ruchy w gore
		for (int i = (m_yind - 1); i >= 0; i--)
		{
			// jesli napotkasz pionka zakoncz generowanie
			if (board->board_state[m_xind + i * 8])
			{
				// jesli byl to przeciwnik dodaj go do przestrzeni ataku
				if (board->board_state[m_xind + i * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(m_xind, i);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(m_xind, i);
			}
		}

		// generuj ruchy w dol
		for (int i = (m_yind + 1); i <= 7; i++)
		{
			// jesli napotkasz pionka zakoncz generowanie
			if (board->board_state[m_xind + i * 8])
			{
				// jesli byl to przeciwnik dodaj go do przestrzeni ataku
				if (board->board_state[m_xind + i * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(m_xind, i);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(m_xind, i);
			}
		}

		// generuj ruchy w lewo
		for (int i = (m_xind - 1); i >= 0; i--)
		{
			// jesli napotkasz pionka zakoncz generowanie
			if (board->board_state[i + m_yind * 8])
			{
				// jesli byl to przeciwnik dodaj go do przestrzeni ataku
				if (board->board_state[i + m_yind * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(i, m_yind);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(i, m_yind);
			}
		}

		// generuj ruchy w prawo
		for (int i = (m_xind + 1); i <= 7; i++)
		{
			// jesli napotkasz pionka zakoncz generowanie
			if (board->board_state[i + m_yind * 8])
			{
				// jesli byl to przeciwnik to dodaj ruch do przestrzeni atakow
				if (board->board_state[i + m_yind * 8]->m_team != m_team)
				{
					m_attack_space.emplace_back(i, m_yind);
				}
				break;
			}
			else
			{
				m_movement_space.emplace_back(i, m_yind);
			}
		}
	}

	// Generuj tak jak dla goñca
	{
		// generuj na lewo w gore
		for (int x = m_xind - 1, y = m_yind - 1; (x >= 0 && x <= 7 && y >= 0 && y <= 7); x--, y--)
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
		for (int x = m_xind + 1, y = m_yind - 1; (x >= 0 && x<=7 && y >= 0 && y<=7); x++, y--)
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
		for (int x = m_xind + 1, y = m_yind + 1; (x >= 0 && x <= 7 && y >= 0 && y <= 7); x++, y++)
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
		for (int x = m_xind - 1, y = m_yind + 1; (x >= 0 && x <= 7 && y >= 0 && y <= 7); x--, y++)
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
	}

	occupy_board();
}

void Queen::ganerate_attack_space()
{
	
}


