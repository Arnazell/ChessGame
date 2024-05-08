#pragma once
#include "SFML_manager.h"	
#include "Figure.h"
#include "Pawn.h"
#include "Bishop.h"
#include <vector>
class Game
{
public:
	// Konstruktor
	Game(SFML_manager* graphics);
	// Destruktor
	//~Game();

	// Rodzaje figur

	// Drukuj figury
	void draw_figures();

	// Drukuj plansze
	void draw_board();

	// Uaktualij gre
	void update();

private:
	// Dostep do grafiki
	SFML_manager* graphics;

	// 
	// Wektor ze wskaznikami na figury
	std::vector<Figure*> pieces;
	// Plansza - przechowuje 
	

	// Figury
	Pawn p1;
	Pawn p2;
	Pawn p3;
	Pawn p4;
	Pawn p5;
	Pawn p6;
	Pawn p7;
	Pawn p8;

	Pawn P1;
	Pawn P2;
	Pawn P3;
	Pawn P4;
	Pawn P5;
	Pawn P6;
	Pawn P7;
	Pawn P8;

	Bishop b1;
	Bishop b2;
};