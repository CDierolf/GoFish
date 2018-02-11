#pragma once
#ifndef CARDGAME_H
#define CARDGAME_H

#include <string>
#include <vector>
#include <stack>

using namespace std;
// Nodes contain data of the players hand which consists of 5 cards.

// Card struct
struct Card {
	int sort_order;
	string card_suit;
	string card_value;
};
// Player struct   DOESN"T WORK YET!
//struct players
//{
//	players_hand ph;
//	int player_number;
//};

//The players hand.
struct players_hand {
	Card hand_card;
	players_hand *next;
	players_hand(Card hand_card1, players_hand *next1 = nullptr)
	{
		hand_card = hand_card1;
		next = next1;
	}

};
class CardGame
{
private:
	players_hand *head, *tail;			//The players hand
	const int MAX_INITIAL_CARDS = 5;	//The maximum number of cards initially dealt to the player
	int num_cards_in_deck;				//The number of cards in the deck depending on the game. set in the constructor

public:
	//Constructor
	CardGame(int n) {
		head = NULL;
		tail = NULL;
		num_cards_in_deck = n;
		create_deck();
		shuffle_deck();
		stack_deck();
	}
	stack<Card, vector<Card>> stacked_deck;	// The deck of cards - eventually will be a stack.
	vector<Card> deck;
	void create_node(Card card);	// Called by deal_card to create a sorted linked list of the players hand
	void create_deck();				// Called by the constructor
	void shuffle_deck();			// Called by the constructor after the deck is created.
	void stack_deck();
	void deal_card();				// Calls create_node to create a linked list of the players card up to MAX_INITIAL_CARDS
	void display_hand();			// Displays the players hand
	void display_deck();			// Displays the deck.
	void go_fish();
};


#endif