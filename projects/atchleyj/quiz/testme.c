#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar()
{
  int min = 32;  // [space] character
  int max = 126; // ~ character

  // Get random ASCII char including symbols
  int randAsciiNum = (rand() % (max - min)) + min;

  // Convert ASCII code to char
  char randChar = (char)randAsciiNum;
  return randChar;
}

char *inputString()
{
  int i;
  int min = 2;   // Want at least 2 characters in the string
  int max = 255; // No more than 255 in the string (to have null terminator)

  int randStringSize = (rand() % (max - min)) + min;

  // Create a string of random size
  char randString[256] = "";
  for (i = 0; i < randStringSize; i++)
  {
    char randChar = inputChar();

    int len = strlen(randString);
    randString[len] = randChar;
    randString[len + 1] = '\0';
  }

  return randString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
      state = 1;
    if (c == '(' && state == 1)
      state = 2;
    if (c == '{' && state == 2)
      state = 3;
    if (c == ' ' && state == 3)
      state = 4;
    if (c == 'a' && state == 4)
      state = 5;
    if (c == 'x' && state == 5)
      state = 6;
    if (c == '}' && state == 6)
      state = 7;
    if (c == ')' && state == 7)
      state = 8;
    if (c == ']' && state == 8)
      state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
    {
      printf("error ");
      exit(200);
    }

    // Interrupt so that it exits and can be checked with gcov
    // if (tcCount > 10000000)
    // {
    //   printf("10,000,000 iterations reached, exiting");
    //   return 0;
    // }
  }
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  testme();
  return 0;
}
