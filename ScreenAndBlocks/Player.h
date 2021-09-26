#pragma once

#include "Tile.h"
class Player
{
private:
	std::vector<sf::Texture> front;
	std::vector<sf::Texture> back;
	std::vector<sf::Texture> left;
	std::vector<sf::Texture> right;
	void loadTextures();
	sf::Sprite sprite;
	float movementSpeed;
	void move(const float dx, const float dy, std::vector<std::vector<Tile*>>& v, std::vector<std::pair<int, int>>& w);
	bool shouldItMove(std::vector<std::vector<Tile*>>& v, std::vector<std::pair<int, int>>& w,const float dx, const float dy);
	int positionArray;
	int framesToUpdate;
	int currentFrames;
public:

	void render(sf::RenderWindow& target);
	void update(std::vector<std::vector<Tile*>>&, std::vector<std::pair<int, int>>&);

	Player();
	~Player();
};

