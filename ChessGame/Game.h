#pragma once
#include "SFML_manager.h"	
#include "Figure.h"
#include "Assets.h"
#include "Board.h"

#include "Pawn.h"
#include "Rook.h"
#include <vector>


// -------------------------------------------------------------------------------------------------------
// klasa zarzadzajaca gr�
// -------------------------------------------------------------------------------------------------------


class Game
{
public:
	// Konstruktor
	Game(SFML_manager* graphics, Assets* resources, Board* board);
	// Destruktor
	//~Game();

	// Drukuj figury
	void draw_figures();

	// Uaktualij gre
	void update();

	// Wybierz figure
	void select_figure();

	// Gracz
	enum Player{BLACK, WHITE};

	Player m_player;

private:
	// Dostep do grafiki
	SFML_manager* graphics;

	// Dostep do zasobow
	Assets* resources;

	// Dostep do planszy
	Board* board;

	// Wybrana figura
	Figure* selected;
	
	// Obecny gracz

	// Figury
	Pawn p1;
	Pawn p2;
	Pawn p3;
	Pawn p4;
	Pawn p5;
	Pawn p6;
	Pawn p7;
	Pawn p8;
	Rook r1;
	Rook r2;

	Pawn P1;
	Pawn P2;
	Pawn P3;
	Pawn P4;
	Pawn P5;
	Pawn P6;
	Pawn P7;
	Pawn P8;
	Rook R1;
	Rook R2;
	

};