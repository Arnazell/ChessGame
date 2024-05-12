#include "Game.h"
#include <iostream>

Game::Game(SFML_manager* graphics, Assets* resources, Board* board)
	:graphics(graphics), resources(resources), board(board), selected(nullptr), m_player(WHITE),
	p1(Pawn(Figure::BLACK, 0, 1, graphics, resources, board)),
	p2(Pawn(Figure::BLACK, 1, 1, graphics, resources, board)),
	p3(Pawn(Figure::BLACK, 2, 1, graphics, resources, board)),
	p4(Pawn(Figure::BLACK, 3, 1, graphics, resources, board)),
	p5(Pawn(Figure::BLACK, 4, 1, graphics, resources, board)),
	p6(Pawn(Figure::BLACK, 5, 1, graphics, resources, board)),
	p7(Pawn(Figure::BLACK, 6, 1, graphics, resources, board)),
	p8(Pawn(Figure::BLACK, 7, 1, graphics, resources, board)),
	r1(Rook(Figure::BLACK, 0, 0, graphics, resources, board)),
	r2(Rook(Figure::BLACK, 7, 0, graphics, resources, board)),
	kn1(Knight(Figure::BLACK, 1, 0, graphics, resources, board)),
	kn2(Knight(Figure::BLACK, 6, 0, graphics, resources, board)),
	b1(Bishop(Figure::BLACK, 2, 0, graphics, resources, board)),
	b2(Bishop(Figure::BLACK, 5, 0, graphics, resources, board)),

	P1(Pawn(Figure::WHITE, 0, 6, graphics, resources, board)),
	P2(Pawn(Figure::WHITE, 1, 6, graphics, resources, board)),
	P3(Pawn(Figure::WHITE, 2, 6, graphics, resources, board)),
	P4(Pawn(Figure::WHITE, 3, 6, graphics, resources, board)),
	P5(Pawn(Figure::WHITE, 4, 6, graphics, resources, board)),
	P6(Pawn(Figure::WHITE, 5, 6, graphics, resources, board)),
	P7(Pawn(Figure::WHITE, 6, 6, graphics, resources, board)),
	P8(Pawn(Figure::WHITE, 7, 6, graphics, resources, board)),
	R1(Rook(Figure::WHITE, 0, 7, graphics, resources, board)),
	R2(Rook(Figure::WHITE, 7, 7, graphics, resources, board)),
	KN1(Knight(Figure::WHITE, 1, 7, graphics, resources, board)),
	KN2(Knight(Figure::WHITE, 6, 7, graphics, resources, board)),
	B1(Bishop(Figure::WHITE, 2, 7, graphics, resources, board)),
	B2(Bishop(Figure::WHITE, 5, 7, graphics, resources, board))
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
	bool correct_move = false;

	// jesli myszka wskazuje na jakies pole
	if ((xind < 8) && (xind >= 0) && (yind < 8) && (yind>=0))
	{
		// jesli byla wybrana figura
		if (selected)
		{
			// sprawdz czy mozna wykonac ruchu
			if (selected->m_team == m_player)
			{
				// sprawdz czy nastapil ruch
				for (auto move : selected->m_movement_space)
				{
					if ((move.x == xind) && (move.y == yind))
					{
						selected->move(xind, yind);
						correct_move = true;
					}
				}

				// sprawdz czy nastapil atak
				for (auto attack : selected->m_attack_space)
				{
					if ((attack.x == xind) && (attack.y == yind))
					{
						selected->move(xind, yind);
						correct_move = true;
					}
				}
				// jesli wykonano ruch zmien gracza
				if (correct_move)
				{
					if (m_player == WHITE)
					{
						m_player = BLACK;
					}
					else
					{
						m_player = WHITE;
					}
					selected = nullptr;
				}
			}

		}
		
		// jesli wybrano figure
		if (board->board_state[xind + yind * 8])
		{
			// i nalezy ona do gracza
			if (board->board_state[xind + yind * 8]->m_team == m_player)
			{
				selected = board->board_state[xind + yind * 8];
				std::cout << "Selected, x: " << xind << " y: " << yind << "\n";
			}
		}
		else
		{
			selected = nullptr;
		}
	
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
