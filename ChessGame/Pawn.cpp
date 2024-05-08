#include <iostream>
#include "Pawn.h"


// Notatka: wiele razy ładujemy tą samą teksturę;)

Pawn::Pawn(Team team, int xind, int yind, SFML_manager* graphics, Assets* resources)
	: Figure(team, xind, yind, PAWN, graphics, resources)
{
	
	std::string fileToLoad;

	// stworzenie prostokata
	m_Rect.left = 0;
	m_Rect.top = 0;
	m_Rect.width = SIZE;
	m_Rect.height = SIZE;

	// inicjalizacja sprite
	this->setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
	this->setPosition(xind * SIZE, yind * SIZE);

	// wybor tekstury
	if (m_team == BLACK)
	{
		this->setTexture(resources->texture_pawn_black);
	}
	else
	{
		this->setTexture(resources->texture_pawn_white);
	}

}

void Pawn::draw() 
{
	graphics->window.draw(*this);
}
