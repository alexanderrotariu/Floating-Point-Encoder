#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "encoderLib.h"

int main(int argc, char** argv)
{
  char floatingPointNum[33];

  if(argc == 2 && strcmp(argv[1], "-v") == 0)
  {
    while(!feof(stdin))
    {
      int numRead = fscanf(stdin, "%s", floatingPointNum);
      if(numRead > 0)
      {
        int sign = getSign(floatingPointNum);
        int exponent = calcExponent(floatingPointNum);
        float fraction = calcFraction(floatingPointNum);

        printf("%s --> %f \n", floatingPointNum, (sign * (1+fraction) * pow(2, exponent-127)));
      }
    }
  }
  else if(argc == 1)
  {
    while(!feof(stdin))
    {
      int numRead = fscanf(stdin, "%s", floatingPointNum);
      if(numRead > 0)
      {
        int sign = getSign(floatingPointNum);
        int exponent = calcExponent(floatingPointNum);
        float fraction = calcFraction(floatingPointNum);

        printf("%f \n", sign * (1+fraction) * pow(2, exponent-127));
      }
    }
  }
  else if(argc > 2)
  {
    perror("TOO MANY COMMAND LINE ARGUMENTS");
    return EXIT_FAILURE;
  }
  else
  {
    perror("COMMAND LINE ARGUMENT NOT FOUND!");
    return EXIT_FAILURE;
  }
}
