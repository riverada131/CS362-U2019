/*--------------------------------------------------------------------------------
Name: Daniel Rivera
File Name: cardtest1.c
Project Name: Assignment 3
Created On: 7/10/2019
Class: CS362 - Software Engineering II 
--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
Description: test the following inclusive in unit testing
1) initializeGame, 2) shuffle, 3) endTurn, 4) getWinners, 5) drawCard.
--------------------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"

#define TESTCARD "minion"

int main(){

	int numPlayers = 0;
	int players[MAX_PLAYERS];
	int seed = 10;
	int i, j, l, m;
	int ret_value = 0;
	int extra_coins = 0;
	int extra_cards = 0;
	int extra_count = 0;

	struct gameState testState, actualState;

	int k[10] = { mine, minion, baron, tribute, ambassador,
		council_room, smithy, embargo, sea_hag, village };
	
	initializeGame(numPlayers, k, seed, &testState);

	printf("\n------------- Test 1 Start (Testing Function: initializeGame) -------------\n");
	printf("Test 1: check initialize game function\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));
	numPlayers = 3;


	for (i = 0; i <= numPlayers; i++) {
		ret_value = initializeGame(i, k, seed, &testState);
		printf("number of players in function = %d, expected %d \n", testState.numPlayers, numPlayers);
	}

	numPlayers = 5;

	ret_value = initializeGame(numPlayers, k, seed, &testState);
	printf("max players return from function = %d, expected -1 \n", ret_value);

	printf("\n------------- Test 2 Start (Testing Function: shuffle) -------------\n");
	printf("Test 2: check shuffle function\n\n");

	for (i = 0; i <= numPlayers; i++) {
		ret_value = shuffle(i, &testState);
		printf("if i < 3 then return = 0 else return -1:  \n");
		printf("return = %d, i = %d  \n", ret_value, i);
	}
	

	printf("\n------------- Test 3 Start (Testing Function: endTurn) -------------\n");
	printf("Test 3: check endTurn function\n\n");

	numPlayers = 3;

	for (i = 0; i < numPlayers; i++) {
		ret_value = endTurn(&testState);
		//printf("state->discard = %d, state->hand = %d\n", *testState.discard, *testState.hand);
		printf("state->whoseTurn = %d expect = %d\n", testState.whoseTurn, i);
	}

	printf("\n------------- Test 4 Start (Testing Function: getWinners) -------------\n");
	printf("Test 4: check getWinners function\n\n");

	getWinners(players, &testState);
	printf("return = %d, expected = 0", ret_value);

	printf("\n------------- Test 5 Start (Testing Function: drawCard) -------------\n");
	printf("Test 5: check drawCard function\n\n");

	numPlayers = 5;

	for (i = 0; i <= numPlayers; i++) {
		ret_value = drawCard(i, &testState);
		printf("if deck count is <= 0 then return = -1 else = 0 \n");
		printf("discard count = %d, Current hand count: %d\n", *testState.discardCount, *testState.handCount);
		printf("return = %d, i = %d  \n", ret_value, i);
	}

	printf("\n------------- Test 6 Start (Testing Card: %s) -------------\n", TESTCARD);
	printf("Test 6: direct call and iteration through inputs for callMinion\n");

	memcpy(&actualState, &testState, sizeof(struct gameState));


	for (i = 0; i < numPlayers; i++) {
		for (j = 0; j < numPlayers; j++) {
			for (l = 0; l < numPlayers; l++) {
				for (m = 0; m < numPlayers; m++) {
					ret_value = cardMinion(l, i, &testState, m, j);
				}
			}
			printf("coins = %d, expected = %d\n", testState.coins, actualState.coins + extra_coins * i);
			printf("deck count = %d, expected = %d\n", *testState.deckCount, *actualState.deckCount + extra_cards);
			printf("hand count = %d, expected = %d\n", *testState.handCount, *actualState.handCount + extra_count);
		}
		printf("return value from function = %d, expect = 0 \n", ret_value);
	}


	printf("\n ----------- SUCCESS: Testing complete ---------- \n\n");

	printf("\n ------------------------------------------------------------------------------------ \n\n");

    return 0;
}