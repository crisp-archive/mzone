
/*

  Math Zone Source
  
    Module name      - Calculate.h
	Abstract         - Functions,  constants,  structure and procedures' definitions
	Author           - David Zhang (02-May-2006) 
	
*/

#ifndef _CALCULATE_H
#define _CALCULATE_H

typedef struct tagEQUAROOT
{
	double x1;
	double x2;
} EQUAROOT;

EQUAROOT GetEquationRoot(double a, double b, double c);

int GetMaximumCommonDivisor(int a, int b);
int GetMinimumCommonMultiple(int a, int b);

int GetPrime(int min, int max);
int GetGoogle(int min, int max);
void GetRandom(int min, int max, int times);

int GetPrimeDivisor(int data);
int GetDivisor(int data);

void GetRemainder(int divisor, int dividend, int step);

void MakeMagicSquare(int a);

#define PI 3.1415926535897932384626

double GetSineValue(double degree);
double GetCosineValue(double degree);
double GetTangentValue(double degree);
double GetCotangentValue(double degree);
double GetSecantValue(double degree);
double GetCosecantValue(double degree);

#endif
