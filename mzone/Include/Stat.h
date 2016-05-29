
/*

  Math Zone Source
  
    Module name      - Stat.h
	Abstract         - Functions, constants and procedures' definitions
	Author           - David Zhang (16-Apr-2006) 
	
*/

#ifndef _STAT_H
#define _STAT_H

#define MAX_COUNTER 32768

void PreStat(int language);

void PrintAverage(double data[MAX_COUNTER], int counter, int language);
double GetAverage(double total, int counter);

double GetVariance(double data[MAX_COUNTER], int counter);
void PrintVariance(double data[MAX_COUNTER], int counter, int language);

double GetStandardDeviation(double sqrdiff);
void PrintStandardDeviation(double sqrdiff, int language);

double GetTotal(double data[MAX_COUNTER], int counter);
void PrintStatInfo(double total, int counter, int language);

#endif
