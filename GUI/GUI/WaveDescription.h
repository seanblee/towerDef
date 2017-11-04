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
	WaveDescription(GUIStyle& style) : cScreen(style) {}
	virtual int Run(sf::RenderWindow &window);
};

int WaveDescription::Run(sf::RenderWindow &window)
{
	GUIStyle style(getStyle());

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	

	
	int titleWidth = widthWin-style.borderSize*2;
	int titleHeight = 80;
	sf::RectangleShape titleBar(sf::Vector2f(titleWidth, titleHeight));
	titleBar.setFillColor(style.bodyCol);
	titleBar.setOutlineThickness(style.borderSize);
	titleBar.setOutlineColor(sf::Color(0, 0, 0));
	titleBar.setPosition(0+titleBar.getOutlineThickness(), 0+ titleBar.getOutlineThickness());


	sf::Text titleText1("Level 1 Wave 1", style.font, 30);
	titleText1.setFillColor(style.textCol);
	titleText1.setStyle(sf::Text::Underlined);
	titleText1.setPosition(titleBar.getPosition().x + titleWidth / 2 - titleText1.getLocalBounds().width / 2,
		titleBar.getPosition().y);

	sf::Text titleText2("Incoming Enemies", style.font, 40);
	titleText2.setFillColor(style.textCol);
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
			window.clear(style.bodyCol);
			screenElement addElement;
			addElement.setStyle(style);
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