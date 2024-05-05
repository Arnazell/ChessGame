#include <iostream>
#include "MainLoop.h"
#include "SFML_manager.h"


void Chess::run()
{
    //NOTATKA: BEDZIEMY PRZEKAZYWALI DO KAZDEJ FIGURY WSKAZNIK DO NIEGO, GDYZ WTEDY BEDA ONE MIALY DOSTEP DO OKNA I BEDA MOGLY SIE NARYSOWAC!
	
    // Zarzadzanie sfml
	SFML_manager graphics;
    graphics.init();

	// Stan gry
	bool quit = false;

    // Glowna petla
	while (!quit)
	{
        // Sprawdzenie zdarzeñ
        sf::Event event;
        while (graphics.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                quit = true;
        }

        graphics.window.clear(sf::Color::White);

        // Wyswietlani
        graphics.window.display();
	}
}
