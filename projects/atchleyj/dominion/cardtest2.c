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
  int expectedCount = 0;
  int randSeed = 1000;

  // Clear the game state and initialize a new game instance
  memset(&state, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdomCards, randSeed, &state);

  // Play adventurer card
  cardEffect(adventurer, -1, -1, -1, &state, 0, 0);

  // Test play of adventurer card for first player immediately after game startup
  // TODO: CHANGE THIS TO A CORRECT/REAL TEST
  if (state.handCount[currPlayerPos] == expectedCount)
    printf("cardEffect(adventurer): PASS when test hand count after adventurer is played\n");
  else
    printf("cardEffect(adventurer): FAIL when test hand count after adventurer is played\n");

  return 0;
}

// TODO: Reference only, delete when finished
int adventurerEffect(int currentPlayer, struct gameState *state)
{
  int drawntreasure = 0;
  int cardDrawn;
  int temphand[MAX_HAND]; // moved above the if statement
  int z = 0;              // this is the counter for the temp hand

  while (drawntreasure < 2)
  {
    if (state->deckCount[currentPlayer] < 1)
    { //if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }

    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; //top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    {
      drawntreasure++;
    }
    else
    {
      temphand[z] = cardDrawn;
      state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while (z - 1 >= 0)
  {
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
    // TODO: This is a bug. The below line should be uncommented to revert behavior
    // z = z - 1;
  }

  return 0;
}