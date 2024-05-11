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

