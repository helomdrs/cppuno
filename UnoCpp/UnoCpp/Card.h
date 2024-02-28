#pragma once

#include "ProjectData.h"

struct CardData
{
	CardColor color;
	CardAction action;
	int number;
};

class Card 
{
public:
	Card(CardColor& color, CardAction& action, int& number);
	CardData GetCardData() const;
private:
	CardData _data;
};