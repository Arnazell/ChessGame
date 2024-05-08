#include <iostream>
#include "MainLoop.h"
#include "SFML_manager.h"
#include "Game.h"

void Chess::run()
{
    //NOTATKA: BEDZIEMY PRZEKAZYWALI DO KAZDEJ FIGURY WSKAZNIK DO NIEGO, GDYZ WTEDY BEDA ONE MIALY DOSTEP DO OKNA I BEDA MOGLY SIE NARYSOWAC!
	
    // Zarzadzanie sfml
	SFML_manager graphics;
    graphics.init();

    // Zarzadzanie gra
    Game game(&graphics);

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
        game.update();

        // Rysowanie figur
        game.draw_figures();

        // Wyswietlenie wszyskiego na ekranie
        graphics.window.display();
	}
}
