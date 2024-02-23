#pragma once

enum InputMoments
{
	StartMenu,
	PlayerQuantity,
	CardChoice
};

class InputManager
{
public:
	bool ValidateInput(InputMoments moment, int choice);

private:
	bool ValidateStartMenuInput(int choice);
	bool ValidatePlayerQuantityInput(int choice);
	bool ValidateCardChoiceInput(int choice);
};