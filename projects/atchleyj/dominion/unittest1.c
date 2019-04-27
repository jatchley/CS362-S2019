#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

// TODO: Print success at end
// TODO: Look over this one more time to make sure it is correct for submission requirements
// Test for drawCard function
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

  // Test draw 5 cards on initialize
  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  expectedCount = 5;
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 5 after drawing 5 cards on game setup");

  // Clear the game state and initialize a new game instance
  // Test draw 1 card from normal deck
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  // Discard all starting cards to test drawing different numbers
  expectedCount = 0;
  for (i = state.handCount[currPlayerPos]; i > 0; i--)
  {
    discardCard(i, currPlayerPos, &state, 0);
  }
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 0 after discarding all cards");
  // Draw 1 card
  expectedCount = 1;
  drawCard(currPlayerPos, &state);
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 1 after drawing 1 card");

  // Test draw all cards from normal deck
  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);
  expectedCount = 10;
  for (i = 0; i < 20; i++)
  {
    drawCard(currPlayerPos, &state);
  }
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 10 after drawing 10 cards");

  return 0;
}