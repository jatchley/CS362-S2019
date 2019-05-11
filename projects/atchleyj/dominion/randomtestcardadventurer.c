#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// TODO: Finish this
// Random Test for adventurer card
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

  printf("----------------- Random Testing of Card: Adventurer ----------------\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Play adventurer card
  cardEffect(adventurer, -1, -1, -1, &state, 0, 0);

  // Test play of adventurer card for first player immediately after game startup
  // Should be 7 (5 on start + 2 drawn)
  expectedCount = 7;
  if (state.handCount[currPlayerPos] == expectedCount)
    printf("cardEffect(adventurer): PASS when test hand count after adventurer is played\n");
  else
    printf("cardEffect(adventurer): FAIL when test hand count after adventurer is played\n");

  return 0;
}