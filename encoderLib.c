#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "encoderLib.h"

//Get sign from first character.
int getSign(char floatingPoint[33])
{
  int output;

  if(floatingPoint[0] == '1')
  {
    output = -1;
  }
  else
  {
    output = 1;
  }

  return output;
}

//Getting the value for the exponent formula
int calcExponent(char floatingPoint[33])
{
  int output = 0;
  char exponentBIN[8];
  int expCount = 0;
  int toAdd = 0;
//Assigning from the point.
  for(int i = 1; i <= 8; i++)
  {
    exponentBIN[expCount] = floatingPoint[i];
    expCount++;
  }

  //printf("The exponent field is: %s\n", exponentBIN);
  //Resetting expCount to -1 and subtracting one more for each bit
  expCount = 0;

  for(int i = strlen(exponentBIN)-1; i >= 0; i--)
  {
    if(exponentBIN[i] == '1')
    {
      toAdd = pow(2, expCount);

      output = output + toAdd;

      expCount = expCount + 1;
    }
    else
    {
      expCount = expCount + 1;
    }

  }

  return output;
}

float calcFraction(char floatingPoint[33])
{
  float output = 0;
  char fractionBIN[23];
  int fractionCount = 0;
  float toAdd = 0;

  for(int i = 9; i < strlen(floatingPoint); i++)
  {
    fractionBIN[fractionCount] = floatingPoint[i];
    fractionCount++;
  }

  fractionCount = -1;

  for(int i = 0; i < strlen(fractionBIN); i++)
  {
    if(fractionBIN[i] == '1')
    {
      toAdd = powf(2.0, fractionCount);

      output = output + toAdd;

      fractionCount = fractionCount - 1;
    }
    else
    {
      fractionCount = fractionCount - 1;
    }
  }

  return output;
}
