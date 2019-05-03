#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// Test for village card
int main()
{
  // Declare test variables
  int i;
  struct gameState state;
  int currPlayerPos = 0;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  int numPlayers = 2;
  int randSeed = 1000;

  printf("----------------- Testing Card: village ----------------\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  int expectedCount = state.numActions + 2;

  // Play village card
  cardEffect(village, -1, -1, -1, &state, 0, 0);

  // Test play of village card for first player immediately after game startup
  if (state.numActions == expectedCount)
    printf("cardEffect(village): PASS when test action count after village is played\n");
  else
    printf("cardEffect(village): FAIL when test action count after village is played\n");

  return 0;
}