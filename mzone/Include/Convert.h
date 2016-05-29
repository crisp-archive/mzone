
/*

  Math Zone Source
  
    Module name      - Convert.h
	Abstract         - Functions' definitions
	Author           - David Zhang (22-Jul-2004) 
	
*/

#ifndef _CONVERT_H
#define _CONVERT_H

void ConvertDecimalNumber(DWORD input, int language);

void DecimalToGTten(DWORD input, DWORD system, char* result);
void DecimalToLTten(DWORD input, DWORD system, char* result);

#endif
