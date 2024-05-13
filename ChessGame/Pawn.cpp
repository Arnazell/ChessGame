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
	deocupy_board();
	m_movement_space.clear();
	m_optional_attack_space.clear();

	if (m_team== BLACK)
	{
		// generuj ruchy dla czarnych pionkow
		if (m_yind < 7)
		{
			// sprawdz czy mozna isc 1 w dol
			if (board->board_state[m_xind + (m_yind + 1) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind + 1);

				// jesli tak to sprawdz czy mozna isc dwa
				if (m_yind < 6)
				{
					if (board->board_state[m_xind + (m_yind + 2) * 8] == nullptr)
					{
						m_movement_space.emplace_back(m_xind, m_yind + 2);
					}
				}
			}
		}
	}
	else if (m_team == WHITE)
	{
		// generuj ruchy dla bialych pionkow
		if (m_yind > 0)
		{
			// sprawdz czy mozna isc 1 w gore
			if (board->board_state[m_xind + (m_yind - 1) * 8] == nullptr)
			{
				m_movement_space.emplace_back(m_xind, m_yind - 1);

				// jesli tak to sprawdz czy mozna isc 1 w dol
				if (m_yind > 1)
				{
					if (board->board_state[m_xind + (m_yind - 2) * 8] == nullptr)
					{
						m_movement_space.emplace_back(m_xind, m_yind - 2);
					}
				}
			}

			
		}
	}
	// wygeneruj mozliwe ataki
	ganerate_attack_space();

	// zajmij plansze
	occupy_board();
}

void Pawn::ganerate_attack_space()
{
	m_attack_space.clear();
	// Ataki czarnych
	if (this->m_team == BLACK)
	{
		// gdy pionek jest po lewej
		if ((m_xind == 0) && (m_yind < 7))
		{
			// jesli jakas figura jest w polu ataki
			if (board->board_state[(m_xind + 1) + (m_yind + 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind + 1) + (m_yind + 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind + 1, m_yind + 1);
				}
			}
			// jesli nie ma, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind + 1, m_yind + 1);
			}
		}

		// gdy pionek jest po prawej
		if ((m_xind == 7) && (m_yind < 7))
		{
			// jesli jakas figura jest w polu ataki
			if (board->board_state[(m_xind - 1) + (m_yind + 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind - 1) + (m_yind + 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind - 1, m_yind + 1);
				}
			}
			// jesli nie ma, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind - 1, m_yind + 1);
			}
		}

		// gdy pionek jest na srodku
		if ((m_xind > 0) && (m_xind < 7) && (m_yind < 7))
		{
			// sprawdz atak na prawe pole
			if (board->board_state[(m_xind + 1) + (m_yind + 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind + 1) + (m_yind + 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind + 1, m_yind + 1);
				}
			}
			// jesli nie ma, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind + 1, m_yind + 1);
			}

			// sprawdz atak na lewe pole
			if (board->board_state[(m_xind - 1) + (m_yind + 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind - 1) + (m_yind + 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind - 1, m_yind + 1);
				}
			}
			// jesli nie ma figury, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind - 1, m_yind + 1);
			}
		}
	}
		
	// Ataki bielych
	else if (this->m_team == WHITE)
	{
		// gdy pionek jest po lewej
		if ((m_xind == 0) && (m_yind > 0))
		{
			// jesli jakas figura jest w polu ataki
			if (board->board_state[(m_xind + 1) + (m_yind - 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind + 1) + (m_yind - 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind + 1, m_yind - 1);
				}
			}
			// jesli nie ma figury, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind + 1, m_yind - 1);
			}
		}

		// gdy pionek jest po prawej
		if ((m_xind == 7) && (m_yind > 0))
		{
			// jesli jakas figura jest w polu ataki
			if (board->board_state[(m_xind - 1) + (m_yind - 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind - 1) + (m_yind - 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind - 1, m_yind - 1);
				}
			}
			// jesli nie ma figury, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind - 1, m_yind - 1);
			}
		}

		// gdy pionek jest na srodku
		if ((m_xind > 0) && (m_xind < 8) && (m_yind > 0))
		{
			// sprawdz atak na prawe pole
			if (board->board_state[(m_xind + 1) + (m_yind - 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind + 1) + (m_yind - 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind + 1, m_yind - 1);
				}
			}
			// jesli nie ma figury, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind + 1, m_yind - 1);
			}

			// sprawdz atak na lewe pole
			if (board->board_state[(m_xind - 1) + (m_yind - 1) * 8])
			{
				// i jesli jest z przeciwnej druzyny
				if (board->board_state[(m_xind - 1) + (m_yind - 1) * 8]->m_team != this->m_team)
				{
					m_attack_space.emplace_back(m_xind - 1, m_yind - 1);
				}
			}
			// jesli nie ma figury, to wciaz to pole jest pod atakiem
			else
			{
				m_optional_attack_space.emplace_back(m_xind - 1, m_yind - 1);
			}
		}
	}
}


