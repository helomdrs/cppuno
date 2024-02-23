#include "Displayer.h"

void Displayer::DisplayHeader()
{
	//display the uno red header
	std::cout << UNO_HEADER;
	std::cout << DEFAULT_DISPLAY_COLOR;
}

void Displayer::CloseScreen()
{
	std::cout << "Closing the application :c" << std::endl;
	exit(0);
}

void Displayer::DisplayMatchOrder(std::vector<Player>& players, int& order)
{
	const char* currentOrder;
	if (order == MatchOrder::CW)
	{
		currentOrder = CLOCKWISE_DIRECTION;
	}
	else
	{
		currentOrder = COUNTERCLOCKWISE_DIRECTION;
	}

	std::cout << "Match order is: ";
	for (Player plr : players)
	{
		std::cout << plr.GetName() << currentOrder;
	}
}

void Displayer::DisplayStartScreen()
{
	// display the first screen
	DisplayHeader();
	std::cout << WELCOME_MESSAGE << std::endl;
	std::cout << RULES_DESCRIPTION << std::endl;
	std::cout << START_MENU_OPTIONS << std::endl;
}

void Displayer::DisplayEndScreen()
{
	// display the winner screen
}

void Displayer::UpdateMatchScreen()
{
	// update the match screen with the top of the discard pile, the amount of cards remaining in draw pile and the player hand
}

void Displayer::DisplayPlayerHand()
{
	// display the cards in the players hand
}

void Displayer::ClearScreen()
{
	system("cls");
	DisplayHeader();
}

void Displayer::WaitForInput()
{
	system("pause");
}
