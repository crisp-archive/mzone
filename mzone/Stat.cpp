
/*

  Math Zone Source
  
    Module name      - Stat.cpp
	Abstract         - Functions which use to count the Average, Variance, and Standard deviation
	Author           - David Zhang (03-May-2006)
	
*/

#include "stdafx.h"


double GetTotal(double data[MAX_COUNTER], int counter)
{
	double total=0;
	int i;
	for(i=0;i<counter;i++){
		total+=data[i];
	}
	return total;
}

double GetAverage(double total, int counter)
{
	return total/(double)counter;
}

void PreStat(int language)
{
	double data[MAX_COUNTER],total;
	int counter=0,key='a',isinput,modify;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3069,"Stat");
	Newline(1);
	while(key!='f'){
		isinput=1;
		if(key=='m' && counter!=0){
			PrintMessage(language,3070,"Stat");
			modify=InputIntNum(INT_MIN,INT_MAX,language);
			Newline(2);
			PrintMessage(language,3071,"Stat");
			data[modify-1]=InputDoubleNum(INT_MIN,INT_MAX,language);
			isinput=0;
		}
		if(isinput==1){
			Newline(1);
			PrintMessage(language,3020,"Prim");
			data[counter]=InputDoubleNum(INT_MIN,INT_MAX,language);
			counter++;
			if(counter==MAX_COUNTER){
				PrintMessage(language,3080,"Stat");
			}
		}
		ClearScreen();
		Newline(1);
		total=GetTotal(data,counter);
		PrintStatInfo(total,counter,language);
		PrintAverage(data,counter,language);
		PrintVariance(data,counter,language);
		PrintStandardDeviation(GetVariance(data,counter),language);
		Newline(2);
		PrintMessage(language,3072,"Stat");
		Newline(2);
		PrintMessage(language,3073,"Stat");
		key=tolower(_getch());
		ClearScreen();
		Newline(1);
	}
	Menu(language);
	return;
}

void PrintAverage(double data[MAX_COUNTER], int counter, int language)
{
	Newline(2);
	double total=GetTotal(data,counter);
	double result=GetAverage(total,counter);
	PrintMessage(language,3074,"Stat");
	Newline(2);
	printf("\t%f",result);
	return;
}

double GetVariance(double data[MAX_COUNTER], int counter)
{
	double total=GetTotal(data,counter);
	double average=GetAverage(total,counter),temp=0,result;
	int i;
	for(i=0;i<counter;i++){
		temp+=((data[i]-average)*(data[i]-average));
	}
	result=temp/counter;
	return result;
}

void PrintVariance(double data[MAX_COUNTER], int counter, int language)
{
	Newline(2);
	PrintMessage(language,3075,"Stat");
	printf("\t%f",GetVariance(data,counter));
	return;
}

double GetStandardDeviation(double sqrdiff)
{
	return sqrt(sqrdiff);
}

void PrintStandardDeviation(double sqrdiff, int language)
{
	Newline(2);
	PrintMessage(language,3076,"Stat");
	printf("\t%f",GetStandardDeviation(sqrdiff));
	return;
}

void PrintStatInfo(double total, int counter, int language)
{
	PrintMessage(language,3077,"Stat");
	printf(" %d\t",counter);
	PrintMessage(language,3078,"Stat");
	printf(" %f",total);
	return;
}
