#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <optional>
#include <thread>


// --------------------------------------------------------------------------------------
// Klasa zarz¹dzaj¹ca grafik¹ - generuje okna, ³aduje pliki, 
// --------------------------------------------------------------------------------------

class SFML_manager
{
public:
	// Screen seetings
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 1024;
	const char* APPNAME = "Chess2024";

	// Framerate
	const int MAX_FPS = 60;

	//  Okno 
	sf::RenderWindow window;

	// Pozycja myszy
	sf::Vector2i mousePosition;

	// Wcisniecie LPM
	bool mousePressedLPM;

	// Flaga pomagajaca obsluzyc klikniecie
	bool LPMblocked;

	// Klikniecie
	bool LPMclick;

	// Inicjalizuje okno
	void init();

	// Update
	void update();
	
	// Zmienia jasnosc tekstury
	void setBrightnes(sf::Texture& texture, float factor);

	// Odtwarza muzyke na innym watku
	void playMusic(sf::Music &sound);

};
