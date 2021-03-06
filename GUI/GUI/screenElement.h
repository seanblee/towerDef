#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Hostile.h"

//class draws stuff for info pages that is drawn alot
//TODO: fix textures, load data for info
class screenElement
{
public:
	GUIStyle style;
	void setStyle(GUIStyle& style);

	
	void drawExitText(sf::RenderWindow &App);
	void drawNextButton(sf::RenderWindow &App);
	void drawEnemyBar(sf::RenderWindow &window, sf::RectangleShape titleBar, int numBar, int, int);
	void drawInfoBar(sf::RenderWindow &window, sf::Text TitleText, int numBar, std::string info);
};

void screenElement::setStyle(GUIStyle& tempStyle) {
	style = tempStyle;
}

void screenElement::drawInfoBar(sf::RenderWindow &window, sf::Text TitleText, int numBar, std::string info) {

	sf::Text infoBox(info, style.font, 40);
	infoBox.setFillColor(style.textCol);
	infoBox.setPosition(100,100);
	infoBox.setPosition(infoBox.getOutlineThickness(), 
		((TitleText.getPosition().y + TitleText.getLocalBounds().height+ infoBox.getLocalBounds().height*numBar))+(30*(numBar+1)));
	window.draw(infoBox);
}
void screenElement::drawExitText(sf::RenderWindow &window) {
  
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;
	sf::Text exitText("(x) to exit", style.font, 30);
	exitText.setFillColor(style.textCol);
	int widthText = exitText.getLocalBounds().width;
	int heightText = exitText.getLocalBounds().height;
	exitText.setPosition(0, heightWin - heightText - 50);
	window.draw(exitText);
}
void screenElement::drawNextButton(sf::RenderWindow &window) {

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	int nextWidth = 150;
	int nextHeight = 70;
	sf::RectangleShape next(sf::Vector2f(nextWidth, nextHeight));
	next.setFillColor(style.bodyCol);
	next.setOutlineThickness(style.borderSize);
	next.setOutlineColor(style.borderCol);
	next.setPosition(widthWin - nextWidth - 10, heightWin - nextHeight - 10);

	sf::Text nextText1("(enter) to", style.font, 20);
	nextText1.setFillColor(style.textCol);
	nextText1.setPosition(next.getPosition().x + nextWidth / 2 - nextText1.getLocalBounds().width / 2,
		next.getPosition().y - nextText1.getLocalBounds().height - 10);

	sf::Text nextText2("Next", style.font, 50);
	nextText2.setFillColor(style.textCol);
	nextText2.setPosition(next.getPosition().x + nextWidth / 2 - nextText2.getLocalBounds().width / 2,
		next.getPosition().y + nextHeight / 2 - nextText2.getLocalBounds().height);

	window.draw(next);
	window.draw(nextText1);
	window.draw(nextText2);
}
void screenElement::drawEnemyBar(sf::RenderWindow &window, sf::RectangleShape titleBar,int numBar, int numHost, int typeHost ) {
	
	//load sprite sheet from file
	sf::Texture spriteSheet;
	if (!spriteSheet.loadFromFile("SpriteSheet.png")) {/*put in exception later*/ }

	//load hostile sprite
	Hostile h (typeHost);
	h.sprite.setTexture(spriteSheet);
	h.sprite.setTextureRect(sf::IntRect(25 * h.type, 0, 30, 30));

	if (h.type == 1)
		h.sprite.setColor((sf::Color(250, 0, 0)));
	else if (h.type == 2)
		h.sprite.setColor((sf::Color(250, 125, 0)));
	else if (h.type == 3)
		h.sprite.setColor((sf::Color(250, 250, 0)));
	
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;
	int titleHeight = titleBar.getLocalBounds().height;

	int enemyBarWidth = widthWin - style.borderSize * 2;
	int enemyBarHeight = 70;
	sf::RectangleShape enemyBar(sf::Vector2f(enemyBarWidth, enemyBarHeight));
	enemyBar.setFillColor(style.bodyCol);
	enemyBar.setOutlineThickness(style.borderSize);
	enemyBar.setOutlineColor(style.borderCol);
	enemyBar.setPosition(enemyBar.getOutlineThickness(), (titleBar.getPosition().y + titleHeight+enemyBarHeight*numBar));

	std::string enemyName = "Hostile Type "+std::to_string(typeHost);

	sf::Text enemyBarText1(std::to_string(numHost) + "x ", style.font, 50);
	enemyBarText1.setFillColor(style.textCol);
	enemyBarText1.setPosition(enemyBar.getPosition().x + 10,
		enemyBar.getPosition().y + enemyBarHeight / 2 - enemyBarText1.getLocalBounds().height / 2 - 15);


	int enemyImgWidth = 50;
	int enemyImgHeight = 50;
	sf::RectangleShape enemyImage(sf::Vector2f(enemyImgWidth, enemyImgHeight));
	enemyImage.setOutlineThickness(style.borderSize);
	enemyImage.setOutlineColor(style.borderCol);
	enemyImage.setFillColor(style.bodyCol);
	
	enemyImage.setPosition(enemyBar.getPosition().x + enemyBarText1.getLocalBounds().width + 10,
	enemyBar.getPosition().y + enemyBarHeight / 2 - enemyImage.getLocalBounds().height / 2);

	h.sprite.setPosition(enemyBar.getPosition().x + enemyBarText1.getLocalBounds().width + 20,
		enemyBar.getPosition().y + enemyBarHeight / 2 - enemyImage.getLocalBounds().height / 2 + 10);

	sf::Text enemyNameLabel(enemyName, style.font, 30);
	enemyNameLabel.setFillColor(style.textCol);
	enemyNameLabel.setStyle(sf::Text::Bold);
	enemyNameLabel.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 - enemyNameLabel.getLocalBounds().width / 2,
		(enemyBar.getPosition().y - 3));

	int enemyHealth = 10;
	int enemySpeed = 10;
	sf::Text enemyHP("HP is " + std::to_string(enemyHealth), style.font, 25);
	enemyHP.setFillColor(style.textCol);
	enemyHP.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 - enemyHP.getLocalBounds().width - 30,
		(enemyNameLabel.getPosition().y + enemyNameLabel.getLocalBounds().height + 10));

	sf::Text enemySpeedLabel("Speed is " + std::to_string(enemySpeed), style.font, 25);
	enemySpeedLabel.setFillColor(style.textCol);
	enemySpeedLabel.setPosition(enemyBar.getPosition().x + enemyBar.getLocalBounds().width / 2 + 20,
		(enemyNameLabel.getPosition().y + enemyNameLabel.getLocalBounds().height + 10));

	

	window.draw(enemyBar);
	window.draw(enemyBarText1);
	window.draw(enemyImage);
	window.draw(h.sprite);
	window.draw(enemyNameLabel);
	window.draw(enemyHP);
	window.draw(enemySpeedLabel);
}


