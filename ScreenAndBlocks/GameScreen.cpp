#include "GameScreen.h"


void GameScreen::render(sf::RenderWindow& target)
{
	if (this->isOpen) {
		for (int i = 0; i < this->gridLength; ++i) {
			for (int j = 0; j < this->gridLength; ++j) {
				target.draw(this->tiles[i][j]->sprite);
			}
		}
		this->player.render(target);
	}
	
}

void GameScreen::update()
{
	if(this->isOpen)
		this->player.update(tiles,walls);
}

GameScreen::GameScreen(sf::RenderWindow& target)
{
	this->isOpen = false;
	this->createMap();
}

GameScreen::~GameScreen()
{
}


void GameScreen::createMap()
{
	std::vector<Tile*>row;
	//1
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 0, 1));
	row.push_back(new Tile("Map/wood.png", 50, 0, 0));
	row.push_back(new Tile("Map/wood.png", 100, 0, 0));
	row.push_back(new Tile("Map/path.png", 150, 0, 1));
	row.push_back(new Tile("Map/path.png", 200, 0, 1));
	row.push_back(new Tile("Map/path.png", 250, 0, 1));
	row.push_back(new Tile("Map/wood.png", 300, 0, 0));
	row.push_back(new Tile("Map/path.png", 350, 0, 1));
	this->tiles.push_back(row);
	//2
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 50, 1));
	row.push_back(new Tile("Map/path.png", 50, 50, 1));
	row.push_back(new Tile("Map/path.png", 100, 50, 1));
	row.push_back(new Tile("Map/path.png", 150, 50, 1));
	row.push_back(new Tile("Map/path.png", 200, 50, 1));
	row.push_back(new Tile("Map/path.png", 250, 50, 1));
	row.push_back(new Tile("Map/wood.png", 300, 50, 0));
	row.push_back(new Tile("Map/path.png", 350, 50, 1));
	this->tiles.push_back(row);
	//3
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 100, 1));
	row.push_back(new Tile("Map/wood.png", 50,100, 0));
	row.push_back(new Tile("Map/wood.png", 100, 100, 0));
	row.push_back(new Tile("Map/path.png", 150, 100, 1));
	row.push_back(new Tile("Map/path.png", 200, 100, 1));
	row.push_back(new Tile("Map/path.png", 250, 100, 1));
	row.push_back(new Tile("Map/wood.png", 300, 100, 0));
	row.push_back(new Tile("Map/path.png", 350, 100, 1));
	this->tiles.push_back(row);
	//4
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 150, 1));
	row.push_back(new Tile("Map/wood.png", 50, 150, 0));
	row.push_back(new Tile("Map/wood.png", 100, 150, 0));
	row.push_back(new Tile("Map/path.png", 150, 150, 1));
	row.push_back(new Tile("Map/path.png", 200, 150, 1));
	row.push_back(new Tile("Map/path.png", 250, 150, 1));
	row.push_back(new Tile("Map/wood.png", 300, 150, 0));
	row.push_back(new Tile("Map/path.png", 350, 150, 1));
	this->tiles.push_back(row);
	//5
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 200, 1));
	row.push_back(new Tile("Map/wood.png", 50, 200, 0));
	row.push_back(new Tile("Map/wood.png", 100, 200, 0));
	row.push_back(new Tile("Map/path.png", 150, 200, 1));
	row.push_back(new Tile("Map/path.png", 200, 200, 1));
	row.push_back(new Tile("Map/path.png", 250, 200, 1));
	row.push_back(new Tile("Map/wood.png", 300, 200, 0));
	row.push_back(new Tile("Map/path.png", 350, 200, 1));
	this->tiles.push_back(row);
	//6
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 250, 1));
	row.push_back(new Tile("Map/wood.png", 50, 250, 0));
	row.push_back(new Tile("Map/wood.png", 100, 250, 0));
	row.push_back(new Tile("Map/path.png", 150, 250, 1));
	row.push_back(new Tile("Map/path.png", 200, 250, 1));
	row.push_back(new Tile("Map/path.png", 250, 250, 1));
	row.push_back(new Tile("Map/wood.png", 300, 250, 0));
	row.push_back(new Tile("Map/path.png", 350, 250, 1));
	this->tiles.push_back(row);
	//7
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 300, 1));
	row.push_back(new Tile("Map/wood.png", 50, 300, 0));
	row.push_back(new Tile("Map/wood.png", 100, 300, 0));
	row.push_back(new Tile("Map/path.png", 150, 300, 1));
	row.push_back(new Tile("Map/path.png", 200, 300, 1));
	row.push_back(new Tile("Map/path.png", 250, 300, 1));
	row.push_back(new Tile("Map/wood.png", 300, 300, 0));
	row.push_back(new Tile("Map/path.png", 350, 300, 1));
	this->tiles.push_back(row);
	//8
	row.clear();
	row.push_back(new Tile("Map/path.png", 0, 350, 1));
	row.push_back(new Tile("Map/wood.png", 50, 350, 0));
	row.push_back(new Tile("Map/wood.png", 100, 350, 0));
	row.push_back(new Tile("Map/path.png", 150, 350, 1));
	row.push_back(new Tile("Map/path.png", 200, 350, 1));
	row.push_back(new Tile("Map/path.png", 250, 350, 1));
	row.push_back(new Tile("Map/wood.png", 300, 350, 0));
	row.push_back(new Tile("Map/path.png", 350, 350, 1));
	this->tiles.push_back(row);

	for (int i = 0; i < this->gridLength; ++i) {
		for (int j = 0; j < this->gridLength; ++j) {
			if (!tiles[i][j]->isPassable)
			{
				std::pair <int, int> p;
				p.first = i;
				p.second = j;
				walls.push_back(p);
			}
		}
	}
}