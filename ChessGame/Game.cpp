#include "Game.h"
#include <iostream>

Game::Game(SFML_manager* graphics, Assets* resources, Board* board)
	:graphics(graphics), resources(resources), board(board), selected(nullptr),
	p1(Pawn(Figure::BLACK, 0, 4, graphics, resources, board)),
	p2(Pawn(Figure::BLACK, 1, 1, graphics, resources, board)),
	p3(Pawn(Figure::BLACK, 2, 1, graphics, resources, board)),
	p4(Pawn(Figure::BLACK, 3, 1, graphics, resources, board)),
	p5(Pawn(Figure::BLACK, 4, 1, graphics, resources, board)),
	p6(Pawn(Figure::BLACK, 5, 1, graphics, resources, board)),
	p7(Pawn(Figure::BLACK, 6, 1, graphics, resources, board)),
	p8(Pawn(Figure::BLACK, 7, 1, graphics, resources, board)),

	P1(Pawn(Figure::WHITE, 0, 6, graphics, resources, board)),
	P2(Pawn(Figure::WHITE, 1, 6, graphics, resources, board)),
	P3(Pawn(Figure::WHITE, 2, 6, graphics, resources, board)),
	P4(Pawn(Figure::WHITE, 3, 6, graphics, resources, board)),
	P5(Pawn(Figure::WHITE, 4, 6, graphics, resources, board)),
	P6(Pawn(Figure::WHITE, 5, 6, graphics, resources, board)),
	P7(Pawn(Figure::WHITE, 6, 6, graphics, resources, board)),
	P8(Pawn(Figure::WHITE, 7, 6, graphics, resources, board))
{
}

void Game::draw_figures()
{
	// drukowanie planszy
	board->drawBoard();
	
	// drukowanie mozliwych ruchow
	if (selected)
	{
		selected->print_moves();
	}

	// drukowanie figur
	for (auto field : board->board_state)
	{
		if (field)
		{
			field->draw();
		}
	}
}
void Game::select_figure()
{
	auto position = graphics->mousePosition;
	int xind = position.x / 128;
	int yind = position.y / 128;
	// jesli myszka wskazuje na jakas figure
	if ((xind < 8) && (yind < 8))
	{
		selected = board->board_state[xind + yind * 8];
		std::cout << "Xind: " << xind << "Yind: " << yind << "\n";
	}
}
void Game::update()
{
	// jesli zaden pionek nie zostal wybrany
	if (!selected)
	{
		// w przypadku klikniecia go wybierz
		if (graphics->LPMclick)
		{
			select_figure();
			if(selected) selected->click();
		}
	}
	else
	{
		// Gdy gracz kliknie to zmien wybor
		if (graphics->LPMclick)
		{
			selected->unclick();
			select_figure();
			if (selected) selected->click();
		}
	}
}
