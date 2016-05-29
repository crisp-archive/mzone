
/*

  Math Zone Source
  
    Module name      - Convert.cpp
	Abstract         - Functions that convert integer systems
	Author           - David Zhang (1-Oct-2004)
	
*/ 

#include "stdafx.h"


void ConvertDecimalNumber(DWORD input, int language)
{
	char* convert=new char[30];
	int system;
	char* print=new char[11];
	_i64toa((__int64)input,print,10);
	Newline(1);
	PrintMessage(language,3010,"Conv");
	printf(" %s",print);
	for(system=2;system<=9;system+=2){
		DecimalToLTten(input,system,convert);
		Newline(2);
		printf("%d:\t    %s",system,convert);
		DecimalToLTten(input,system+1,convert);
		printf("    %d:\t    %s",system+1,convert);
	}
	for(system=11;system<=35;system+=3){
		DecimalToGTten(input,system,convert);
		Newline(2);
		printf("%d:\t  %s",system,convert);
		DecimalToGTten(input,system+1,convert);
		printf("  %d:\t  %s",system+1,convert);
		DecimalToGTten(input,system+2,convert);
		printf("  %d:\t  %s",system+2,convert);
	}
	Newline(1);
	delete convert,print;
	return;
}

void DecimalToGTten(DWORD input, DWORD system, char* result)
{
	DWORD remainder;
	char cache[2];
	strcpy(result,"");
	do{
		remainder=input%system;
		input=(DWORD)input/system;
		if(remainder<=9){
			cache[0]=(char)('0'+remainder);
			cache[1]='\0';
			strcat(result,cache);
		}
		else{
			cache[0]=(char)('A'+remainder-10);
			cache[1]='\0';
			strcat(result,cache);
		}
	}while(input);
	result=strrev(result);
	return;
}

void DecimalToLTten(DWORD input, DWORD system, char* result)
{
	DWORD remainder;
	char cache[2];
	strcpy(result,"");
	do{
		remainder=input%system;
		input=(DWORD)input/system;
		cache[0]=(char)('0'+remainder);
		cache[1]='\0';
		strcat(result,cache);
	}while(input);
	result=strrev(result);
	return;
}
