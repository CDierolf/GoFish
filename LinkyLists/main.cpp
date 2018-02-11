#include <iostream>
#include <string>
#include <vector>
#include "CardGame.h"

using namespace std;

int main()
{

	CardGame goFish(52);
	goFish.deal_card();
	cout << "Displaying the deck of cards!\n";
	goFish.display_deck();
	cout << endl << endl;
	cout << "\nDealing the cards:\nHere are your cards!:\n";
	goFish.display_hand();
	cout << endl << endl << "\nYou have to go fishing brosqueeto!\n";
	goFish.go_fish();
	cout << "Here is your current hand with your new card:\n";
	goFish.display_hand();


	return 0;
}