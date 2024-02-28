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

void Displayer::DisplayMatchBoard(Player& player, Card& topCardOnBoard, std::vector<Card>& playerHand)
{
	std::cout << "\n Board: ";
	DisplayCard(topCardOnBoard);

	std::cout << DEFAULT_DISPLAY_COLOR;
	std::cout << HAND_MESSAGE;

	for (int i  = 0; i < playerHand.size(); i++)
	{
		std::cout << DEFAULT_DISPLAY_COLOR;
		std::cout << "[" << i + 1 << "]\t";
		DisplayCard(playerHand[i]);
		std::cout << "\n";
	}
}

void Displayer::DisplayCard(Card& card)
{
	CardData cardData = card.GetCardData();

	switch (cardData.color)
	{
	case Green:
		std::cout << GREEN_DISPLAY_COLOR;
		break;
	case Yellow:
		std::cout << YELLOW_DISPLAY_COLOR;
		break;
	case Blue:
		std::cout << BLUE_DISPLAY_COLOR;
		break;
	case Red:
		std::cout << RED_DISPLAY_COLOR;
		break;
	default:
		std::cout << DEFAULT_DISPLAY_COLOR;
		break;
	}

	if (cardData.action != Number)
	{
		std::cout << "[" << CardActionsIndex[cardData.action] << "]";
		return;
	}
	else
	{
		std::cout << "[" << cardData.number << "]";
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
