#pragma once
#include <iostream>
#include "MainLoop.h"
#include "SFML_manager.h"
#include "Game.h"
#include "Assets.h"
#include "Board.h"

void Chess::run()
{
    //NOTATKA: BEDZIEMY PRZEKAZYWALI DO KAZDEJ FIGURY WSKAZNIK DO NIEGO, GDYZ WTEDY BEDA ONE MIALY DOSTEP DO OKNA I BEDA MOGLY SIE NARYSOWAC!
	
    // Zarzadzanie danym
    Assets assets;
    assets.init();
    
    // Zarzadzanie sfml
	SFML_manager graphics;
    graphics.init();

    // Zarzadzanie plansza
    Board board(&graphics);

    // Zarzadzanie gra
    Game game(&graphics, &assets, &board);
    game.init();

	// Stan gry
	bool quit = false;

    // Glowna petla
	while (!quit)
	{
        // Obsluga zdarzeñ
        sf::Event event;
        while (graphics.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                quit = true;
        }

        // Czyszczenie okna
        graphics.window.clear(sf::Color::White);

        // aktualizacja
        graphics.update();
        game.update();
        
        // Rysowanie figur
        game.draw_figures();

        // sprawdzenie warunku
        if (board.check_check())
        {
            game.end();
            quit = true;
        }
        // Wyswietlenie wszyskiego na ekranie
        graphics.window.display();
	}
}
