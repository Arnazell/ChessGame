#include "Game.h"

Game::Game(SFML_manager* graphics, Assets* resources)
	:graphics(graphics), resources(resources),
	p1(Pawn(Figure::BLACK, 0, 1, graphics, resources)),
	p2(Pawn(Figure::BLACK, 1, 1, graphics, resources)),
	p3(Pawn(Figure::BLACK, 2, 1, graphics, resources)),
	p4(Pawn(Figure::BLACK, 3, 1, graphics, resources)),
	p5(Pawn(Figure::BLACK, 4, 1, graphics, resources)),
	p6(Pawn(Figure::BLACK, 5, 1, graphics, resources)),
	p7(Pawn(Figure::BLACK, 6, 1, graphics, resources)),
	p8(Pawn(Figure::BLACK, 7, 1, graphics, resources)),

	P1(Pawn(Figure::WHITE, 0, 6, graphics, resources)),
	P2(Pawn(Figure::WHITE, 1, 6, graphics, resources)),
	P3(Pawn(Figure::WHITE, 2, 6, graphics, resources)),
	P4(Pawn(Figure::WHITE, 3, 6, graphics, resources)),
	P5(Pawn(Figure::WHITE, 4, 6, graphics, resources)),
	P6(Pawn(Figure::WHITE, 5, 6, graphics, resources)),
	P7(Pawn(Figure::WHITE, 6, 6, graphics, resources)),
	P8(Pawn(Figure::WHITE, 7, 6, graphics, resources))
{
	pieces.push_back(&p1);
	pieces.push_back(&p2);
	pieces.push_back(&p3);
	pieces.push_back(&p4);
	pieces.push_back(&p5);
	pieces.push_back(&p6);
	pieces.push_back(&p7);

	pieces.push_back(&P1);
	pieces.push_back(&P2);
	pieces.push_back(&P3);
	pieces.push_back(&P4);
	pieces.push_back(&P5);
	pieces.push_back(&P6);
	pieces.push_back(&P7);

}

void Game::draw_figures()
{
	for (auto piece : pieces)
	{
		piece->draw();
	}
}

void Game::draw_board()
{

}

void Game::update()
{
	return;
}
