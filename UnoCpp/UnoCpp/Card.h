#pragma once

enum CardColor
{
	Black,
	Red,
	Yellow,
	Blue,
	Green
};

enum CardAction
{
	Number,
	Block,
	Reverse,
	PickColor,
	PlusTwo,
	PlusFour
};

struct CardData
{
	CardColor color;
	CardAction action;
	int number;
};

class Card 
{
public:
	Card(CardColor color, CardAction action, int number = -1);
	CardData GetCardData() const;
private:
	CardData _data;
};