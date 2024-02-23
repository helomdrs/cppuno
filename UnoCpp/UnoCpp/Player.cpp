#include "Player.h"
#include "Card.h"

#include <iostream>

Player::Player(std::string name)
{
	_name = name;
}

void Player::PurchaseCard(Card card)
{
	_handCards.emplace_back(card);
}

//Card Player::PlayCard()
//{
//	 chose a card from the player hand to return so deck can check if its valid
//}
//
std::string Player::GetName()
{
	return _name;
}