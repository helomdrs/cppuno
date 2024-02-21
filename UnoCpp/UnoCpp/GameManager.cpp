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
	std::cout << "GO TO GAME";
}

void GameManager::HandleWrongInput()
{
	std::cout << "Your input is invalid, please choose correctly" << std::endl;
	displayer->WaitForInput(); 
}