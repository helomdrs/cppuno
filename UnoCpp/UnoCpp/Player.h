#pragma once
#include "Card.h"

#include <string>
#include <list>

class Player
{
public:
	Player(std::string name);

	/*void PurchaseCard(Card card);
	Card PlayCard();

	std::string* GetName();*/

private:
	std::list<Card> _handCards;
	std::string _name;
};