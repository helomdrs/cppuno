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
		isChoiceValid = ValidatePlayerQuantityInput(choice);
		break;
	case InputMoments::CardChoice:
		isChoiceValid = ValidateCardChoiceInput(choice);
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
	return true;

	//comeback here later, this is returning false, need to find a way to validate if this is a number or not
	//return isdigit(choice);
}

bool InputManager::ValidateCardChoiceInput(int choice)
{
	return true;
}

