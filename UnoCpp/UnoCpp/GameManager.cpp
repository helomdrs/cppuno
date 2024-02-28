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
	for (Player plr : players)
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

	while (!gameOver)
	{
		Player player = players[playerIndex];
		Card topCardOnBoard = deck->DrawCard();
		std::vector<Card> playerHand = player.GetHand();
		
		UpdateMatchDisplay(player, topCardOnBoard, playerHand);
		Card cardPlayed = GetCardPlayed(player);

		if (IsCardPlayedValid(topCardOnBoard, cardPlayed))
		{
			//make card action
			switch (cardPlayed.GetCardData().action)
			{
			case Block:
				playerIndex = SelectNextPlayer(playerIndex);
				break;
			case Reverse:
				ToggleCurrentOrder();
				break;
			case PickColor:
				AskForNextColor();
				break;
			case PlusTwo:
				amountForNextPlayerToBuy = 2;
				break;
			case PlusFour:
				amountForNextPlayerToBuy = 4;
				AskForNextColor();
				break;
			}
		}
		else
		{
			//if player chose and invalid card, purchase another one as punishment
			player.PurchaseCard(deck->DrawCard());
		}

		//select next player
		playerIndex = SelectNextPlayer(playerIndex);
	}
}

void GameManager::UpdateMatchDisplay(Player& player, Card& topCardOnBoard, std::vector<Card>& playerHand)
{
	displayer->ClearScreen();
	displayer->DisplayMatchOrder(players, currentOrder);
	displayer->DisplayMatchBoard(player, topCardOnBoard, playerHand);
	displayer->WaitForInput();
}

Card GameManager::GetCardPlayed(Player& player)
{
	std::cout << "Select a card to play by their index between []: ";

	int cardIndex = 0;
	std::cin >> cardIndex;

	if (inputManager->ValidateInput(InputMoments::CardChoice, cardIndex))
	{
		return player.PlayCard(cardIndex);
	}
	else
	{
		HandleWrongInput();
		GetCardPlayed(player);
	}
}

bool GameManager::IsCardPlayedValid(const Card& topCard, const Card& cardPlayed)
{
	bool isValid = false;

	CardData topCardData = topCard.GetCardData();
	CardData cardPlayedData = cardPlayed.GetCardData();

	if ((topCardData.color == cardPlayedData.color or topCardData.number == cardPlayedData.number) or cardPlayedData.color == Black)
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

int GameManager::SelectNextPlayer(int playerIndex)
{
	if (currentOrder == CW)
	{
		playerIndex++;
	}
	else
	{
		playerIndex--;
	}
	
	if ((playerIndex > players.size()) or (playerIndex < 0))
	{
		playerIndex = 0;
	}

	return playerIndex;
}

void GameManager::HandleWrongInput()
{
	std::cout << "Your input is invalid, please choose correctly" << std::endl;
	displayer->WaitForInput(); 
}