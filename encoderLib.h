#ifndef ENCODERLIB_H
#define ENCODERLIB_H

int getSign(char floatingPoint[33]);
int calcExponent(char floatingPoint[33]);
float calcFraction(char floatingPoint[33]);

#endif
