#pragma once
#include "TextScreen.h"
#include "GameScreen.h"
class Game
{
private:

	sf::RenderWindow* window;
	TextScreen* startingWindow;
	GameScreen* gameScreen;

	void getPollEvents();
	void update();
	void updateTextScreen();
	
	void render();

	sf::Vector2i m;
	sf::Vector2f mousePos;
	void updateMouse();
	
public:
	Game();
	~Game();
	void run();
};

