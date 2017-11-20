
#include <iostream>
#include <fstream>
#include <string>
#include "cScreen.h"
#include "stdafx.h"
#include "BuySellPage.h"
#include <SFML/Graphics.hpp>

int BuySellPage::Run(sf::RenderWindow &window)
{

	//initialize state and tower to 0
	state = 0;
	tower = 0;

	//initializing flags used in input logic
	int confirmWindowFlag(0); //flag raised when enter's hit
	int selected(0);
	int testIntMap(-2); 

	//get style from cScreen
	GUIStyle style(getStyle());

	//make the default cursor - when state is zero, the cursor is this sprite
	sf::Sprite defaultCursor;
	defaultCursor.setTexture(spriteSheet);
	defaultCursor.setTextureRect(sf::IntRect(0, 0, 25, 25));
	defaultCursor.setColor(style.bodyCol);

	//initialize cursor
	cursor cur(defaultCursor);

	

	//allll of the messages im printing
	vector<string> userMessage;
	userMessage.push_back("Buy some towers");
	userMessage.push_back("[1] [2] [3] Select\n\n[enter] Start game");
	userMessage.push_back("Ready?");
	userMessage.push_back("\n\n\n[Enter] Continue\n\n\n[Backspace] Back");
	userMessage.push_back("Error:\n\nCannot build \n\non path");
	userMessage.push_back("Error:\n\nTower already\n\nplaced");
	userMessage.push_back("Tower 1: $20");
	userMessage.push_back("\n[1] Deselect\n\n[space] Place");
	userMessage.push_back("Tower 2: $40");
	userMessage.push_back("\n[2] Deselect\n\n[space] Place");
	userMessage.push_back("Tower 3: $60");
	userMessage.push_back("\n[3] Deselect\n\n[space] Place");
	userMessage.push_back("Error: Not\n\nenough money");
	userMessage.push_back("\n\n\n[enter] Continue");
	userMessage.push_back(" ");

	//load path image - like, the background image
	string easyPathMap("path1.jpg");
	path easyPath(easyPathMap, 20, 14);

	//vector to store towers after they're placed
	vector<sf::Sprite>towersBought;

	//read map values from text file and store in intMap 2d array
	//0 is not path, -1 is path
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

	//HP and money - later will be passed from other places
	int HP = 100;
	int money = 200;

	//initializing overlays - status things in top right
	pathOverlays overlays;
	overlays.setStyle(style);
	overlays.setMessage(userMessage[0]);
	overlays.setOptions(userMessage[1]);
	overlays.setHP(HP);
	overlays.setMoney(money);
	//tower options at bottom
	buySell buySellOverlay(3, spriteSheet, style);

	//confirm message that displays when user hits enter
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

	//actual running code
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

			//logic for handling key presses
			if (event.type == sf::Event::KeyPressed)
			{
				//if it's x, close window
				if (event.key.code == sf::Keyboard::X) {
					window.close();
					return -1;
				}
				//initialize selected to -1
				selected = -1;
				//if enter,  either entering confirm window or hitting enter a second time to start wave
				if (event.key.code == sf::Keyboard::Return) {

					if ((state == 0 && tower == 0)) {
						//if cursor empty,  set flag to 1
						if (confirmWindowFlag == 0) {
							confirmWindowFlag = 1;
						}
						//if flag was already raised, go to waveRunningPage
						else
							return 3;
					}
				}
				//if space, user trying to place tower
				else if ((event.key.code == sf::Keyboard::Space) && state == 1) {
					testIntMap = intMap[cur.getX()][cur.getY()];
					//put tower in cursor location
					if (testIntMap == -1) { //if attempting to place in path, display error and return
						overlays.setMessage(userMessage[4]);
						overlays.setOptions(userMessage[14]);
						break;
					}
					else if (testIntMap != 0) { //if trying to place over another tower, display error and return
						overlays.setMessage(userMessage[5]);
						overlays.setOptions(userMessage[14]);
						break;
					}
					//check if user has enough money - if not, return error message and break
					money = money - (tower * 20);
					if (money < 0) {
						overlays.setMessage(userMessage[12]);
						overlays.setOptions(userMessage[13]);
						//can go directly to confirm message without having to deselect the tower
						tower = 0;
						state = 0;
						break;
					}
					//if all checks passed, place tower

					//change the number at the cursor location in 2d array to the tower number
					intMap[cur.getX()][cur.getY()] = tower;
					//make a new sprite with the tower sprite, push into vector of towers placed
					sf::Sprite newTowerSprite(cur.cursorImage);
					towersBought.push_back(newTowerSprite);

					//once placed, resets the message in the top right to the tower
					overlays.setMessage(userMessage[(tower*2) + 4]);
					overlays.setOptions(userMessage[(tower * 2) + 5]);
					//set the money
					overlays.setMoney(money);

				}

				//from confirm window, if user hits backspace, send user back to buySell page
				else if (event.key.code == sf::Keyboard::BackSpace && confirmWindowFlag == 1) {
					confirmWindowFlag = 0;
				}

				//selecting towers, change the cursor to the tower sprite; both the numbers at the top and numPad works
				//selected is the tower number, and set message corresponding to the message
				else if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) {
					selected = 1; 
					overlays.setMessage(userMessage[6]);
					overlays.setOptions(userMessage[7]);
				}
				else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) {
					selected = 2;
					overlays.setMessage(userMessage[8]);
					overlays.setOptions(userMessage[9]);
				}
				else if (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3) {
					selected = 3;
					overlays.setMessage(userMessage[10]);
					overlays.setOptions(userMessage[11]);
				}
				//if something was selected
				if (selected != tower && selected != -1) {
					//if state was 0, set it to 1 since user is now trying to buy
					if (state == 0) {
						state = 1;
					}
					//set tower to the one selected
					tower = selected;
					cur.changeCursor(buySellOverlay.getTower(selected));
				}
				//if user hit tower number again, clear cursor to default
				else if (selected == tower) {
					tower = 0;
					state = 0;
					cur.changeCursor(defaultCursor);
					overlays.setMessage(userMessage[0]);
					overlays.setOptions(userMessage[1]);
				}
				//logic to move cursor
				cur.moveCursor();

			}

			//draw everything

			window.clear();
			window.draw(easyPath.pathImage); //path image
			
			//tower sprites
			for (sf::Sprite i : towersBought) {
				window.draw(i);
			}

			//cursor
			window.draw(cur.cursorImage);

			//tower options at the bottom
			window.draw(buySellOverlay.getBorder(1));
			window.draw(buySellOverlay.getTower(1));
			window.draw(buySellOverlay.getText(1));
			window.draw(buySellOverlay.getBorder(2));
			window.draw(buySellOverlay.getTower(2));
			window.draw(buySellOverlay.getText(2));
			window.draw(buySellOverlay.getBorder(3));
			window.draw(buySellOverlay.getTower(3));
			window.draw(buySellOverlay.getText(3));

			//window in top right
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