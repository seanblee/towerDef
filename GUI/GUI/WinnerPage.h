#pragma once
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "screenElement.h"
#include "TowerManager.h"
#include "WaveDescription.h"
#include "WaveComplete.h"
//displays winning statistics
//todo: make statistic based off of outside data
class WinnerPage : public cScreen
{
	Player *user;
public:
	WinnerPage(GUIStyle& style, Player*& p) : cScreen(style) { user = p; }

	virtual int Run(sf::RenderWindow &window);
};
int WinnerPage::Run(sf::RenderWindow &window) {

	GUIStyle style(getStyle());//load style

	//for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	
	//add winner title
	sf::Text TitleText("Winner", style.font, 70);
	TitleText.setFillColor(style.textCol);
	TitleText.setStyle(sf::Text::Underlined);
	float widthText = TitleText.getLocalBounds().width;
	float heightText = TitleText.getLocalBounds().height;
	TitleText.setPosition((widthWin / 2) - (widthText / 2), 0);

	int finalScore = 100;// change this so is real value
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
				//close window and stop program
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					//close window stop program
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					//restart game, go to mainMenu
					return 0;
				}
			}
			window.clear(style.bodyCol);

			// draw title and final score text
			window.draw(TitleText);
			window.draw(scoreText);

			// add exit text and next label
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);

			//draw text with info about game
			int numEnemiesKilled = 100;//change this to real info
			addElement.drawInfoBar(window, TitleText, 0, std::to_string(numEnemiesKilled) + " :Total Hostiles Eliminated");
			int playerHealthLost = user->getHP();
			addElement.drawInfoBar(window, TitleText, 1, std::to_string(playerHealthLost) + " :Extra Hp");
			int currencyRemaining = user->getMoney();
			addElement.drawInfoBar(window, TitleText, 2, std::to_string(currencyRemaining) + " :Currency Remaining");
			
			window.display();
		}
	}
}











