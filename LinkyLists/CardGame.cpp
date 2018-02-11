#pragma once
#include "CardGame.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

/*create_node inserts a card into the players_hand in a sorted fashion
  This function is called from the deal_card function*****************/
void CardGame::create_node(Card card)
{
	players_hand *nodePtr, *previousNodePtr;

	if (head == nullptr || head->hand_card.sort_order >= card.sort_order)
	{
		head = new players_hand(card, head);
	}
	else
	{
		previousNodePtr = head;
		nodePtr = head->next;
		while (nodePtr != nullptr && nodePtr->hand_card.sort_order < card.sort_order)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNodePtr->next = new players_hand(card, nodePtr);
	}
}
/*create_deck creates the deck on program execution
  called by the constructor************************/
void CardGame::create_deck()
{
	string arrName[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	string arrSuit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	//Populate the deck stack
	for (int i = 0; i < num_cards_in_deck; i++)
	{
		Card tempCard = { i,  arrSuit[i / 13], arrName[i % 13] };
		deck.push_back(tempCard);
	}
}
/*shuffle_deck is called by the constructor after create_deck*/
void CardGame::shuffle_deck()
{
	random_shuffle(deck.begin(), deck.end());
}
void CardGame::stack_deck()
{
	for (int i = 0; i < num_cards_in_deck; i++)
	{
		stacked_deck.push(deck[i]);
	}
}
/*deal_card creates the players hand by creating a linked list of cards
  inserted in a sorted fashion up to MAX_INITIAL_CARDS*****************/
void CardGame::deal_card()
{
	Card tempCard;
	for (int i = 0; i < MAX_INITIAL_CARDS; i++)
	{	
		tempCard = stacked_deck.top();
		stacked_deck.pop();
		create_node(tempCard);
	}
}
/*display_hand displays the players hand*/
void CardGame::display_hand()
{
	cout << "\nDisplaying the players hand: \n";
	
	players_hand *nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->hand_card.card_value<< " of " << nodePtr->hand_card.card_suit << endl;
		nodePtr = nodePtr->next;
	}

}
/*display_deck is a test function that will display the deck*/
void CardGame::display_deck()
{
	for (int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].sort_order << " " << deck[i].card_value << " of " << deck[i].card_suit << endl;
	}
}
void CardGame::go_fish()
{
	Card tempCard = stacked_deck.top();
	cout << "You drew a: " << tempCard.card_value << " of " << tempCard.card_suit << endl;
	stacked_deck.pop();
	create_node(tempCard);
	
}

