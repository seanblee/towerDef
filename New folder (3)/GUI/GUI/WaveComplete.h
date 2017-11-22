#pragma once
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "screenElement.h"
#include "HostileManager.h"
//displays statistics for wave just completed
//todo: base statistics off of info from other classes, 
class WaveComplete : public cScreen
{
	int numWave = 0;
public:
	Player *user;
	HostileManager *hostMan;
	//to reset wave on when restarting game
	void resetScreen() {
		numWave = 0;
	}
	WaveComplete(GUIStyle& style, Player*& p, HostileManager*& tempMan) : cScreen(style) { user = p; hostMan = tempMan; }
	virtual int Run(sf::RenderWindow &window);
};
int WaveComplete::Run(sf::RenderWindow &window) {
	//make wave object for current wave
	numWave++;
	Wave wave(numWave);

	GUIStyle style(getStyle());//load style

	//for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;
	

	//add title
	sf::Text TitleText("Wave Complete", style.font, 70);
	TitleText.setFillColor(style.textCol);
	TitleText.setStyle(sf::Text::Underlined);
	float widthText = TitleText.getLocalBounds().width;
	float heightText = TitleText.getLocalBounds().height;
	TitleText.setPosition((widthWin / 2) - (widthText / 2), 0);

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				//close and stop program
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					//close and stop program
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return&&wave.getWaveNumber() == 3)
				{
					//player just won the game
					return 6;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					//move to description page for next wave
					return 1;
				}
			}
		}
			window.clear(style.bodyCol);
			//write title
			window.draw(TitleText);

			// add (x) to exit and next label
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			
			//write the info to be displayed
			int numEnemiesKilled = hostMan->hostileKilledLastWave;
			addElement.drawInfoBar(window,TitleText,0, std::to_string(numEnemiesKilled) +" :Hostiles Eliminated");
			int playerHealthLost = user->HPstartLastWave-user->getHP();
			addElement.drawInfoBar(window, TitleText, 1, std::to_string(playerHealthLost) + " :HP Lost");
			int currencyGained = user->getMoney()-user->moneyStartLastWave;
			addElement.drawInfoBar(window, TitleText, 2, std::to_string(currencyGained) + " :Currency Gained");
			
			window.display();
		

	}
}
