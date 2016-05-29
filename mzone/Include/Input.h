
/*

  Math Zone Source
  
    Module name      - Input.h
	Abstract         - Functions' and constants definitions 
	Author           - David Zhang (6-Feb-2004) 
	
*/

#ifndef _INPUT_H
#define _INPUT_H

int isnum(char* input);

int InputIntNum(int min, int max, int language);
double InputDoubleNum(double min, double max, int language);
__int64 Input__int64Num(int language);

#define ACCEPT 1005
#define REFUSE 1006
int DataWarn(int input, int max, int language);

void DataErrorMessage(int min, int max, int language);
#endif
