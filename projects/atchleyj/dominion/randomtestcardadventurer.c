#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

// Random Test for Adventurer card
int checkAdventurer(int currPlayerPos, struct gameState *post)
{
  struct gameState pre;
  memcpy(&pre, post, sizeof(struct gameState));

  int expectedCount = post->numActions + 2;

  // Play Adventurer card on post state
  cardEffect(adventurer, -1, -1, -1, post, 0, 0);

  // Mimic functionality between pre and post to check for mismatches
  pre.handCount[currPlayerPos] += 2;

  // Compare pre and post states to validate test
  int result = 0;
  if (pre.handCount[currPlayerPos] == post->handCount[currPlayerPos])
  {
    result = 1;
  }

  return result;
}

int main()
{
  // Declare test variables
  int i, j, k;
  struct gameState state;
  int possibleCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  int currPlayerPos = 0;
  int numPlayers = 2;
  int randSeed = 1000;
  int failureCount = 0;
  int result;

  printf("----------------- Random Testing of Card: Adventurer ----------------\n");

  SelectStream(2);
  PutSeed(3);

  for (i = 0; i < 2000; i++)
  {
    memset(&state, 23, sizeof(struct gameState));
    initializeGame(numPlayers, possibleCards, randSeed, &state);
    
    currPlayerPos = floor(Random() * numPlayers);
    state.whoseTurn = currPlayerPos;
    state.deckCount[currPlayerPos] = floor(Random() * MAX_DECK);
    state.discardCount[currPlayerPos] = floor(Random() * (MAX_DECK - state.deckCount[currPlayerPos]));
    state.handCount[currPlayerPos] = floor(Random() * MAX_HAND);
    state.playedCardCount = floor(Random() * MAX_DECK);

    state.numActions = floor(Random() * 1000);
    result = checkAdventurer(currPlayerPos, &state);

    if (result != 0)
    {
      failureCount++;
    }
  }

  if (failureCount > 0)
  {
    printf("Random testing of cardEffect(Adventurer) FAILED. FAILURE COUNT: %d\n", failureCount);
  }
  else
  {
    printf("Random testing of cardEffect(Adventurer) PASSED\n");
  }

  return 0;
}