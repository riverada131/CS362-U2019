/*--------------------------------------------------------------------------------
Name: Daniel Rivera
File Name: cardtest1.c
Project Name: Assignment 3
Created On: 7/10/2019
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

#define TESTCARD "baron"
#define MAX_NUM_TEST 10

void print_values(int choice1, int choice2);
void coin_check(int coin_count, int pre_coin_count, int extra_coins);
void discard_count_check(int pre_discard_count, int discard_count);
void hand_count_check(int num_hand_count, int exp_hand_count);
void estate_count_check(int expected_estate_count, int estate_count);

int main() {

	int numPlayers;
	int pre_coin_count, pre_discard_count, pre_estate_count, cards_discarded;
	int seed, hand_count, player, coin_count, extra_coins, expected_estate_count,
		num_hand_cards, hand_count_1, discard_count, estate_count, estates_removed,
		expected_discard_count;
	int i, j, p, index;
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
		index = i + 1;
		p = 0;
		numPlayers = rand() % 4;
		seed = rand();
		extra_coins = 0;
		choice1 = 1;
		estates_removed = 2;
		cards_discarded = 1;

		printf("\n------------- Test Iteration %d, Part 1 (Testing: %s) -------------\n", index, TESTCARD);
		initializeGame(numPlayers, k, seed, &test_state);

		memcpy(&pre_test_state, &test_state, sizeof(struct gameState));

		test_state.deckCount[player] = rand() % MAX_DECK;
		test_state.handCount[player] = rand() % MAX_HAND;
		pre_estate_count = test_state.supplyCount[estate] = rand() % 20;
		pre_discard_count = test_state.discardCount[player] = rand() % MAX_DECK;
		expected_estate_count = pre_estate_count - estates_removed;
		expected_discard_count = pre_discard_count + cards_discarded;

		if (choice1 > 0 && test_state.hand[player][p] == estate) {
			extra_coins = 4; 
		}

		pre_coin_count = pre_test_state.coins;
		hand_count_1 = hand_count = test_state.handCount[player];

		if (seed % 3 == 0) {
			test_state.deckCount[player] = 0;
		}

		cardEffect(baron, choice1, choice2, choice3, &test_state, handPos, &bonus);

		coin_count = test_state.coins;
		num_hand_cards = test_state.handCount[player];
		discard_count = test_state.discardCount[player];
		estate_count = test_state.supplyCount[estate];

		//assert(coin_count == pre_coin_count + extra_coins);
		//assert(num_hand_cards == exp_hand_count);

		print_values(choice1, choice2);
		coin_check(coin_count, pre_coin_count, extra_coins);
		hand_count_check(num_hand_cards, hand_count_1);
		discard_count_check(expected_discard_count, discard_count);
		estate_count_check(expected_estate_count, estate_count);

		printf("\n------------- Test Iteration %d, Part 2 (Testing: %s) -------------\n", index, TESTCARD);
		choice1 = rand() % 2;
		choice2 = rand() % 2;
		int currentPlayer = whoseTurn(&test_state);
		int upper_limit = rand() % 100 + 4;

		if (choice1 == 1 && test_state.hand[player][p] == estate) {
			extra_coins = 4;
		}

		cardEffect(baron, choice1, choice2, choice3, &test_state, handPos, &bonus);

		coin_count = test_state.coins;

		//assert(coin_count == pre_coin_count + extra_coins);

		printf("Number of players = %d\n", numPlayers);
		print_values(choice1, choice2);
		coin_check(coin_count, pre_coin_count, extra_coins);

		for (j = 0; j < numPlayers; j++) {
			test_state.handCount[j] = upper_limit;
			test_state.coins = 0;
		}

		cardBaron(choice1, &test_state, currentPlayer);

		for (j = 0; j < numPlayers; j++) {
			printf("Player %d ", j + 1);
			hand_count_check(test_state.handCount[j], upper_limit);
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

void coin_check(int coin_count, int pre_coin_count, int extra_coins) {
	if (coin_count == pre_coin_count + extra_coins) {
		printf("Coin count matches - ");
		printf("(coin count = %d, ", coin_count);
		printf("expected = %d)\n", pre_coin_count + extra_coins);
	}
	else {
		printf("Coin count does not match - ");
		printf("(coin count = %d, ", coin_count);
		printf("expected = %d) <-- BUG\n", pre_coin_count + extra_coins);
	}
}

void discard_count_check(int pre_discard_count, int discard_count) {
	if (discard_count == pre_discard_count) {
		printf("Discard count matches - ");
		printf("(discard count = %d, ", discard_count);
		printf("expected = %d)\n", pre_discard_count);
	}
	else {
		printf("Discard count does not match - ");
		printf("(discard count = %d, ", discard_count);
		printf("expected = %d) <-- BUG\n", pre_discard_count);
	}
}

void hand_count_check(int num_hand_count, int exp_hand_count) {
	if (num_hand_count == exp_hand_count) {
		printf("Hand count matches - ");
		printf("(Hand count = %d, ", num_hand_count);
		printf("expected = %d)\n", exp_hand_count);
	}
	else {
		printf("Hand count does not match - ");
		printf("(Hand count = %d, ", num_hand_count);
		printf("expected = %d) <-- BUG\n", exp_hand_count);
	}
}

void estate_count_check(int expected_estate_count, int estate_count) {
	if (expected_estate_count == estate_count) {
		printf("Estate count matches - ");
		printf("(estate count = %d, ", estate_count);
		printf("expected = %d)\n", expected_estate_count);
	}
	else {
		printf("Estate count does not match - ");
		printf("(estate count = %d, ", estate_count);
		printf("expected = %d) <-- BUG\n", expected_estate_count);
	}
}
