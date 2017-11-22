#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "Wave.h"

//displays upcoming enemies
//TODO: makes sure it works with wave.cpp
class WaveDescription : public cScreen
{
	int numWave = 0;//keeps track of what wave we are on
public:
	//called when game has restarted
	void resetScreen() {
		numWave = 0;
	}
	WaveDescription(GUIStyle& style) : cScreen(style) {}
	virtual int Run(sf::RenderWindow &window);
};

int WaveDescription::Run(sf::RenderWindow &window)
{
	//create wave object for this wave
	numWave++;
	Wave wave(numWave);

	GUIStyle style(getStyle());//loads style

	//for positoning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	//adds bar to top 
	int titleWidth = widthWin-style.borderSize*2;
	int titleHeight = 80;
	sf::RectangleShape titleBar(sf::Vector2f(titleWidth, titleHeight));
	titleBar.setFillColor(style.bodyCol);
	titleBar.setOutlineThickness(style.borderSize);
	titleBar.setOutlineColor(sf::Color(0, 0, 0));
	titleBar.setPosition(0+titleBar.getOutlineThickness(), 0+ titleBar.getOutlineThickness());

	//adds title text
	sf::Text titleText1("Level 1 Wave"+std::to_string(wave.getWaveNumber()), style.font, 30);
	titleText1.setFillColor(style.textCol);
	titleText1.setStyle(sf::Text::Bold);
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
				//close end program when window closed
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					//close end program when x button clicked
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return)//goes to buySellPage
				{
					return 2;
				}
			}
			window.clear(style.bodyCol);

			//draw (x) to exit and next label on screen
			screenElement addElement;
			addElement.setStyle(style);
			addElement.drawExitText(window);
			addElement.drawNextButton(window);
			//draws upcoming enemies bar based on info from wave object
			addElement.drawEnemyBar(window,titleBar,0,wave.getHostileAmount(),wave.getHostileType());

			//draw title
			window.draw(titleBar);
			window.draw(titleText1);
			window.draw(titleText2);
			
			window.display();
		}


	}
}