#include "Deck.h"

Deck::Deck()
{
	// create all cards here and put it on draw pile
	CreateCards(CardColor::Yellow);
	CreateCards(CardColor::Red);
	CreateCards(CardColor::Green);
	CreateCards(CardColor::Blue);
	CreateWildCards();
	ShuffleDeck();
}

void Deck::CreateCards(CardColor color)
{
	// number cards
	for (int i = MIN_NUMBER; i <= MAX_NUMBER; i++)
	{
		CreateCardInDeck(color, CardAction::Number, i);
	}

	// reverse cards
	for (int i = 0; i < REVESE_PER_COLOR; i++)
	{
		CreateCardInDeck(color, CardAction::Reverse, -1);
	}

	// block cards
	for (int i = 0; i < BLOCK_PER_COLOR; i++)
	{
		CreateCardInDeck(color, CardAction::Block, -1);
	}

	// +2 cards
	for (int i = 0; i < PLUSTWO_PER_COLOR; i++)
	{
		CreateCardInDeck(color, CardAction::PlusTwo, -1);
	}
}

void Deck::CreateWildCards()
{
	for (int i = 0; i < PLUSFOUR_PER_DECK; i++)
	{
		CreateCardInDeck(CardColor::Black, CardAction::PlusFour, -1);
	}

	for (int i = 0; i < PICKCOLOR_PER_DECK; i++)
	{
		CreateCardInDeck(CardColor::Black, CardAction::PickColor, -1);
	}
}

void Deck::CreateCardInDeck(CardColor color, CardAction action, int number)
{
	Card card{ color, action, number };
	_drawPile.emplace_back(card);
}

void Deck::ShuffleDeck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(_drawPile), std::end(_drawPile), rng);
}

Card Deck::DrawCard()
{
	if (_drawPile.size() == 0)
	{
		RefillDrawPile();
	}

	Card cardToDraw = _drawPile.back();
	_drawPile.pop_back();
	return cardToDraw;
}
//
//Card Deck::DiscardCard()
//{
//	// push card to the discard pile
//}
//
//
void Deck::RefillDrawPile()
{
	while (!_discardPile.empty())
	{
		_drawPile.emplace_back(_discardPile.back());
		_discardPile.pop_back();
	}

	ShuffleDeck();
}
//
//bool Deck::ValidateDiscard(Card& cardDiscarted)
//{
//	// validate number and color of card with the top of discard pile
//}
