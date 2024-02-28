#pragma once
#include "Card.h"

#include <string>
#include <vector>

class Player
{
public:
	Player(std::string name);

	void PurchaseCard(Card& card);
	Card PlayCard(int index);
	const std::vector<Card>& GetHand();

	std::string GetName();

private:
	std::vector<Card> handCards;
	std::string name;

};