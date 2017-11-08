#pragma once
#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>

/* WaveRunningPage.h
	implementation of game screen where the wave runs
		-hostiles generated, towers shoot projectiles and hostiles

	to do: projectile animations, hostile animation, logic for going to either WaveComplete, LevelComplete, WinnerPage or GameOverScreen
	(or would the logic come from GameLogic???), pass in towers from towerManager
*/


class WaveRunningPage : public cScreen
{
	sf::Texture spriteSheet;
public:
	WaveRunningPage(GUIStyle& style, sf::Texture Sheet) : cScreen(style) { spriteSheet = Sheet; }
	virtual int Run(sf::RenderWindow &window);
};

int WaveRunningPage::Run(sf::RenderWindow &window)
{

	//I found this came in handy for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	//initialize GUI style
	GUIStyle style(getStyle());

	//set path background and overlays
	string easyPathMap("path1.jpg");
	path easyPath(easyPathMap, 10, 7);
	pathOverlays overlays;
	overlays.setStyle(style);
	buySell buySellOverlay(3, spriteSheet, style);
	


	//define things to be added to window later



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if they click the x in top corner close window
			if (event.type == sf::Event::Closed) {
				window.close();
				return -1;
			}

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Return)
				{
					//click enter to go to waverunning page
					return 4;
				}
			}
			window.clear();
			window.draw(easyPath.pathImage);
			window.draw(overlays.backing);
			window.draw(overlays.getHP());
			window.draw(overlays.getMoney());
			window.draw(overlays.getMessage());
			window.display();
		}

	}
}
