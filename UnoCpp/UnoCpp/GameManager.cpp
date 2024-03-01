#include "GameManager.h"

void GameManager::StartGame()
{
	displayer->DisplayStartScreen();

	int choice;
	std::cin >> choice;

	if (inputManager->ValidateInput(InputMoments::StartMenu, choice))
	{
		if (choice == 1)
		{
			StartMatch();
		}
		else if (choice == 2)
		{
			displayer->CloseScreen();
		}
	} 
	else 
	{
		HandleWrongInput();
		displayer->ClearScreen();
		StartGame();
	}
}

void GameManager::StartMatch()
{
	SetupPlayers();
	CreatePlayersHands();

	displayer->ClearScreen();
	SetMatchOrder();
	LoopMatch();
}

void GameManager::SetupPlayers()
{
	displayer->ClearScreen();
	std::cout << "How many players will play this match?" << std::endl;
	
	int playerAmount;
	std::cin >> playerAmount;

	if (inputManager->ValidateInput(InputMoments::PlayerQuantity, playerAmount))
	{
		CreatePlayers(playerAmount);
	}
	else
	{
		HandleWrongInput();
		SetupPlayers();
	}

}

void GameManager::CreatePlayers(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		std::string playerName = "Player " + std::to_string(i + 1);
		Player player{ playerName };
		players.emplace_back(player);
	} 
}

void GameManager::CreatePlayersHands()
{
	for (Player& plr : players)
	{
		for (int i = 0; i < HAND_SIZE; i++)
		{
			Card& cardToPlayer = deck->DrawCard();
			plr.PurchaseCard(cardToPlayer);
		}
	}
}

void GameManager::SetMatchOrder()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(players), std::end(players), rng);
	displayer->DisplayMatchOrder(players, currentOrder);
}

void GameManager::LoopMatch()
{
	bool gameOver = false;
	int playerIndex = 0;
	int amountForNextPlayerToBuy = 0;
	Card& topCardOnBoard = deck->DrawCard();

	while (!gameOver)
	{
		Player& player = players[playerIndex];
		std::vector<Card>& playerHand = player.GetHand();
		
		UpdateMatchDisplay(player, topCardOnBoard, playerHand);

		int cardPlayedIndex = GetCardIndexPlayed(player);

		if (cardPlayedIndex > 0)
		{
			// -1 because I applied + 1 to display the card index starting with 1 instead of 0
			cardPlayedIndex -= 1;
			Card& cardPlayed = player.PlayCard(cardPlayedIndex); 

			if (IsCardPlayedValid(topCardOnBoard, cardPlayed))
			{
				//make card action
				switch (cardPlayed.GetCardData().action)
				{
				case Block:
					playerIndex = SelectNextPlayer(playerIndex, true);
					break;
				case Reverse:
					ToggleCurrentOrder();
					break;
				case PickColor:
					AskForNextColor();
					break;
				case PlusTwo:
					amountForNextPlayerToBuy += 2;
					break;
				case PlusFour:
					amountForNextPlayerToBuy += 4;
					AskForNextColor();
					break;
				}

				topCardOnBoard = cardPlayed;

				//remove card from player hand and put it on discard pile
				deck->DiscardCard(cardPlayed);
				player.RemoveCard(cardPlayedIndex);
			}
			else
			{
				TreatPlayerCardPurchase(player, amountForNextPlayerToBuy);
				amountForNextPlayerToBuy = 0;
			}
		}
		else
		{
			TreatPlayerCardPurchase(player, amountForNextPlayerToBuy);
			amountForNextPlayerToBuy = 0;
		}

		//select next player
		playerIndex = SelectNextPlayer(playerIndex, false);
	}
}

void GameManager::TreatPlayerCardPurchase(Player& player, int amountToBuy)
{
	// if there's no card to be played or player chose an invalid card, purchase the amount indicated
	if (amountToBuy > 0)
	{
		for (int i = 0; i < amountToBuy; i++)
		{
			player.PurchaseCard(deck->DrawCard());
		}

		amountToBuy = 0;
	}
	else
	{
		player.PurchaseCard(deck->DrawCard());
	}
}

void GameManager::UpdateMatchDisplay(Player& player, Card& topCardOnBoard, std::vector<Card>& playerHand)
{
	displayer->ClearScreen();
	displayer->DisplayMatchOrder(players, currentOrder);
	displayer->DisplayMatchBoard(player, topCardOnBoard, playerHand);
}

int GameManager::GetCardIndexPlayed(Player& player)
{
	std::cout << "Select a card to play by their index between []: ";

	int cardIndex = 0;
	std::cin >> cardIndex; 

	//check if player passed their turn
	if (cardIndex == 0)
		return 0;

	if (cardIndex <= static_cast<int>(player.GetHand().size()))
	{
		return cardIndex;
	}
	else
	{
		HandleWrongInput();
		GetCardIndexPlayed(player);
	}
}

bool GameManager::IsCardPlayedValid(Card& topCard, Card& cardPlayed)
{
	bool isValid = false;

	CardData topCardData = topCard.GetCardData();
	CardData cardPlayedData = cardPlayed.GetCardData();

	bool hasTheSameColor = topCardData.color == cardPlayedData.color;
	bool hasTheSameNumber = topCardData.number == cardPlayedData.number;
	bool isWildCard = cardPlayedData.color == Black;

	if ((hasTheSameColor or hasTheSameNumber) or isWildCard)
	{
		isValid = true;
	}

	return isValid;
}

void GameManager::ToggleCurrentOrder()
{
	if (currentOrder == CW)
	{
		currentOrder = CCW;
	}
	else
	{
		currentOrder = CW;
	}
}

void GameManager::AskForNextColor()
{
	//ask the player to the next color desired
}

int GameManager::SelectNextPlayer(int playerIndex, bool isBlock)
{
	if (currentOrder == CW)
	{
		playerIndex++;

		if (playerIndex >= static_cast<int>(players.size()))
		{
			if (isBlock)
				playerIndex = 1;
			else
				playerIndex = 0;
		}
	}
	else
	{
		playerIndex--;

		if (playerIndex < 0)
		{
			if (isBlock)
				playerIndex = (static_cast<int>(players.size()) - 1);
			else
				playerIndex = 0;
		}
	}

	return playerIndex;
}

void GameManager::HandleWrongInput()
{
	std::cout << "Your input is invalid, please choose correctly" << std::endl;
	displayer->WaitForInput(); 
}