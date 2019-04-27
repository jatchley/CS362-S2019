#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Test for discardCard function
// TODO: Finish this
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
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 4 after discarding one card after game setup");
  // Test that discarded card was not trashed
  assert(state.playedCards[state.playedCardCount] == state.hand[currPlayerPos][0] && "Top of PlayedCards does not match card that was discarded");

  // Test trashing a card 
  int expectedCount = 3;
  discardCard(0, currPlayerPos, &state, 1);
  if (NOISY_TEST == 1)
    printf("Current hand count: %d cards in hand.\n", state.handCount[currPlayerPos]);
  assert(state.handCount[currPlayerPos] == expectedCount && "Handcount was not 3 after discarding one additional card after game setup");
  // Test that discarded card was trashed
  assert(state.playedCards[state.playedCardCount] != state.hand[currPlayerPos][0] && "Top of PlayedCards matches card that was trashed");

  return 0;
}

// TODO: Delete, reference only
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
  //if card is not trashed, added to Played pile
  if (trashFlag < 1)
  {
    //add card to played pile
    state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos];
    state->playedCardCount++;
  }

  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;

  //remove card from player's hand
  if (handPos == (state->handCount[currentPlayer] - 1)) //last card in hand array is played
  {
    //reduce number of cards in hand
    state->handCount[currentPlayer]--;
  }
  else if (state->handCount[currentPlayer] == 1) //only one card in hand
  {
    //reduce number of cards in hand
    state->handCount[currentPlayer]--;
  }
  else
  {
    //replace discarded card with last card in hand
    state->hand[currentPlayer][handPos] = state->hand[currentPlayer][(state->handCount[currentPlayer] - 1)];
    //set last card to -1
    state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
    //reduce number of cards in hand
    state->handCount[currentPlayer]--;
  }

  return 0;
}