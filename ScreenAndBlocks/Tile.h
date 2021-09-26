#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
class Tile
{
private:
	bool setUpSprite(std::string);
public:
	bool isPassable;
	bool isExit;
	
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;

	Tile(std::string,float,float,bool);
	~Tile();

};

