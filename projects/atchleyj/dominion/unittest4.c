#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// Test for endTurn function
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

printf("----------------- Testing Unit: endTurn() ----------------\n");

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Test that turn has changed to next player
  endTurn(&state);
  if (state.whoseTurn = currPlayerPos + 1)
    printf("endTurn(): PASS when test turn has changed to next player\n");
  else
    printf("endTurn(): FAIL when test turn has changed to next player\n");

  // Test that player whose turn ended has an empty hand
  if (state.handCount[currPlayerPos] == 0)
    printf("endTurn(): PASS when test player whose turn ended has an empty hand\n");
  else
    printf("endTurn(): FAIL when test player whose turn ended has an empty hand\n");

  return 0;
}