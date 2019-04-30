#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Test for discardCard function
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

  // Test standard discard after initial drawing of cards
  int expectedCount = 4;
  discardCard(0, currPlayerPos, &state, 0);
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  if (state.handCount[currPlayerPos] == expectedCount)
    printf("discardCard(): PASS when test hand count on discarding one card after game setup\n");
  else
    printf("discardCard(): FAIL when test hand count on discarding one card after game setup\n");

  // Test that discarded card was not trashed
  if (state.playedCards[state.playedCardCount] == state.hand[currPlayerPos][0])
    printf("discardCard(): PASS when test discarded card was not trashed on discarding one card after game setup\n");
  else
    printf("discardCard(): FAIL when test discarded card was not trashed on discarding one card after game setup\n");

  // Test trashing a card
  int expectedCount = 3;
  discardCard(0, currPlayerPos, &state, 1);
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  if (state.handCount[currPlayerPos] == expectedCount)
    printf("discardCard(): PASS when test discarding one additional card after game setup\n");
  else
    printf("discardCard(): FAIL when test discarding one additional card after game setup\n");
  // Test that discarded card was trashed
  if (state.playedCards[state.playedCardCount] == state.hand[currPlayerPos][0])
    printf("discardCard(): PASS when test discarded card was trashed on discarding one card after game setup\n");
  else
    printf("discardCard(): FAIL when test discarded card was trashed on discarding one card after game setup\n");

  return 0;
}