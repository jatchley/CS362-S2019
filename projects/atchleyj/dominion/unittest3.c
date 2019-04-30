#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Test for isGameOver function
// TODO: Finish this
// TODO: Print success at end
// TODO: Look over this one more time to make sure it is correct for submission requirements
int main()
{
  // Declare test variables
  int i;
  struct gameState state;
  int currPlayerPos = 0;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  int numPlayers = 2;
  int expectedCount = 0;
  int randSeed = 1000;

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test for empty Province stack
  state.supplyCount[province] = 0;
  if (isGameOver(&state) == 1)
    printf("isGameOver(): PASS when test empty supply count of Province cards\n");
  else
    printf("isGameOver(): FAIL when test empty supply count of Province cards\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test for only one empty stack
  state.supplyCount[0] = 0;
  if (isGameOver(&state) == 0)
    printf("isGameOver(): PASS when test empty supply count of only one stack\n");
  else
    printf("isGameOver(): FAIL when test empty supply count of only one stack\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test for two empty stacks
  state.supplyCount[0] = 0;
  state.supplyCount[1] = 0;
  if (isGameOver(&state) == 0)
    printf("isGameOver(): PASS when test empty supply count of only two stacks\n");
  else
    printf("isGameOver(): FAIL when test empty supply count of only two stacks\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test for three empty stacks
  state.supplyCount[0] = 0;
  state.supplyCount[1] = 0;
  state.supplyCount[2] = 0;
  if (isGameOver(&state) == 1)
    printf("isGameOver(): PASS when test empty supply count of three stacks\n");
  else
    printf("isGameOver(): FAIL when test empty supply count of three stacks\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test for no empty stacks
  if (isGameOver(&state) == 0)
    printf("isGameOver(): PASS when test no empty stacks\n");
  else
    printf("isGameOver(): FAIL when test no empty stacks\n");

  return 0;
}