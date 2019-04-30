#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Test for smithy card
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

  // Play smithy card
  cardEffect(smithy, -1, -1, -1, &state, 0, 0);

  // Test play of smithy card for first player immediately after game startup
  // Should be 7 (5 on start + 3 drawn - 1 for discard of smithy)
  expectedCount = 7;
  if (state.handCount[currPlayerPos] == expectedCount)
    printf("cardEffect(smithy): PASS when test hand count after smithy is played\n");
  else
    printf("cardEffect(smithy): FAIL when test hand count after smithy is played\n");

  return 0;
}