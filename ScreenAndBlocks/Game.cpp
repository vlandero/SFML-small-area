#include "Game.h"

void Game::getPollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.type == sf::Event::Closed)
			this->window->close();
		if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::update()
{
	this->getPollEvents();
	this->updateMouse();
	this->updateTextScreen();
	this->gameScreen->update();
	
}
void Game::updateMouse()
{
	this->m = sf::Mouse::getPosition(*this->window);
	this->mousePos = this->window->mapPixelToCoords(this->m);
}

void Game::updateTextScreen()
{
	if (this->startingWindow->isOpen) {
		if (this->startingWindow->text.getGlobalBounds().contains(this->mousePos)) {
			this->startingWindow->setTextColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->startingWindow->isOpen = false;
				this->gameScreen->isOpen = true;
			}
		}
		else
			this->startingWindow->setTextColor(sf::Color::White);
	}
}
void Game::render()
{
	this->window->clear();

	this->gameScreen->render(*this->window);
	this->startingWindow->render(*this->window);

	this->window->display();
}

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(400, 400), "Sample Game", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->startingWindow = new TextScreen(*this->window);
	this->gameScreen = new GameScreen(*this->window);
}

Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen()) {
		
		this->update();
		this->render();
	}
}
