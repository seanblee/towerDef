
#include <iostream>
#include <fstream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "BuySellPage.h"
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "TowerManager.h"

int BuySellPage::Run(sf::RenderWindow &window)
{
	//I found this came in handy for positioning
	WINDOWINFO wiInfo;
	GetWindowInfo(window.getSystemHandle(), &wiInfo);
	int widthWin = wiInfo.rcClient.right - wiInfo.rcClient.left;
	int heightWin = wiInfo.rcClient.bottom - wiInfo.rcClient.top;

	//initializing flags and logic variables
	int confirmWindowFlag(0);
	state = 0;
	tower = 0;
	int selected(0);
	int testIntMap(-2);

	//getting style
	GUIStyle style(getStyle());

	//initializing default cursor
	sf::Sprite defaultCursor;
	defaultCursor.setTexture(spriteSheet);
	defaultCursor.setTextureRect(sf::IntRect(0, 0, 25, 25));
	defaultCursor.setColor(style.bodyCol);
	cursor cur(defaultCursor);

	//allll of the messages i print
	string easyPathMap("path1.jpg");
	vector<string> userMessage;
	userMessage.push_back("Buy some towers");
	userMessage.push_back("[1] [2] [3] Select\n\n[enter] Start [s] Sell");
	userMessage.push_back("Ready?");
	userMessage.push_back("\n\n\n[Enter] Continue\n\n\n[Backspace] Back");
	userMessage.push_back("Error:\n\nCannot build \n\non path");
	userMessage.push_back("Error:\n\nTower already\n\nplaced");
	userMessage.push_back("\n[1] Deselect\n\n[space] Place");
	userMessage.push_back("\n[2] Deselect\n\n[space] Place");
	userMessage.push_back("\n[3] Deselect\n\n[space] Place");
	userMessage.push_back("Error: Not\n\nenough money");
	userMessage.push_back("\n\n\n[enter] Continue");
	userMessage.push_back(" ");
	path easyPath(easyPathMap, 20, 14);

	
	
	//prices of towers
	//get prices from towermanager
	string price1 = to_string(2);
	string price2 = to_string(4);
	string price3 = to_string(6);

	//tower prices display message - stored in string vector
	vector<string> towerPrices;
	string temp;
	temp = "Tower 1: $" + price1;
	towerPrices.push_back(temp);
	temp = "Tower 2: $" + price2;
	towerPrices.push_back(temp);
	temp = "Tower 3: $" + price3;
	towerPrices.push_back(temp);
	
	//getting map 2d array
	fstream mapFile;
	mapFile.open("Intmap.txt");
	int intMap[20][16];

	while (mapFile.is_open()) {
		for (int row = 0; row < 16; row++) {
			for (int col = 0; col < 20; col++) {
				mapFile >> intMap[col][row];
			}
		}
		mapFile.close();
	}

	//HP and money - stored in Player
	int HP(user->getHP());
	int money(user->getMoney());

	//initializing overlays displayed in top right of screen
	pathOverlays overlays;
	overlays.setStyle(style);
	overlays.setMessage(userMessage[0]);
	overlays.setOptions(userMessage[1]);
	overlays.setHP(HP);
	overlays.setMoney(money);
	buySell buySellOverlay(3, spriteSheet, style);

	//confirm window
	sf::RectangleShape confirmOverlay(sf::Vector2f(1000, 700));
	confirmOverlay.setPosition(0, 0);
	confirmOverlay.setFillColor(sf::Color(0, 0, 0, 100));
	sf::RectangleShape confirmBorder(sf::Vector2f(400, 200));
	style.setStyle(confirmBorder);
	confirmBorder.setPosition(300, 250);
	sf::Text confirmTitle(userMessage[2], style.font, 27);
	confirmTitle.setPosition(325, 275);
	sf::Text confirmOptions(userMessage[3], style.font, 16);
	confirmOptions.setPosition(345, 305);

	//window loop
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
				if (event.key.code == sf::Keyboard::X) {
					window.close();
					return -1;
				}
				
				selected = -1;
				if (event.key.code == sf::Keyboard::Return) {
					//if cursor empty and not selling, then enter loop
					if ((state == 0 && tower == 0)) {
						//if the confirm window isn't displaying, display confirm window
						if (confirmWindowFlag == 0) {
							confirmWindowFlag = 1;
						}
						else //otherwise go to waveRunningPage
							return 3;
					}
				}
				//if user hits space and a tower is selected, buy and place tower in cursor location
				else if ((event.key.code == sf::Keyboard::Space) && state == 1) {
					testIntMap = intMap[cur.getX()][cur.getY()];
					//put tower in cursor location
					if (testIntMap == -1) { //if attempting to place in path, display error and return
						overlays.setMessage(userMessage[4]);
						overlays.setOptions(userMessage[11]);
						break;
					}
					else if (testIntMap != 0) { //if trying to place over another tower, display error and return
						overlays.setMessage(userMessage[5]);
						overlays.setOptions(userMessage[11]);
						break;
					}

					//money check - if purchase not possible, display error and return
					//**** change to actual tower price later
					money = money - (tower * 2);
					if (money < 0) {
						overlays.setMessage(userMessage[9]);
						overlays.setOptions(userMessage[10]);
						tower = 0;
						state = 0;
						break;
					}
					//otherwise, set the tower and money value
					intMap[cur.getX()][cur.getY()] = tower;
					sf::Sprite newTowerSprite(cur.cursorImage);
					Tower newTower(newTowerSprite);
					BuySellManager->addTower(newTower);
					overlays.setOptions(userMessage[tower + 5]);
					overlays.setMessage(towerPrices[tower - 1]);

					overlays.setMoney(money);
				}

				//if user hit backspace from the confirm window, return to buySellPage
				else if (event.key.code == sf::Keyboard::BackSpace && confirmWindowFlag == 1) {
					confirmWindowFlag = 0;
				}

				//checking for towers being selected - if selected, display message
				else if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) {
					selected = 1;
					overlays.setOptions(userMessage[6]);
					
				}
				else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) {
					selected = 2;
					overlays.setOptions(userMessage[7]);
				}
				else if (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3) {
					selected = 3;
					overlays.setOptions(userMessage[8]);
				}

				//change logic values, set tower to one
				if (selected != tower && selected != -1) {
					if (state == 0) {
						state = 1;
					}
					tower = selected;
					cur.changeCursor(buySellOverlay.getTower(selected));
					overlays.setMessage(towerPrices.at((selected - 1)));
				}
				//if tower already selected, change cursor back to default
				else if (selected == tower) {
					tower = 0;
					state = 0;
					cur.changeCursor(defaultCursor);
					overlays.setMessage(userMessage[0]);
					overlays.setOptions(userMessage[1]);
				}
				//cursor move logic - checking arrow keys
				cur.moveCursor();

			}


			//drawing everything
			window.clear();
			window.draw(easyPath.pathImage); //map image
			BuySellManager->drawTowers(window); //all of the towers bought
			window.draw(cur.cursorImage); //cursor

			//overlay at bottom of screen 
			window.draw(buySellOverlay.getBorder(1));
			window.draw(buySellOverlay.getTower(1));
			window.draw(buySellOverlay.getText(1));
			window.draw(buySellOverlay.getBorder(2));
			window.draw(buySellOverlay.getTower(2));
			window.draw(buySellOverlay.getText(2));
			window.draw(buySellOverlay.getBorder(3));
			window.draw(buySellOverlay.getTower(3));
			window.draw(buySellOverlay.getText(3));

			//top right overlay
			window.draw(overlays.backing);
			window.draw(overlays.getHP());
			window.draw(overlays.getMoney());
			window.draw(overlays.getMessage());
			window.draw(overlays.getOptions());

			//confirm window
			if (confirmWindowFlag == 1) {
				window.draw(confirmOverlay);
				window.draw(confirmBorder);
				window.draw(confirmTitle);
				window.draw(confirmOptions);
			}


			window.display();
		}

	}
}


int BuySellPage::getTowerNum() {
	return tower;
}
int BuySellPage::getState() {
	return state;
}
void BuySellPage::setTowerNum(int towerNum) {
	tower = towerNum;
}
void BuySellPage::setState(int status) {
	state = status;
}