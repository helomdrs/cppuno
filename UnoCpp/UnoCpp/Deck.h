#pragma once
#include "Card.h"

#include <stack>

class Deck
{
public:
	Deck();

	Card DrawCard();
	Card DiscardCard();

	void GivePlayerHand();
	void RefillDrawPile();

private:
	std::stack<Card> _drawPile;
	std::stack<Card> _discardPile;

	const int DECK_SIZE = 104;
	const int HAND_SIZE = 7;
	const int REVESE_PER_COLOR = 2;
	const int PLUSTWO_PER_COLOR = 2;
	const int BLOCK_PER_COLOR = 2;
	const int PLUSFOUR_PER_DECK = 4;
	const int PICKCOLOR_PER_DECK = 4;
	const int MIN_NUMBER = 0;
	const int MAX_NUMBER = 9;

	bool ValidateDiscard(Card& cardDiscarted);
};