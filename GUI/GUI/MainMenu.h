#pragma once
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "screenElement.h"
#include "Player.h"
#include "TowerManager.h"
#include "WaveDescription.h"
#include "WaveComplete.h"

//Displays star screen and reset variables to starting point when displayed

class MainMenu : public cScreen
{
	TowerManager *towerMan;
	WaveDescription *descriptionPage;
	WaveComplete *waveCompPage;
	Player *user;
public:
	//resetting all variable so when we restart the game we are starting fresh
	void resetGame() {
		towerMan->clearAllTowers();
		descriptionPage->resetScreen();
		waveCompPage->resetScreen();
		user->setHP(1);
		user->setMoney(10);
	}
	MainMenu(GUIStyle& style, TowerManager*& tempMan, WaveDescription*& s1, WaveComplete*& s4, Player*& p) : cScreen(style) {
		towerMan = tempMan;
		descriptionPage = s1;
		waveCompPage = s4;
		user = p;
	}
	virtual int Run(sf::RenderWindow &window);
};

int MainMenu::Run(sf::RenderWindow &window)
{
	resetGame();
	GUIStyle style(getStyle());//loads style

	//needed for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	//draws start label in middle
	int startWidth = 400;
	int startHeight = 150;
	sf::RectangleShape start(sf::Vector2f(startWidth, startHeight));
	start.setFillColor(style.bodyCol);
	start.setOutlineThickness(style.borderSize);
	start.setOutlineColor(style.borderCol);
	start.setPosition(widthWin / 2 - (startWidth / 2), heightWin / 2 - (startHeight / 2));

	//and the start labels text
	sf::Text startText1("(Enter) to", style.font, 20);
	startText1.setFillColor(style.textCol);
	startText1.setPosition(start.getPosition().x + startWidth / 2 - startText1.getLocalBounds().width / 2,
		start.getPosition().y);

	sf::Text startText2("Start Game", style.font, 50);
	startText2.setFillColor(style.textCol);
	startText2.setPosition(start.getPosition().x + startWidth / 2 - startText2.getLocalBounds().width / 2,
		start.getPosition().y + startHeight / 2 - startText2.getLocalBounds().height / 2);




	//writes title
	sf::Text TitleText1("Madawaska", style.font, 50);
	TitleText1.setFillColor(style.textCol);
	float widthText = TitleText1.getLocalBounds().width;
	float heightText = TitleText1.getLocalBounds().height;
	TitleText1.setPosition((widthWin / 2) - (widthText / 2), 0);

	sf::Text TitleText2("Tower Defence", style.font, 50);
	TitleText2.setFillColor(style.textCol);
	widthText = TitleText2.getLocalBounds().width;
	TitleText2.setPosition((widthWin / 2) - (widthText / 2), heightText + 10);




	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {//close window when x-clicked and return -1 to end program
				window.close();
				return -1;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)//close window end program
				{
					window.close();
					return -1;
				}
				if (event.key.code == sf::Keyboard::Return)//go to wavedescription page
				{
					return 1;
				}
			}
		}

		window.clear(style.bodyCol);
		//draw start label in middle
		window.draw(start);
		window.draw(startText1);
		window.draw(startText2);
		//add title
		window.draw(TitleText1);
		window.draw(TitleText2);

		//add (x) to exit to bottom left
		screenElement addElement; 
		addElement.setStyle(style);
		addElement.drawExitText(window);
		
		window.display();
	}

	return 0;
}

