#include <iostream>
#include "Bishop.h"

Bishop::Bishop(Team team, int xind, int yind, SFML_manager* graphics)
	: Figure(team, xind, yind, BISHOP, graphics)
{

	std::string fileToLoad;

	// stworzenie prostokata
	m_Rect.left = 0;
	m_Rect.top = 0;
	m_Rect.width = SIZE;
	m_Rect.height = SIZE;

	// �adowanie tekstury
	if (m_team == BLACK)
	{
		fileToLoad = "Res/black-bishop.png";
	}
	else
	{
		fileToLoad = "Res/white-bishop.png";
	}
	m_texture.loadFromFile(fileToLoad);

	


	// inicjalizacja spritea
	m_sprite.setTextureRect(m_Rect);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(xind*SIZE, yind*SIZE);
}

void Bishop::draw()
{
	graphics->window.draw(m_sprite);
}
