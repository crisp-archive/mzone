
/*

  Math Zone Source
  
    Module name      - Input.cpp
    Abstract         - Functions that process data input
    Author           - David Zhang (30-Apr-2006) 
	
*/      

#include "stdafx.h"


int isnum(char* input)
{
	int i=0,length,temp;
	int counter=0;
	length=strlen(input);
	if(length>10){
		return 0;
	}
	for(i=0;i<length;i++){
		temp=isdigit(input[i]);
		if(temp==0 && input[i]=='-' && i==0){
			continue;
		}
		if(temp==0 && input[i]=='.' && i==0){
            return 0;
			break;
		}
		if(temp==0 && input[i]!='.'){
			return 0;
			break;
		}
		if(counter>1){
			return 0;
			break;
		}
		if(input[i]=='.'){
			counter++;
		}
		if(counter<=1){
			continue;
		}
	}
	if(i==length && counter<=1){
		return 1;
	}
	else{
		return 0;
	}
}

int InputIntNum(int min, int max, int language)
{
	char* input=new char[50];
	int temp,out;
	do{
		do{
			gets(input);
			temp=isnum(input);
			if(temp==0){
				PlayMediaFile();
				Newline(1);
				PrintMessage(language,4001,"Input");
				Newline(2);
				PrintMessage(language,4008,"Input");
			}
		}while(temp==0);
		out=atoi(input);
		if(out<min || out>max){
			DataErrorMessage(min,max,language);
			Newline(2);
			PrintMessage(language,4008,"Input");
		}
	}while(out<min || out>max);
	delete input;
    return out;
}

double InputDoubleNum(double min, double max, int language)
{
	char* input=new char[50];
	char* endptr;
	int temp;
	double out;
	do{
		do{
			gets(input);
			temp=isnum(input);
			if(temp==0){
				PlayMediaFile();
				Newline(1);
				PrintMessage(language,4001,"Input");
				Newline(2);
				PrintMessage(language,4008,"Input");
			}			
		}while(temp==0);
		out=strtod(input,&endptr);          
		if(out<min || out>max){
			DataErrorMessage((int)min,(int)max,language);
			Newline(2);
			PrintMessage(language,4008,"Input");
		}
	}while(out<min || out>max);
	delete input;
    return out;
}

__int64 Input__int64Num(int language)
{
	char* input=new char[50];
	__int64 out,min=0,max=UINT_MAX;
	int temp;
	do{
		do{
			gets(input);
			temp=isnum(input);
			if(temp==0){
				PlayMediaFile();
				Newline(1);
				PrintMessage(language,4001,"Input");
				Newline(2);
				PrintMessage(language,4008,"Input");
			}
		}while(temp==0);
		out=_atoi64(input);
		if(out<min || out>max){
			PlayMediaFile();
			Newline(1);
			PrintMessage(language,4002,"Input");
			Newline(2);
			PrintMessage(language,4003,"Input");
			Newline(2);
			PrintMessage(language,3041,"Rand");
			printf("%d",NON_NEGATIVE);
			printf("\t");
			PrintMessage(language,3042,"Rand");
			printf("%s","4294967295");
			Newline(2);
			PrintMessage(language,4008,"Input");
		}
	}while(out<min || out>max);
	delete input;
    return out;
}

int DataWarn(int input, int max, int language)
{
	int key;
	if(input>max){
		PlayMediaFile();
		Newline(2);
		PrintMessage(language,4005,"Input");
		Newline(2);
		PrintMessage(language,4006,"Input");
		Newline(2);
		PrintMessage(language,4007,"Input");
		Newline(1);
		do{
			key=tolower(_getch());
		}while(key!='y' && key!='n' && key!='t');
		if(key=='y'){
			return ACCEPT;
		}
		if(key=='t'){
			MathHelp(language);
			return REFUSE;
		}
		else{
			return REFUSE;
		}
	}
	else{
		return ACCEPT;
	}
}

void DataErrorMessage(int min, int max, int language)
{
	PlayMediaFile();
	ClearScreen();
	Newline(1);
	PrintMessage(language,4002,"Input");
	Newline(2);
	PrintMessage(language,4003,"Input");
	Newline(2);
	PrintMessage(language,3041,"Rand");
	printf("%d",min);
	printf("\t");
	PrintMessage(language,3042,"Rand");
	printf("%d",max);
	return;
}