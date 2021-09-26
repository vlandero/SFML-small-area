#include "Tile.h"

Tile::Tile(std::string textureName, float x, float y, bool passable)
{
	if (!this->setUpSprite(textureName))
		return;
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
}

Tile::~Tile()
{
}

bool Tile::setUpSprite(std::string textureName)
{
	if (!this->texture.loadFromFile(textureName))
	{
		std::cout << "Textures not loaded ";
		return 0;
	}
	this->texture.setSmooth(true);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	return true;

}
