
/*

  Math Zone Source
  
    Module name      - SpeedTest.cpp
	Abstract         - Functions and procedures to get the Math Mark 
	Author           - David Zhang (30-Apr-2006)
	
*/ 

#include "stdafx.h"


double MathGetCurrentTime(LARGE_INTEGER* freq)
{
	LARGE_INTEGER performanceCount;
	double time;
	BOOL result;
	result=QueryPerformanceCounter(&performanceCount);
	time=performanceCount.HighPart*4294967296.0+performanceCount.LowPart;
	time/=(freq->HighPart*4294967296.0+freq->LowPart);
	return time;
}

void GetMathMark(int language)
{
	int result1,result2,result3;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3027,"Test");
	Newline(1);
	Line(50);
	Newline(1);
	PrintMessage(language,3028,"Test");
	Newline(2);
	PrintMessage(language,3029,"Test");
	Newline(2);
	result1=GetIntMark();
	result2=GetFloatMark();
	result3=GetDiskMark();
	if(result1==1001 || result2==1001 || result3==1001){
		Newline(1);
		PlayMediaFile();
		PrintMessage(language,3025,"Test");
		Newline(2);
		PrintMessage(language,3026,"Test");
		_getch();
		Menu(language);
	}
	Menu(language);
	Newline(1);
	PrintMessage(language,3079,"Test");
	Newline(2);
	PrintMessage(language,3030,"Test");
	printf(" %d\t",result1);
	PrintMessage(language,3031,"Test");
	printf("%d",result2);
	Newline(2);
	PrintMessage(language,3081,"Test");
	printf(" %d",result3);
    Newline(2);
	PrintMessage(language,3032,"Test");
	Newline(2);
	PrintMessage(language,3033,"Test");
	Newline(2);
	PrintMessage(language,3034,"Test");
	Newline(2);
	PrintMessage(language,3083,"Test");
	Newline(1);
	return;
}

int GetIntMark()
{
	double start,end;
	int result;
	LARGE_INTEGER freq;
	if(!QueryPerformanceFrequency(&freq)){
		return 1001;
	}
	start=MathGetCurrentTime(&freq);
	GetPrimeDivisor(2100000001);
	end=MathGetCurrentTime(&freq);
	result=10000-(int)((end-start)*1000);
	if(result<0){
		result=0;
	}
	if(result>10000){
		result=10000;
	}
	return result;
}

int GetFloatMark()
{
	double start,end,temp,cache=0;
	int result,i;
	LARGE_INTEGER freq;
	if(!QueryPerformanceFrequency(&freq)){
		return 1001;
	}
	start=MathGetCurrentTime(&freq);
	for(i=1;i<=110000000;i++){
		temp=1/i;
		cache+=temp;
	}
	end=MathGetCurrentTime(&freq);
	result=10000-(int)((end-start)*1000);
	if(result<0){
		result=0;
	}
	if(result>10000){
		result=10000;
	}
	return result;
}

int GetDiskMark()
{
	FILE* open;
	double start,end;
	int result,i;
	char path[50],num[10];
	LARGE_INTEGER freq;
	if(!QueryPerformanceFrequency(&freq)){
		return 1001;
	}
	start=MathGetCurrentTime(&freq);
	mkdir("C:\\mztt");
	for(i=0;i<2200;i++){
		strcpy(path,"C:\\mztt\\");
		itoa(i,num,10);
		strcat(path,num);
		open=fopen(path,"w");
		fprintf(open,"Math Zone Hard Disk Speed Test");
		fclose(open);
	}
	for(i=0;i<2500;i++){
		strcpy(path,"C:\\mztt\\");
		itoa(i,num,10);
		strcat(path,num);
		DeleteFile(path);
	}
	RemoveDirectory("C:\\mztt");
	end=MathGetCurrentTime(&freq);
	result=10000-(int)((end-start)*1000);
	if(result<0){
		result=0;
	}
	if(result>10000){
		result=10000;
	}
	return result;
}
