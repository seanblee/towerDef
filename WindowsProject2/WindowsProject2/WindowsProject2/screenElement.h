#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
class screenElement
{
public:
	void drawExitText(sf::RenderWindow &App);
	void drawNextButton(sf::RenderWindow &App);
	void drawEnemyBar(sf::RenderWindow &window, sf::RectangleShape titleBar, int numBar);
	void drawInfoBar(sf::RenderWindow &window, sf::Text TitleText, int numBar, std::string info);
};
void screenElement::drawInfoBar(sf::RenderWindow &window, sf::Text TitleText, int numBar, std::string info) {
	sf::Font font;
	font.loadFromFile("atwriter.ttf");
	sf::Text infoBox(info, font, 40);
	infoBox.setFillColor(sf::Color::Black);

	// FIX SPACING
	int spacing=0;
	if (numBar > 0)
		spacing = 30;

	infoBox.setPosition(10, 20+ spacing+(TitleText.getPosition().y + TitleText.getLocalBounds().height + (infoBox.getLocalBounds().height*numBar*2)));
	window.draw(infoBox);
}
void screenElement::drawExitText(sf::RenderWindow &window) {
    sf::Font font;
	font.loadFromFile("atwriter.ttf");
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;
	sf::Text exitText("(x) to exit", font, 20);
	exitText.setFillColor(sf::Color::Black);
	int widthText = exitText.getLocalBounds().width;
	int heightText = exitText.getLocalBounds().height;
	exitText.setPosition(0, heightWin - heightText - 10);
	window.draw(exitText);
}
void screenElement::drawNextButton(sf::RenderWindow &window) {

	sf::Font font;
	font.loadFromFile("atwriter.ttf");
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	int nextWidth = 150;
	int nextHeight = 70;
	sf::RectangleShape next(sf::Vector2f(nextWidth, nextHeight));
	next.setFillColor(sf::Color(60, 130, 230));
	next.setOutlineThickness(3);
	next.setOutlineColor(sf::Color(0, 0, 0));
	next.setPosition(widthWin - nextWidth - 10, heightWin - nextHeight - 10);

	sf::Text nextText1("(enter) to", font, 20);
	nextText1.setFillColor(sf::Color::Black);
	nextText1.setPosition(next.getPosition().x + nextWidth / 2 - nextText1.getLocalBounds().width / 2,
		next.getPosition().y - nextText1.getLocalBounds().height - 10);

	sf::Text nextText2("Next", font, 50);
	nextText2.setFillColor(sf::Color::Black);
	nextText2.setPosition(next.getPosition().x + nextWidth / 2 - nextText2.getLocalBounds().width / 2,
		next.getPosition().y + nextHeight / 2 - nextText2.getLocalBounds().height);

	window.draw(next);
	window.draw(nextText1);
	window.draw(nextText2);
}
void screenElement::drawEnemyBar(sf::RenderWindow &window, sf::RectangleShape titleBar, int numBar) {
	int border = 3;
	sf::Font font;
	font.loadFromFile("atwriter.ttf");
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;
	int titleHeight = titleBar.getLocalBounds().height;

	int enemyBarWidth = widthWin - border * 2;
	int enemyBarHeight = 70;
	sf::RectangleShape enemyBar(sf::Vector2f(enemyBarWidth, enemyBarHeight));
	enemyBar.setFillColor(sf::Color(160, 190, 250));
	enemyBar.setOutlineThickness(border);
	enemyBar.setOutlineColor(sf::Color(0, 0, 0));
	enemyBar.setPosition(enemyBar.getOutlineThickness(), (titleBar.getPosition().y + titleHeight+enemyBarHeight*numBar));

	std::string enemyName = "Enemy One Name";

	int numEnemies = 10;

	sf::Text enemyBarText1(std::to_string(numEnemies) + "x ", font, 50);
	enemyBarText1.setFillColor(sf::Color::Black);
	enemyBarText1.setPosition(enemyBar.getPosition().x + 10,
		enemyBar.getPosition().y + enemyBarHeight / 2 - enemyBarText1.getLocalBounds().height / 2 - 15);
	sf::Texture texture;
	texture.loadFromFile("enemyTexture.jpg");

	int enemyImgWidth = 50;
	int enemyImgHeight = 50;
	sf::RectangleShape enemyImage(sf::Vector2f(enemyImgWidth, enemyImgHeight));
	enemyImage.setFillColor(sf::Color(160, 190, 250));
	enemyImage.setOutlineThickness(border);
	enemyImage.setOutlineColor(sf::Color(0, 0, 0));
	enemyImage.setTexture(&texture);
	enemyImage.setPosition(enemyBar.getPosition().x + enemyBarText1.getLocalBounds().width + 10,
		enemyBar.getPosition().y + enemyBarHeight / 2 - enemyImage.getLocalBounds().height / 2);

	sf::Text enemyNameLabel(enemyName, font, 30);
	enemyNameLabel.setFillColor(sf::Color::Black);
	enemyNameLabel.setStyle(sf::Text::Underlined);
	enemyNameLabel.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 - enemyNameLabel.getLocalBounds().width / 2,
		(enemyBar.getPosition().y - 3));

	int enemyHealth = 10;
	int enemySpeed = 10;
	sf::Text enemyHP(" is " + std::to_string(enemyHealth), font, 25);
	enemyHP.setFillColor(sf::Color::Black);
	enemyHP.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 - enemyHP.getLocalBounds().width - 20,
		(enemyNameLabel.getPosition().y + enemyNameLabel.getLocalBounds().height + 10));

	sf::Text enemySpeedLabel("Speed is " + std::to_string(enemySpeed), font, 25);
	enemySpeedLabel.setFillColor(sf::Color::Black);
	enemySpeedLabel.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 + 20,
		(enemyNameLabel.getPosition().y + enemyNameLabel.getLocalBounds().height + 10));

	sf::Texture pixelHeart;
	pixelHeart.loadFromFile("PixelHeart.png");
	sf::Sprite sprite;
	sprite.setTexture(pixelHeart);
	sprite.setScale(0.05, 0.05);
	sprite.setPosition((enemyHP.getPosition().x - 20),
		(enemyHP.getPosition().y + 5));

	window.draw(enemyBar);
	window.draw(enemyBarText1);
	window.draw(enemyImage);
	window.draw(enemyNameLabel);
	window.draw(sprite);
	window.draw(enemyHP);
	window.draw(enemySpeedLabel);
}


