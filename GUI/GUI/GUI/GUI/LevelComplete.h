#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class LevelComplete : public cScreen
{
public:
	LevelComplete(GUIStyle& style) : cScreen(style) {}
	virtual int Run(sf::RenderWindow &window);
};
int LevelComplete::Run(sf::RenderWindow &window)
{

	GUIStyle style(getStyle());

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	sf::Text TitleText1("Level Complete", style.font, 70);
	TitleText1.setFillColor(style.textCol);
	TitleText1.setStyle(sf::Text::Underlined);
	float widthText = TitleText1.getLocalBounds().width;
	float heightText = TitleText1.getLocalBounds().height;
	TitleText1.setPosition((widthWin / 2) - (widthText / 2), 0);

	sf::Text TitleText2("Upcoming Changes", style.font, 50);
	TitleText2.setFillColor(style.textCol);
	widthText = TitleText2.getLocalBounds().width;
	heightText = TitleText2.getLocalBounds().height;
	TitleText2.setPosition((widthWin / 2) - (widthText / 2), TitleText1.getLocalBounds().height+TitleText1.getPosition().y+20);



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
					//should be 1
					return 6;
				}
			}
			window.clear(style.bodyCol);
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			addElement.drawInfoBar(window, TitleText2, 0, "Hostiles Hp increase by one");
			addElement.drawInfoBar(window, TitleText2, 2, "Hostiles speed increases by one");
			window.draw(TitleText1);
			window.draw(TitleText2);
			window.display();
		}

	}
}
