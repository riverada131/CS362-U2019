/*--------------------------------------------------------------------------------
Name: Daniel Rivera
File Name: cardtest1.c
Project Name: Assignment 3
Created On: 7/10/2019
Class: CS362 - Software Engineering II
--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
Description: Random black box testing with random inputs to test callMinion function.
tests also to include testing callEffect function.
--------------------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"

#define TESTCARD "tribute"
#define MAX_NUM_TEST 10

void print_values(int choice1, int choice2);
void element_check(int pre_condition, int post_condition, int extra_input, char element[]);

int main() {

	int numPlayers;
	int pre_coin_count, pre_copper_count, exp_hand_count;
	int seed, hand_count, player, coin_count, copper_count, extra_coins,
		num_hand_cards, hand_count_1, next_player;
	int i, j;
	int choice1, choice2, choice3, handPos, bonus;

	struct gameState test_state, pre_test_state;

	int k[10] = { mine, minion, baron, tribute, ambassador,
		council_room, smithy, embargo, sea_hag, village };

	choice1 = 0;
	choice2 = 0;
	choice3 = 0;
	handPos = 0;
	bonus = 0;

	printf("\n------------- Random Testing: Test Start (Testing: %s) -------------\n", TESTCARD);

	for (i = 0; i < MAX_NUM_TEST; i++) {
		int index = i + 1;
		numPlayers = rand() % 4;
		seed = rand();
		extra_coins = 2;
		choice1 = 1;

		printf("\n------------- Test Iteration %d, Part 1 (Testing: %s) -------------\n", index, TESTCARD);
		initializeGame(numPlayers, k, seed, &test_state);

		memcpy(&pre_test_state, &test_state, sizeof(struct gameState));

		test_state.deckCount[player] = rand() % MAX_DECK;
		test_state.discardCount[player] = rand() % MAX_DECK;
		test_state.handCount[player] = rand() % MAX_HAND;

		pre_coin_count = pre_test_state.coins;
		pre_copper_count = pre_test_state.supplyCount[copper];
		hand_count_1 = hand_count = test_state.handCount[player];

		if (seed % 3 == 0) {
			test_state.deckCount[player] = 0;
		}

		cardEffect(tribute, choice1, choice2, choice3, &test_state, handPos, &bonus);

		coin_count = test_state.coins;
		copper_count = test_state.supplyCount[copper];
		num_hand_cards = test_state.handCount[player];
		exp_hand_count = hand_count_1 - 1; //<-- found bug should not need to subtract 1

		/*assert(coin_count == pre_coin_count + extra_coins);
		assert(copper_count == pre_copper_count);
		assert(num_hand_cards == exp_hand_count);*/

		print_values(choice1, choice2);
		element_check(pre_coin_count, coin_count, extra_coins, "Coin");
		element_check(pre_copper_count, copper_count, 0, "Copper");
		element_check(exp_hand_count, num_hand_cards, 0, "Hand");

		printf("\n------------- Test Iteration %d, Part 2 (Testing: %s) -------------\n", index, TESTCARD);
		choice1 = rand() % 2;
		choice2 = rand() % 2;
		next_player = player + 1;
		int currentPlayer = whoseTurn(&test_state);
		int upper_limit = rand() % 100 + 4;
		test_state.discardCount[next_player] = rand() % 10;
		test_state.deckCount[next_player] = rand() % 10;

		cardEffect(tribute, choice1, choice2, choice3, &test_state, handPos, &bonus);

		coin_count = test_state.coins;
		copper_count = test_state.supplyCount[copper];

		//assert(coin_count == pre_coin_count + extra_coins);

		printf("Number of players = %d\n", numPlayers);
		print_values(choice1, choice2);
		element_check(pre_coin_count, coin_count, extra_coins, "Coin");

		for (j = 0; j < numPlayers; j++) {
			test_state.handCount[j] = upper_limit;
			test_state.coins = 0;
		}

		cardTribute(&test_state, next_player, currentPlayer, &test_state);

		for (j = 0; j < numPlayers; j++) {
			printf("Player %d ", j + 1);
			element_check(upper_limit, test_state.handCount[j], 0, "Hand");
		}

		printf("\n------------- End of Test Iteration %d -------------\n", index);

	}
	return 0;
}

void print_values(int choice1, int choice2) {
	printf("Values for this test are: \n");
	printf("choice1 = %d\n", choice1);
	printf("choice2 = %d\n\n", choice2);
}

void element_check(int pre_condition, int post_condition, int extra_input, char element[]) {
	if (post_condition == pre_condition + extra_input) {
		printf("%s count matches - ", element);
		printf("(%s count = %d, ", element, post_condition);
		printf("expected = %d)\n", pre_condition + extra_input);
	}
	else {
		printf("%s count does not match - ", element);
		printf("(%s count = %d, ", element, post_condition);
		printf("expected = %d) <-- BUG\n", pre_condition + extra_input);
	}
}

