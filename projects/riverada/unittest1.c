/*--------------------------------------------------------------------------------
Name: Daniel Rivera
File Name: unittest1.c
Project Name: Assignment 3
Created On: 7/10/2019
Class: CS362 - Software Engineering II
--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
Description: 
--------------------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h>"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TESTCARD "minion"

int main(){

	int numPlayers = 2;
	int new_cards = 0;
	int discarded_cards = 0;
	int extra_coins = 0;
	int shuffled_cards = 0;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int remove1, remove2;
	int seed = 10;
	int currentPlayer = 0;

	struct gameState testState, actualState;

	int k[10]={mine, minion, baron, tribute, ambassador, 
		council_room, smithy, embargo, sea_hag, village}
	
	int initializeGame(int numPlayers, k, int seed, struct &testState);

	printf("------------- Test Start (Testing Card: %s) -------------\n", TESTCARD)

	printf("Test 1: choice1 = 1, +2 coins\n");

	memcpy(&actualState, testState, sizeof(struct gameState));
	choice1 = 1;
	extra_coins = 2;
	cardEffect(minion, choice1, choice2, choice3, testState, handPos, &bonus);
	printf("coins = %d, expected = %d\n", testState.coins, actualState.coins + extra_coins);
	assert(testState.coins == actualState.coins + extra_coins);


    return 0;
}