#include "SFML_manager.h"


// --------------------------------------------------------------------------------------
// Inicjalizacja
// --------------------------------------------------------------------------------------
void SFML_manager::init()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APPNAME);
	window.setFramerateLimit(60);
}


