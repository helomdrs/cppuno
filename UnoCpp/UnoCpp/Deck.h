#pragma once
#include "Card.h"

#include <vector>

class Deck
{
public:
	Deck();

	//Card DrawCard();
	//Card DiscardCard();

	//void GivePlayerHand();
	//void RefillDrawPile();

private:
	std::vector<Card> _drawPile;
	std::vector<Card> _discardPile;

	const int DECK_SIZE = 72;
	const int HAND_SIZE = 7;
	const int COLOR_QUANTITY = 4;
	const int REVESE_PER_COLOR = 2;
	const int PLUSTWO_PER_COLOR = 2;
	const int BLOCK_PER_COLOR = 2;
	const int PLUSFOUR_PER_DECK = 4;
	const int PICKCOLOR_PER_DECK = 4;
	const int MIN_NUMBER = 0;
	const int MAX_NUMBER = 9;

	//bool ValidateDiscard(Card& cardDiscarted);

	void CreateCards(CardColor color);
	void CreateWildCards();
	void CreateCardInDeck(CardColor color, CardAction action, int number);
	void ShuffleDeck();
};