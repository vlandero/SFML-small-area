#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class TextScreen
{
private:
	sf::Font font;
public:
	sf::Text text;
	bool isOpen;
	void setTextColor(sf::Color x);
	void render(sf::RenderWindow& target);
	TextScreen(sf::RenderWindow& target);
	~TextScreen();
};

