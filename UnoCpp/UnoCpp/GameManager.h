#pragma once

#include "Card.h"
#include "Displayer.h"
#include "Player.h"
#include "Deck.h"

#include <memory>

class GameManager
{
public:
	void StartGame();
	void StartMatch();
private:
	std::unique_ptr<Displayer> displayer = std::make_unique<Displayer>();
};