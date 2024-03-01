#include "Player.h"
#include "Card.h"

#include <iostream>

Player::Player(std::string _name)
{
	name = _name;
}

void Player::PurchaseCard(Card& card)
{
	handCards.push_back(card);
}

std::vector<Card>& Player::GetHand()
{
	return handCards;
}

Card& Player::PlayCard(int index)
{
	return handCards[index];
}

void Player::RemoveCard(int index)
{
	handCards.erase(handCards.begin() + index);
}

std::string Player::GetName()
{
	return name;
}