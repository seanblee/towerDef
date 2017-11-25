#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "HostileManager.h"
//display end of game statistic when player loses
class GameOverPage : public cScreen
{

	Player *user;
	HostileManager *hostMan;
public:

	GameOverPage(GUIStyle& style, Player*& p, HostileManager*& tempMan) : cScreen(style) { user = p; hostMan = tempMan; }
	virtual int Run(sf::RenderWindow &window);
};
int GameOverPage::Run(sf::RenderWindow &window)
{
	// for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	GUIStyle style(getStyle());//load style

	//add title
	sf::Text TitleText1("GameOver", style.font, 70);
	TitleText1.setFillColor(style.textCol);
	TitleText1.setStyle(sf::Text::Bold);
	float widthText = TitleText1.getLocalBounds().width;
	float heightText = TitleText1.getLocalBounds().height;
	TitleText1.setPosition((widthWin / 2) - (widthText / 2), 0);

	// add text with final score
	int finalScore = 100;//change this to real value
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
				//close program and window
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					//close window and stop program
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					//restart game, go to mainMenu
					return 0;
				}
			}
		}
			window.clear(style.bodyCol);

			//draw score and title text
			window.draw(TitleText1);
			window.draw(scoreText);

			// add exit text and next label
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);

			// info text of end of game statistic when user loses
			int enemiesEliminated = hostMan->totalHostilesEliminated;//change this to real info
			addElement.drawInfoBar(window, TitleText1, 0, std::to_string(enemiesEliminated)+" :total Enemies Eliminated");
			int currLeft = user->getMoney();
			addElement.drawInfoBar(window, TitleText1, 1, std::to_string(currLeft) + " :Currency Remaining");
			
			
			window.display();
		

	}
}
