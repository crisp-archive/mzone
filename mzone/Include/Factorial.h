
/*

  Math Zone Source
  
    Module name      - Factorial.h
	Abstract         - Functions, constants and procedures' definitions 
	Modified         - David Zhang (15-Dec-2004) 
	
*/

#ifndef _FACTORIAL_H
#define _FACTORIAL_H

#define E 2.7182818284590452353602
#define TEN9 1000000000

inline DWORD Div_TEN9_1(UINT64 x, DWORD* remainder);
inline DWORD Div_TEN9_2(UINT64 x, DWORD* remainder);
double GetResultLength(DWORD n);
void PrintResult(DWORD n, DWORD* buff, int bufflen, int language);
void GetFactorial(DWORD* buff, int bufflen, DWORD n);

#endif
