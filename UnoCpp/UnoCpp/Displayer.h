#pragma once

#include "ProjectData.h"
#include "Player.h"

#include <stdlib.h>
#include <iostream>
#include <vector>

class Displayer
{
public:
	void DisplayStartScreen();
	void DisplayEndScreen();
	void UpdateMatchScreen();
	void DisplayPlayerHand();
	void ClearScreen();
	void WaitForInput();
	void DisplayHeader();
	void CloseScreen();
	void DisplayMatchOrder(std::vector<Player>& players, int& order);

private:
	const char* DEFAULT_DISPLAY_COLOR = "\033[0m";
	const char* RED_DISPLAY_COLOR = "\033[1m\033[31m";
	const char* YELLOW_DISPLAY_COLOR = "\033[1m\033[33m";
	const char* BLUE_DISPLAY_COLOR = "\033[1m\033[34m";
	const char* GREEN_DISPLAY_COLOR = "\033[1m\033[32m";

	const char* UNO_HEADER = "\033[1m\033[33m ----------- \033[1m\033[31m U \033[1m\033[34m N \033[1m\033[32m O \033[1m\033[33m---------- \n";
	
	const char* WELCOME_MESSAGE = "Welcome to Uno Console Game!";
	
	const char* RULES_DESCRIPTION = "Rules of UNO:\n - Each player can discard one card per turn.\n - Each player can buy only one card per turn if necessary.\n - +4 cards can't be stacked with +2 cards, only with other +4.\n - +2 cards can be stacked with a +4 card.\n\n Wild Cards:\n [PC] Pick Color\n [R] Reverse\n [B] Block\n\n";
	
	const char* START_MENU_OPTIONS = "Please select one of the options bellow.\n[1] Start Game\n[2] Exit";

	const char* CLOCKWISE_DIRECTION = " > ";
	const char* COUNTERCLOCKWISE_DIRECTION = " < ";
};