/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Pei Jou Liu (Vicky)
 * USC email: peijouli@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

//test git




//同时改vct0ry
/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  for (int j= 0; j<52; j++ ){
  	cards[j]=j;
  } //initialize a desk of 52 cards to have values from 0 to 51 
  for (int i = 51; i >= 1; i--){
  	int j = rand() % (i+1); 
  	int temp;
  	temp =cards[i]; 
  	cards[i] = cards[j];
  	cards[j] = temp;
  } // shuffle the deck by swaping 
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  cout<< type[id%13] << "-" << suit[id/13] << " ";

} // print the card in pretty form of "type-suit"

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  	return value[id%13];
} // return the id number with the actual value of card
  
/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
	for (int i = 0; i < numCards; i++){
		printCard(hand[i]);
		
	} // print out each card in the hand
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
	int sumOfCards=0;
	for (int i = 0; i < numCards; i++){
		sumOfCards = sumOfCards + cardValue(hand[i]);
	} //sum of all the cards when there is NO ACE 
	
	for (int i = 0; i< numCards; i++){
		if (cardValue(hand[i]) ==11 && sumOfCards > 21){
			sumOfCards = sumOfCards -10;
		}//sum of the cards when there is ACE and the sum is over 21
		// chchange the value of ACE from 11 to 1
	}
	return sumOfCards;

}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
 
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);
  
  int cards[52];
  int dhand[9];
  int phand[9];
  

  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
// while (the user enter "y")
 
  //cout << getBestScore(phand, 2);


  //int getBestScore(phand[1], pnumCards++);
  //cout<< getBestScore();
  // create number of card for both dealer and player --> 
  // set number of card = 2
  // then do number of card ++
 
char playAgain='y';
while (playAgain == 'y'){

	 shuffle(cards);


  int dnumCards = 0;
  int pnumCards = 0;
  int deckNumCards = 0;

  phand[pnumCards++]=cards[deckNumCards++];
  dhand[dnumCards++]=cards[deckNumCards++]; 
  phand[pnumCards++]=cards[deckNumCards++];
  dhand[dnumCards++]=cards[deckNumCards++];

  cout << "Dealer:" << "? ";
  printCard(dhand[1]);
  cout << endl;
  
  cout << "Player:";
  printHand(phand,2);
  cout << endl;

while (true){
	if (getBestScore(phand,pnumCards)>21){
  		break; // jump out when the sum is over 21
  	} 
  	else if ( getBestScore(phand,pnumCards) == 21) {
  		while(getBestScore(dhand,dnumCards)<17){

		  			dhand[dnumCards++]= cards[deckNumCards++];
		  		 }
		  			cout << "Dealer: ";
		  			printHand(dhand, dnumCards);
		  			cout << endl;
		  			break;

  	}
  	else {
  		cout << "Type 'h' to hit and 's' to stay:" << endl;
  		char answer;
  		cin >> answer;
  
		  // set int total value = 0 
		  // increment everytime = total value = +card value 

		  if (answer == 'h'){
		  	phand[pnumCards++] = cards[deckNumCards++];
		  	cout << "Player:";
		  	printHand(phand, pnumCards);
		  	cout << endl; // give one more card to the player when hitting 'h'
		  } else if (answer == 's') { 
		  		while(getBestScore(dhand,dnumCards)<17){

		  			dhand[dnumCards++]= cards[deckNumCards++];
		  		 } // give dealer one more card 
		  			cout << "Dealer: ";
		  			printHand(dhand, dnumCards);
		  			cout << endl;
		  			break; 
		  	}
	}
 }

	if (getBestScore(phand,pnumCards)>21)
	{
  		cout << "Player Busts " << endl;
  		cout << "lose ";
  		cout << getBestScore(phand,pnumCards) << " ";
  		cout << getBestScore(dhand,dnumCards) << endl;
  		
  	} // player busts
  		
   	else if (getBestScore(dhand,dnumCards)>21) {
  		cout << "Dealer Busts " << endl;
  		cout << "Win ";
  		cout << getBestScore(phand,pnumCards) << " ";
  		cout << getBestScore(dhand,dnumCards) << endl;

  	} // dealer is busted  
  		
  	else if ( getBestScore(phand,pnumCards)> getBestScore(dhand,dnumCards) ) { 
  		cout << "Win ";
  		cout << getBestScore(phand,pnumCards) << " ";
  		cout << getBestScore(dhand,dnumCards) << endl;
  		// when sum of the player is larger than dealer - player wins

  	} else if(getBestScore(phand,pnumCards)< getBestScore(dhand,dnumCards) ) { 
  		cout << "Lose ";
  		cout << getBestScore(phand,pnumCards) << " ";
  		cout << getBestScore(dhand,dnumCards) << endl;
  	}// when sum of the player is smaller than dealer - dealer wins
  	else {
  		cout << "tie " ;
  		cout << getBestScore(phand,pnumCards) << " ";
  		cout << getBestScore(dhand,dnumCards) << endl;
  		// tie

  	}
  
  

cout << endl<< "Play again? [y / n]" <<endl;
  		cin >> playAgain;
// ask the user to play again or not 
}

return 0;
}
