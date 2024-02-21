#pragma once

#include "Card.h"
#include "Displayer.h"
#include "Player.h"
#include "Deck.h"
#include "InputManager.h"

#include <memory>

class GameManager
{
public:
	void StartGame();
	void StartMatch();
private:
	std::unique_ptr<Displayer> displayer = std::make_unique<Displayer>();
	std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();

	void HandleWrongInput();
};