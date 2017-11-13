#pragma once
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "screenElement.h"
class WinnerPage : public cScreen
{
public:
	WinnerPage(GUIStyle& style) : cScreen(style) {}
	virtual int Run(sf::RenderWindow &window);
};
int WinnerPage::Run(sf::RenderWindow &window) {
	GUIStyle style(getStyle());

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	

	sf::Text TitleText("Winner", style.font, 70);
	TitleText.setFillColor(style.textCol);
	TitleText.setStyle(sf::Text::Underlined);
	float widthText = TitleText.getLocalBounds().width;
	float heightText = TitleText.getLocalBounds().height;
	TitleText.setPosition((widthWin / 2) - (widthText / 2), 0);

	int finalScore = 100;
	sf::Text scoreText(std::to_string(finalScore)+" :Final Score", style.font, 70);
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
					//0
					return 7;
				}
			}
			window.clear(style.bodyCol);
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			int numEnemiesKilled = 100;
			addElement.drawInfoBar(window, TitleText, 0, std::to_string(numEnemiesKilled) + " :Total Hostiles Eliminated");
			int playerHealthLost = 10;
			addElement.drawInfoBar(window, TitleText, 1, std::to_string(playerHealthLost) + " :Extra Hp");
			int currencyGained = 100;
			addElement.drawInfoBar(window, TitleText, 2, std::to_string(currencyGained) + " :Currency Remaining");
			window.draw(TitleText);
			window.draw(scoreText);
			window.display();
		}
	}
}











