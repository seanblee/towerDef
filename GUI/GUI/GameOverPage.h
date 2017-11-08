#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class GameOverPage : public cScreen
{
public:
	GameOverPage(GUIStyle& style) : cScreen(style) {}
	virtual int Run(sf::RenderWindow &window);
};
int GameOverPage::Run(sf::RenderWindow &window)
{
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	GUIStyle style(getStyle());

	sf::Text TitleText1("GameOver", style.font, 70);
	TitleText1.setFillColor(style.textCol);
	TitleText1.setStyle(sf::Text::Underlined);
	float widthText = TitleText1.getLocalBounds().width;
	float heightText = TitleText1.getLocalBounds().height;
	TitleText1.setPosition((widthWin / 2) - (widthText / 2), 0);

	int finalScore = 100;
	sf::Text scoreText(std::to_string(finalScore) + " :Final Score", style.font, 70);
	scoreText.setFillColor(style.textCol);
	widthText = scoreText.getLocalBounds().width;
	heightText = scoreText.getLocalBounds().height;
	scoreText.setPosition((widthWin / 2) - (widthText / 2), 450);

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
					return 0;
				}
			}
			window.clear(style.bodyCol);
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			int enemiesEliminated = 100;
			addElement.drawInfoBar(window, TitleText1, 0, std::to_string(enemiesEliminated)+" :total Enemies Eliminated");
			int currLeft = 1;
			addElement.drawInfoBar(window, TitleText1, 1, std::to_string(currLeft) + " :Currency Remaining");
			
			window.draw(TitleText1);
			window.draw(scoreText);
			window.display();
		}

	}
}
