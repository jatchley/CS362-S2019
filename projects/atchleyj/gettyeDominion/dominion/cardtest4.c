#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// Test for greatHall card
int main()
{
  // Declare test variables
  int i;
  struct gameState state;
  int currPlayerPos = 0;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  int numPlayers = 2;
  int randSeed = 1000;

  printf("----------------- Testing Card: greatHall ----------------\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  int expectedCount = state.numActions + 1;

  // Play greatHall card
  cardEffect(great_hall, -1, -1, -1, &state, 0, 0);

  // Test play of greatHall card for first player immediately after game startup
  if (state.numActions == expectedCount)
    printf("cardEffect(greatHall): PASS when test action count after greatHall is played\n");
  else
    printf("cardEffect(greatHall): FAIL when test action count after greatHall is played\n");

  return 0;
}