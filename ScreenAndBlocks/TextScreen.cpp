#include "TextScreen.h"

void TextScreen::setTextColor(sf::Color x)
{
	this->text.setFillColor(x);
}

void TextScreen::render(sf::RenderWindow& target)
{
	if(this->isOpen)
		target.draw(this->text);
}

TextScreen::TextScreen(sf::RenderWindow& target)
{
	this->isOpen = true;
	if (!this->font.loadFromFile("Fonts/sewer.ttf")) {
		std::cout << "Error with text fonts\n";
	}
	this->text.setFont(this->font);
	this->text.setCharacterSize(40);
	this->text.setString("Start Game");
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(sf::Vector2f(target.getSize().x/2-this->text.getLocalBounds().width/2, target.getSize().y/2- text.getLocalBounds().height / 2));
}

TextScreen::~TextScreen()
{
}
