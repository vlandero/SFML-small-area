#pragma once
#include "Tile.h"
#include "Player.h"
#include <vector>
#include <utility>

class GameScreen
{
private:
	sf::Vector2i playerPos;
	void createMap();
public:
	Player player;
	std::vector<std::vector<Tile*>>tiles;
	std::vector<std::pair<int, int>>walls;
	int gridLength = 8;
	bool isOpen;

	void render(sf::RenderWindow& target);
	void update();

	GameScreen(sf::RenderWindow &target);
	~GameScreen();
};

