#pragma once
#include "Card.h"

#include <string>
#include <vector>

class Player
{
public:
	Player(std::string name);

	void PurchaseCard(Card card);
	//Card PlayCard();

	//std::string* GetName();

private:
	std::vector<Card> _handCards;
	std::string _name;
};