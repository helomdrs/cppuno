#include "GameManager.h"
#include <iostream>

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
	CreateDeck();
	// shuffle deck
	// handle cards to players
	// select one card to start the board
	// call match loop
}

void GameManager::SetupPlayers()
{
	displayer->ClearScreen();
	displayer->DisplayHeader();
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

void GameManager::CreateDeck()
{

}

void GameManager::CreatePlayersHands()
{
}

void GameManager::HandleWrongInput()
{
	std::cout << "Your input is invalid, please choose correctly" << std::endl;
	displayer->WaitForInput(); 
}