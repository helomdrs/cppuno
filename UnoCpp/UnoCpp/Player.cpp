#include "Player.h"
#include "Card.h"

#include <iostream>

Player::Player(std::string _name)
{
	name = _name;
}

void Player::PurchaseCard(Card& card)
{
	handCards.emplace_back(card);
}

const std::vector<Card>& Player::GetHand()
{
	return handCards;
}

Card Player::PlayCard(int index)
{
	return handCards[index];
}

std::string Player::GetName()
{
	return name;
}