#pragma once

#include "Card.h"
#include "Displayer.h"
#include "Player.h"
#include "Deck.h"
#include "InputManager.h"
#include "ProjectData.h"

#include <memory>
#include <vector>
#include <random>
#include <iostream>

class GameManager
{
public:
	void StartGame();
	void StartMatch();
private:
	std::unique_ptr<Displayer> displayer = std::make_unique<Displayer>();
	std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();
	std::unique_ptr<Deck> deck = std::make_unique<Deck>();

	std::vector<Player> players;

	const int HAND_SIZE = 7;

	int currentOrder = MatchOrder::CW;

	void HandleWrongInput();
	void SetupPlayers();
	void CreatePlayers(int amount);
	void CreatePlayersHands();
	void SetMatchOrder();
};