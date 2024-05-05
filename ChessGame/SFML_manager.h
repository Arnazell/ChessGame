#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>

// --------------------------------------------------------------------------------------
// Klasa zarz¹dzaj¹ca grafik¹ - generuje okna, ³aduje pliki, 
// --------------------------------------------------------------------------------------

class SFML_manager
{
public:
	// Screen seetings
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 800;
	const char* APPNAME = "Chess2024";

	// Framerate
	const int MAX_FPS = 60;

	//  Okno 
	sf::RenderWindow window;

	// Inicjalizuje okno
	void init();

	// £aduje teksture
	void loadTexture(const char* filename);
};
