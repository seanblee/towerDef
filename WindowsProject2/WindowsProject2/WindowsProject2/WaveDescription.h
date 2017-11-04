#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class WaveDescription : public cScreen
{
public:
	virtual int Run(sf::RenderWindow &window);
};

int WaveDescription::Run(sf::RenderWindow &window)
{

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	sf::Font font;
	font.loadFromFile("atwriter.ttf");

	int border = 3;
	int titleWidth = widthWin-border*2;
	int titleHeight = 80;
	sf::RectangleShape titleBar(sf::Vector2f(titleWidth, titleHeight));
	titleBar.setFillColor(sf::Color(240, 230, 60));
	titleBar.setOutlineThickness(border);
	titleBar.setOutlineColor(sf::Color(0, 0, 0));
	titleBar.setPosition(0+titleBar.getOutlineThickness(), 0+ titleBar.getOutlineThickness());


	sf::Text titleText1("Level 1 Wave 1", font, 30);
	titleText1.setFillColor(sf::Color::Black);
	titleText1.setStyle(sf::Text::Underlined);
	titleText1.setPosition(titleBar.getPosition().x + titleWidth / 2 - titleText1.getLocalBounds().width / 2,
		titleBar.getPosition().y);

	sf::Text titleText2("Incoming Enemies", font, 40);
	titleText2.setFillColor(sf::Color::Black);
	titleText2.setPosition(titleBar.getPosition().x + titleWidth / 2 - titleText2.getLocalBounds().width / 2,
		titleBar.getPosition().y+titleText1.getLocalBounds().height+10);





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					return 2;
				}
			}
			window.clear(sf::Color(80, 90, 100));
			screenElement addElement;
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			addElement.drawEnemyBar(window,titleBar,0);
			addElement.drawEnemyBar(window, titleBar, 1);
			window.draw(titleBar);
			window.draw(titleText1);
			window.draw(titleText2);
			
			window.display();
		}


	}
}