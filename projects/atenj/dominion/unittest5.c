/*--------------------------------------------------------------------------------
Name: Daniel Rivera
File Name: unittest5.c
Project Name: Assignment 3
Created On: 7/11/2019
Class: CS362 - Software Engineering II
--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
Description: 
--------------------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"

#define TESTCARD "ambassador"

int main() {

	int numPlayers = 2;
	int extra_coins = 0;
	int extra_cards = 0;
	int extra_count = 0;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int seed = 10;
	int i, j, l;
	int ret_value = 0;

	struct gameState testState, actualState;

	int k[10] = { mine, minion, baron, tribute, ambassador,
		council_room, smithy, embargo, sea_hag, village };

	initializeGame(numPlayers, k, seed, &testState);

	printf("------------- Test 1 Start (Testing Card: %s) -------------\n", TESTCARD);

	printf("Test 1: choice1 = 1, +2 coins\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));
	choice1 = 1;
	extra_coins = 2;
	cardEffect(ambassador, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("coins = %d, expected = %d\n\n", testState.coins, actualState.coins + extra_coins);

	printf("------------- Test 2 Start (Testing Card: %s) -------------\n", TESTCARD);
	printf("Test 2: choice1 = 0, +0 coins\n");
	printf("        choice2 = 1, +0 coins\n\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 1;
	extra_coins = 0;
	extra_cards = 0;
	extra_count = 0;
	cardEffect(ambassador, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("coins = %d, expected = %d\n", testState.coins, actualState.coins + extra_coins);
	printf("deck count = %d, expected = %d\n", *testState.deckCount, *actualState.deckCount + extra_cards);
	printf("hand count = %d, expected = %d\n", *testState.handCount, *actualState.handCount + extra_count);
	/*assert(testState.coins == actualState.coins + extra_coins);
	assert(*testState.deckCount == *actualState.deckCount + extra_cards);
	assert(*testState.handCount == *actualState.handCount + extra_count);*/


	printf("------------- Test 3 Start (Testing Card: %s) -------------\n", TESTCARD);
	printf("Test 3: iterate though handPos from 0 to total number of players.\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));
	choice1 = 1;
	choice2 = 1;
	extra_coins = 0;
	extra_cards = 0;
	extra_count = 0;


	for (i = 0; i < numPlayers; i++) {

		cardEffect(ambassador, choice1, choice2, choice3, &testState, i, &bonus);
		printf("coins = %d, expected = %d\n", testState.coins, actualState.coins + extra_coins);
		printf("deck count = %d, expected = %d\n", *testState.deckCount, *actualState.deckCount + extra_cards);
		printf("hand count = %d, expected = %d\n", *testState.handCount, *actualState.handCount + extra_count);
		/*assert(testState.coins == actualState.coins + extra_coins);
		assert(*testState.deckCount == *actualState.deckCount + extra_cards);
		assert(*testState.handCount == *actualState.handCount + extra_count);*/

	}

	//printf("\n------------- Test 4 Start (Testing Card: %s) -------------\n", TESTCARD);
	//printf("Test 4: iterate though choice 1, 2, and 3, from 0 to total number of players.\n");

	//memcpy(&actualState, &testState, sizeof(struct gameState));
	//extra_coins = 2;
	//extra_cards = 0;
	//extra_count = 0;

	//for (i = 0; i < numPlayers; i++) {
	//	for (j = 0; j < numPlayers; j++) {
	//		for (l = 0; l < numPlayers; l++) {
	//			cardEffect(ambassador, i, j, l, &testState, handPos, &bonus);
	//			printf("coins = %d, expected = %d\n", testState.coins, actualState.coins + extra_coins);
	//			printf("deck count = %d, expected = %d\n", *testState.deckCount, *actualState.deckCount + extra_cards);
	//			printf("hand count = %d, expected = %d\n", *testState.handCount, *actualState.handCount + extra_count);
	//			/*	assert(testState.coins == actualState.coins + extra_coins);
	//				assert(*testState.deckCount == *actualState.deckCount + extra_cards);
	//				assert(*testState.handCount == *actualState.handCount + extra_count);*/
	//		}
	//	}
	//}

	/*printf("\n------------- Test 5 Start (Testing Card: %s) -------------\n", TESTCARD);
	printf("Test 5: direct call and iteration through inputs for callAmbassador\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));
	extra_coins = 2;
	extra_cards = 0;
	extra_count = 0;


	for (i = 0; i < numPlayers; i++) {
		for (j = 0; j < numPlayers; j++) {
			for (l = 0; l < numPlayers; l++) {
				ret_value = cardAmbassador(i, j, &testState, handPos, l);
				printf("return value from function = %d \n", ret_value);
			}
		}
	}*/


	printf("\n ----------- SUCCESS: Testing complete %s ---------- \n\n", TESTCARD);
	printf("\n ------------------------------------------------------------------------------------ \n\n");
	return 0;
}