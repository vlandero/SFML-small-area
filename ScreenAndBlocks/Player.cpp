#include "Player.h"



void Player::move(const float dx, const float dy, std::vector<std::vector<Tile*>>& v, std::vector<std::pair<int, int>>& w)
{
	if (this->shouldItMove(v, w, dx, dy)) {
		this->sprite.move(this->movementSpeed * dx, this->movementSpeed * dy);
	}
}

bool Player::shouldItMove(std::vector<std::vector<Tile*>>& v, std::vector<std::pair<int, int>>& w, const float dx, const float dy)
{
	int n = w.size();
	for (int i = 0; i < n; ++i) {
		sf::FloatRect playerBounds = this->sprite.getGlobalBounds();
		sf::FloatRect wallBounds = v[w[i].first][w[i].second]->sprite.getGlobalBounds();
		sf::FloatRect nextPosition;
		nextPosition = playerBounds;
		nextPosition.left += this->movementSpeed * dx;
		nextPosition.top += this->movementSpeed * dy;
		if (wallBounds.intersects(nextPosition)) {
			return 0;
		}
	}
	return 1;
}

void Player::render(sf::RenderWindow& target)
{
	target.draw(this->sprite);
}

void Player::update(std::vector<std::vector<Tile*>>& v, std::vector<std::pair<int, int>>&w)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (this->currentFrames == this->framesToUpdate) {
			this->currentFrames = 0;
			this->sprite.setTexture(this->left[this->positionArray]);
			this->positionArray++;
			if (this->positionArray == 3)
				this->positionArray = 0;
		}
		this->move(-1.f, 0.f, v, w);
		this->currentFrames++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (this->currentFrames == this->framesToUpdate) {
			this->currentFrames = 0;
			this->sprite.setTexture(this->right[this->positionArray]);
			this->positionArray++;
			if (this->positionArray == 3)
				this->positionArray = 0;
		}
		this->move(1.f, 0.f, v, w);
		this->currentFrames++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (this->currentFrames == this->framesToUpdate) {
			this->currentFrames = 0;
			this->sprite.setTexture(this->back[this->positionArray]);
			this->positionArray++;
			if (this->positionArray == 3)
				this->positionArray = 0;

		}
		this->move(0.f, -1.f, v, w);
		this->currentFrames++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (this->currentFrames == this->framesToUpdate) {
			this->currentFrames = 0;
			this->sprite.setTexture(this->front[this->positionArray]);
			this->positionArray++;
			if (this->positionArray == 3)
				this->positionArray = 0;
		}
		this->move(0.f, 1.f, v, w);
		this->currentFrames++;
	}
}

Player::Player()
{
	this->movementSpeed = 2.5f;
	this->framesToUpdate = 6;
	this->currentFrames = 0;
	this->loadTextures();
	this->positionArray = 0;
	this->sprite.setTexture(this->front[0]);
	this->sprite.setScale(.5f, .5f);
	
}

Player::~Player()
{
}

void Player::loadTextures()
{
	sf::Texture t;
	t.loadFromFile("Players/front_left_foot.png");
	front.push_back(t);
	t.loadFromFile("Players/front.png");
	front.push_back(t);
	t.loadFromFile("Players/front_right_foot.png");
	front.push_back(t);
	t.loadFromFile("Players/right_left_foot.png");
	right.push_back(t);
	t.loadFromFile("Players/right.png");
	right.push_back(t);
	t.loadFromFile("Players/right_right_foot.png");
	right.push_back(t);
	t.loadFromFile("Players/left_left_foot.png");
	left.push_back(t);
	t.loadFromFile("Players/left.png");
	left.push_back(t);
	t.loadFromFile("Players/left_right_foot.png");
	left.push_back(t);
	t.loadFromFile("Players/back_left_foot.png");
	back.push_back(t);
	t.loadFromFile("Players/back.png");
	back.push_back(t);
	t.loadFromFile("Players/back_right_foot.png");
	back.push_back(t);
}