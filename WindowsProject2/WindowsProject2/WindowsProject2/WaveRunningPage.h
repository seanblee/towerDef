#pragma once
#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class WaveRunningPage : public cScreen
{
public:
	virtual int Run(sf::RenderWindow &window);
};

int WaveRunningPage::Run(sf::RenderWindow &window)
{
	//I found this came in handy for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	//loading font
	sf::Font font;
	font.loadFromFile("atwriter.ttf");

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
			//window.draw(), stuff defined above to window
			window.display();
		}

	}
}
