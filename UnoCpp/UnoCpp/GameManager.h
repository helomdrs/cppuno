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
#include <optional>

class GameManager
{
public:
	void StartGame();
private:
	const std::unique_ptr<Displayer> displayer = std::make_unique<Displayer>();
	const std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();
	const std::unique_ptr<Deck> deck = std::make_unique<Deck>();

	std::vector<Player> players;

	const int HAND_SIZE = 7;

	int currentOrder = MatchOrder::CW;

	void StartMatch();
	void HandleWrongInput();
	void SetupPlayers();
	void CreatePlayers(int amount);
	void CreatePlayersHands();
	void SetMatchOrder();
	void LoopMatch();
	void UpdateMatchDisplay(Player& player, Card& topCardOnBoard, std::vector<Card>& playerHand);
	int GetCardIndexPlayed(Player& player);
	bool IsCardPlayedValid(Card& topCard, Card& cardPlayed);
	void ToggleCurrentOrder();
	void AskForNextColor();
	int SelectNextPlayer(int playerIndex, bool isBlock);
	void TreatPlayerCardPurchase(Player& player, int amountToBuy);
};