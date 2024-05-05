#include <iostream>
#include "Pawn.h"
#include 

Pawn::Pawn(Team team, unsigned int xpos, unsigned int ypos)
	: Figure(team, xpos, ypos, PAWN)
{
	
	std::string fileToLoad;

	// £adowanie tekstury
	if (m_team == BLACK)
	{
		fileToLoad = "../res/black-pawn.png";
	}
	else
	{
		fileToLoad = "../res/white-pawn.png";
	}


}
