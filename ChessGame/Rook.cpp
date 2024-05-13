#include <iostream>
#include "Rook.h"


// Notatka: wiele razy ³adujemy t¹ sam¹ teksturê;)

Rook::Rook(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources, Board* board)
	: Figure(team, xind, yind, PAWN, graphics, resources, board)
{
	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		m_texture = resources->texture_rook_black;
	}
	else
	{
		m_texture = resources->texture_rook_white;
	}

	this->setTexture(m_texture);

	// generuj ruchy
	generate_move_space();
}

void Rook::generate_move_space()
{
	deocupy_board();
	m_movement_space.clear();
	m_attack_space.clear();

	// generuj ruchy w gore
	for (int i = (m_yind-1); i >= 0; i--)
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
	for(int i = (m_yind + 1); i <= 7; i++)
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

	occupy_board();
}

void Rook::ganerate_attack_space()
{
	;
}


