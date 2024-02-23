#include "Player.h"
#include "Card.h"

Player::Player(std::string name)
{
	_name = name;
}

//void Player::PurchaseCard(Card card)
//{
//	 insert card on _handCards list
//}
//
//Card Player::PlayCard()
//{
//	 chose a card from the player hand to return so deck can check if its valid
//}
//
//std::string* Player::GetName()
//{
//	return &_name;
//}