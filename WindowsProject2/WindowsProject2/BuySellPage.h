#pragma once
#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "WindowsProject2.h"
#include <SFML/Graphics.hpp>
class BuySellPage : public cScreen
{
public:
	virtual int Run(sf::RenderWindow &window);
};

int BuySellPage::Run(sf::RenderWindow &window)
{
	//I found this came in handy for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;


	//To add texture or font add to file WindowsProject2 in file WindowsProject2 (the below files will be there)
	//loading font
	sf::Font font;
	font.loadFromFile("atwriter.ttf");

	// texture example
	sf::Texture pixelHeart;
	pixelHeart.loadFromFile("PixelHeart.png");
	sf::Sprite sprite;
	sprite.setTexture(pixelHeart);
	sprite.setScale(0.05, 0.05);

	// add texture to rectangle object
	sf::Texture texture;
	texture.loadFromFile("enemyTexture.jpg");

	sf::RectangleShape enemyImage(sf::Vector2f(50, 50));
	enemyImage.setTexture(&texture);

	//define things to be added to window later
	//if you want you can stick code you are repeating alot in a function in screenElement.h


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
					return 3;
				}
			}
			window.clear();
			window.draw(enemyImage);
			window.draw(sprite);
			//window.draw(), stuff defined above to window
			window.display();
		}

	}
}