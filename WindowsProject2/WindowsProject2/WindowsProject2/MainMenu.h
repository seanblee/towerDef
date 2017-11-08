#pragma once
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
#include "screenElement.h"
class MainMenu : public cScreen
{
public:
	virtual int Run(sf::RenderWindow &window);
};

int MainMenu::Run(sf::RenderWindow &window)
{

	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	int startWidth = 400;
	int startHeight = 150;

	sf::RectangleShape start(sf::Vector2f(startWidth, startHeight));
	start.setFillColor(sf::Color(60, 130, 230));
	start.setOutlineThickness(3);
	start.setOutlineColor(sf::Color(0, 0, 0));
	start.setPosition(widthWin / 2 - (startWidth / 2), heightWin / 2 - (startHeight / 2));


	sf::Font font;
	font.loadFromFile("atwriter.ttf");


	sf::Text startText1("(Enter) to", font, 20);
	startText1.setFillColor(sf::Color::Black);
	startText1.setPosition(start.getPosition().x + startWidth / 2 - startText1.getLocalBounds().width / 2,
		start.getPosition().y);

	sf::Text startText2("Start Game", font, 50);
	startText2.setFillColor(sf::Color::Black);
	startText2.setPosition(start.getPosition().x + startWidth / 2 - startText2.getLocalBounds().width / 2,
		start.getPosition().y + startHeight / 2 - startText2.getLocalBounds().height / 2);





	sf::Text TitleText1("Madawaska", font, 50);
	TitleText1.setFillColor(sf::Color::Black);
	float widthText = TitleText1.getLocalBounds().width;
	float heightText = TitleText1.getLocalBounds().height;
	TitleText1.setPosition((widthWin / 2) - (widthText / 2), 0);

	sf::Text TitleText2("Tower Defence", font, 50);
	TitleText2.setFillColor(sf::Color::Black);
	widthText = TitleText2.getLocalBounds().width;
	TitleText2.setPosition((widthWin / 2) - (widthText / 2), heightText + 10);




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
					return 1;
				}
			}
		}

		window.clear(sf::Color(80, 90, 100));
		window.draw(start);
		window.draw(TitleText1);
		window.draw(TitleText2);

		screenElement addElement; 
		addElement.drawExitText(window);
		window.draw(startText1);
		window.draw(startText2);
		window.display();
	}

	return 0;
}

