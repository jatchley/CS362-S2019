#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Test for adventurer card
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
  int expectedCount = 13;
  int randSeed = 1000;

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  // Set deckCount to 0 to test that adventurer shuffles the deck
  state.deckCount[currPlayerPos] = 0;

  // Play adventurer card
  cardEffect(adventurer, -1, -1, -1, &state, 0, 0);

  // Test play of adventurer card for first player immediately after game startup
  if (state.deckCount[currPlayerPos] == expectedCount)
    printf("cardEffect(adventurer): PASS when test deck count after adventurer is played\n");
  else
    printf("cardEffect(adventurer): FAIL when test deck count after adventurer is played\n");

  return 0;
}