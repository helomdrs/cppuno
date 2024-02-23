#include "Card.h"

Card::Card(CardColor color, CardAction action, int number) {
	_data.color = color;
	_data.action = action;
	_data.number = number;
}

//CardData Card::GetCardData() const
//{
//	return _data;
//}