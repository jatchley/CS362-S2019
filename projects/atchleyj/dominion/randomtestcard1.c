#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

// TODO: Finish this
// Random Test for Village card
int checkVillage(int currPlayerPos, struct gameState *post)
{
  struct gameState pre;
  memcpy(&pre, post, sizeof(struct gameState));

  int expectedCount = post->numActions + 2;

  // Play Village card on post state
  cardEffect(village, -1, -1, -1, post, 0, 0);

  // Mimic functionality between pre and post to check for mismatches
  drawCard(currPlayerPos, &pre);
  pre.numActions = pre.numActions + 2;
  discardCard(0, currPlayerPos, &pre, 0);

  // Compare pre and post states to validate test
  int result = memcmp(&pre, post, sizeof(struct gameState));

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
  int failureCount = 0;
  int result;

  printf("----------------- Random Testing of Card: Village ----------------\n");

  SelectStream(2);
  PutSeed(3);

  for (i = 0; i < 2000; i++)
  {
    for (j = 0; j < sizeof(struct gameState); j++)
    {
      ((char *)&state)[j] = floor(Random() * 256);
    }
    currPlayerPos = floor(Random() * numPlayers);
    state.whoseTurn = currPlayerPos;
    state.deckCount[currPlayerPos] = floor(Random() * MAX_DECK);
    state.discardCount[currPlayerPos] = floor(Random() * (MAX_DECK - state.deckCount[currPlayerPos]));
    state.handCount[currPlayerPos] = floor(Random() * MAX_HAND);
    state.playedCardCount = floor(Random() * MAX_DECK);

    // TODO: Remove this if not used
    // Fill hand with random cards
    // for (k = 0; k < state.handCount[currPlayerPos]; k++)
    // {
    //   int randomCardPos = floor(Random() * 10);
    //   int randomCard = possibleCards[randomCardPos];
    //   state.hand[currPlayerPos][k] = randomCard;
    // }

    state.numActions = floor(Random() * 1000);
    result = checkVillage(currPlayerPos, &state);

    if (result != 0)
    {
      failureCount++;
    }
  }

  if (failureCount > 0)
  {
    printf("Random testing of cardEffect(village) FAILED\n");
  }
  else
  {
    printf("Random testing of cardEffect(village) PASSED\n");
  }

  return 0;
}