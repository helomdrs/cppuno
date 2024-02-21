#include "InputManager.h"

bool InputManager::ValidateInput(InputMoments moment, int choice)
{
	bool isChoiceValid = false;

	switch (moment)
	{
	case InputMoments::StartMenu:
		isChoiceValid = ValidateStartMenuInput(choice);
		break;
	case InputMoments::PlayerQuantity:
		//check if input is valid for player quantity
		break;
	case InputMoments::CardChoice:
		//check if input is valid for card choice
		break;
	}

	return isChoiceValid;
}

bool InputManager::ValidateStartMenuInput(int choice)
{
	if (choice == 1 or choice == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::ValidatePlayerQuantityInput(int choice)
{
	return false;
}

bool InputManager::ValidateCardChoiceInput(int choice)
{
	return false;
}

