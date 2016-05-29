
/*

  Math Zone Source
  
    Module name      - MathProc.cpp
	Abstract         - Procedures that prepare for calculating  
	Author           - David Zhang (02-May-2006) 
	
*/   

#include "stdafx.h"


void PreRemainder(int language)
{
	int divisor,dividend,step;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3011,"Rema");
	Newline(2);
	PrintMessage(language,3012,"Rema");
	divisor=InputIntNum(0,INT_MAX,language);
	Newline(2);
	PrintMessage(language,3013,"Rema");
	dividend=(int)InputDoubleNum(1,DIVIDEND_MAX,language);
	Newline(2);
	PrintMessage(language,3084,"Rema");
	step=InputIntNum(1,1000,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3014,"Rema");
	printf(" %d    ",divisor);
	PrintMessage(language,3024,"Rema");
	printf(" %d    ",dividend);
	PrintMessage(language,3035,"Rema");
	printf(" %d    ",step);
	Newline(2);
	PrintMessage(language,3036,"Rema");
	Newline(2);
	if(divisor!=0){
		GetRemainder(divisor,dividend,step);
	}
	else{
		printf("0");
	}
	Newline(1);
	return;
}

void PreEquationRoot(int language)
{
	EQUAROOT root;
	double a,b,c;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3015,"Eqrt");
	do{
		Newline(2);
		printf("ax*x+bx+c=0");
		Newline(2);
		PrintMessage(language,3016,"Eqrt");
		Newline(2);
		printf("a:");
		a=InputDoubleNum(AC_MIN,AC_MAX,language);
		Newline(2);
		printf("b:");
        b=InputDoubleNum(B_MIN,B_MAX,language);
		Newline(2);
		printf("c:");
		c=InputDoubleNum(AC_MIN,AC_MAX,language);
		if(b*b-4*a*c<NON_NEGATIVE){
			PlayMediaFile();
			Newline(1);
			PrintMessage(language,3017,"Eqrt");
			printf("%d",NON_NEGATIVE);
		}
	}while(b*b-4*a*c<NON_NEGATIVE);
	Menu(language);
	Newline(1);
	PrintEquation(a,b,c);
	Newline(2);
	PrintMessage(language,3018,"Eqrt");
	root=GetEquationRoot(a,b,c);
	Newline(2);
	if(root.x1==root.x2){
		printf("x=%f",root.x1);
	}
	else{
		printf("x1=%f    x2=%f",root.x1,root.x2);
	}
	Newline(1);
	return;
}

void PrePrime(int language)
{
	int min,max,mintemp,maxtemp,counter;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3019,"Prim");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	min=InputIntNum(PRIME_MIN,PRIME_MAX,language);
	mintemp=min;
	if(min>INT_MAX-1500){
		maxtemp=INT_MAX;
	}
	else{
		maxtemp=min+1500;
	}
	Newline(2);
	PrintMessage(language,3021,"Prim");
	max=InputIntNum(mintemp,maxtemp,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3022,"Prim");
	printf(" %d - %d:",min,max);
	Newline(2);
	counter=GetPrime(min,max);
	Newline(2);
	PrintMessage(language,3023,"Prim");
	printf(" %d",counter);
	Newline(1);
	return;
}

void PreRandom(int language)
{
	int max,min,times,mintemp;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3037,"Rand");
	Newline(2);
	PrintMessage(language,3038,"Rand");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	min=InputIntNum(RANDOM_MIN,RAND_MAX-1,language);
	mintemp=min;
	Newline(2);
	PrintMessage(language,3021,"Prim");
	max=InputIntNum(mintemp,RAND_MAX,language);
	Newline(2);
	PrintMessage(language,3039,"Rand");
	times=InputIntNum(1,RANDOM_TIME_MAX,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3040,"Rand");
	Newline(2);
	PrintMessage(language,3041,"Rand");
	printf(" %d\t",min);
	PrintMessage(language,3042,"Rand");
	printf(" %d\t",max);
	PrintMessage(language,3043,"Rand");
	printf(" %d\t",times);
	Newline(2);
	GetRandom(min,max,times);
	Newline(1);
	return;
}

void PrePrimeDivisor(int language) 
{
	int data,control,counter;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3044,"Pdiv");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	data=InputIntNum(PRIME_MIN,INT_MAX,language);
	if(data%2==0){
		control=ACCEPT;
	}
	else{
		control=DataWarn(data,2000000000,language);
	}
	if(control==ACCEPT){
		Menu(language);
		Newline(1);
		PrintMessage(language,3045,"Pdiv");
		printf(" %d:",data);
		Newline(2);
        counter=GetPrimeDivisor(data);
		if(counter==1){
			Newline(2);
			PrintMessage(language,3046,"Pdiv");
		}	
		Newline(2);
		PrintMessage(language,3023,"Prim");
		printf(" %d",counter);
		Newline(1);
	}
	if(control==REFUSE){
		Menu(language);
	}
	return;
}

void PreGoogle(int language)
{
	int max,min,mintemp,maxtemp,counter;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3047,"Pyno");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	min=InputIntNum(NON_NEGATIVE,GOOGLE_MAX-1,language);
	mintemp=min;
	maxtemp=min+1000;
	Newline(2);
	PrintMessage(language,3021,"Prim");
	max=InputIntNum(mintemp,maxtemp,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3048,"Pyno");
	printf(" %d - %d",min,max);
	Newline(2);
	counter=GetGoogle(min,max);
	Newline(2);
	PrintMessage(language,3023,"Prim");
	printf(" %d",counter);
	Newline(1);
	return;
}

void PreMaximumDivisor(int language)
{
	int a,b,result,control;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3049,"MaCD");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	a=InputIntNum(1,INT_MAX,language);
	Newline(2);
	PrintMessage(language,3050,"MaCD");
	b=InputIntNum(1,INT_MAX,language);
	if(a>960000000 || b>960000000){
		if(a!=b){
			control=DataWarn(b,960000000,language);
		}
	}
	else{
		control=ACCEPT;
	}
	if(control==ACCEPT){
		Menu(language);
		Newline(1);
		PrintMessage(language,3051,"MaCD");
		printf(" %d, %d:",a,b);
		result=GetMaximumCommonDivisor(a,b);
		Newline(2);
		printf("%d",result);
		if(a!=1 && b!=1 && result==1){
			Newline(2);
			PrintMessage(language,3052,"MaCD");
		}
		Newline(1);
	}
	if(control==REFUSE){
		Menu(language);
	}
	return;
}

void PreDivisor(int language)
{
	int data,counter;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3053,"Divi");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	data=InputIntNum(2,INT_MAX,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3054,"Divi");
	printf(" %d",data);
	Newline(2);
	counter=GetDivisor(data);
	Newline(2);
	PrintMessage(language,3023,"Prim");
	printf(" %d",counter);
	Newline(1);
	return;
}

void PreMinimumMultiple(int language)
{
	int a,b,result;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3055,"MiCM");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	a=InputIntNum(1,MIN_MULTIPLE_MAX,language);
	Newline(2);
	PrintMessage(language,3021,"Prim");
	b=InputIntNum(1,MIN_MULTIPLE_MAX,language);
	Menu(language);
	Newline(1);
	PrintMessage(language,3056,"MiCM");
	printf(" %d, %d",a,b);
	result=GetMinimumCommonMultiple(a,b);
	Newline(2);
	printf("%d",result);
	Newline(1);
	return;
}

void PreMagicSquare(int language)
{
	int a,control;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3057,"Masq");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	a=InputIntNum(MAGIC_MIN,MAGIC_MAX,language);
	control=DataWarn(a,24,language);
	if(control==ACCEPT){
		Menu(language);
		Newline(1);
		printf("%d*%d ",a,a);
		PrintMessage(language,3058,"Masq");
		Newline(2);
		MakeMagicSquare(a);
		Newline(1);
	}
	if(control==REFUSE){
		Menu(language);
	}
	return;
}

void PreTrigonometricFunctions(int language)
{
	double data,sine,cosine,tangent,cotangent,secant,cosecant;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3059,"Tfun");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	data=InputDoubleNum(NON_NEGATIVE,INT_MAX,language);
	Menu(language);
	sine=GetSineValue(data);
	cosine=GetCosineValue(data);
	Newline(1);
	Newline(1);
	PrintMessage(language,3060,"Tfun");
	printf(" %f",data);
	Newline(2);
	PrintMessage(language,3061,"Tfun");
	printf(" %f\t",sine);
	PrintMessage(language,3062,"Tfun");
	printf(" %f",cosine);
	if((int)data%90!=0){
		tangent=GetTangentValue(data);
		cotangent=GetCotangentValue(data);
		Newline(2);
		PrintMessage(language,3063,"Tfun");
		printf(" %f\t",tangent);
		PrintMessage(language,3064,"Tfun");
		printf(" %f",cotangent);
		secant=GetSecantValue(data);
		Newline(2);
		PrintMessage(language,3065,"Tfun");
		printf(" %f\t",secant);
	}
	else{
		Newline(2);
	}
	if((int)data%180!=0){
		cosecant=GetCosecantValue(data);
		PrintMessage(language,3066,"Tfun");
		printf(" %f\t",cosecant);
	}
	Newline(1);
	return;
}

void PreFactorial(int language)
{
	DWORD n,*buff;
	int control,buffLen;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3067,"Fact");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	n=(DWORD)InputIntNum(FACTORIAL_MIN,FACTORIAL_MAX,language);
	control=DataWarn(n,1500,language);
	if(control==ACCEPT){
		buffLen=(int)((GetResultLength(n)+8)/9);
		buff=new DWORD[buffLen];
		GetFactorial(buff,buffLen,n);
		Menu(language);
		PrintResult(n,buff,buffLen,language);
		delete buff;
	}
	if(control==REFUSE){
		Menu(language);
	}
	return;
}

void PreSystemConvert(int language)
{
	DWORD data;
	ClearScreen();
	Newline(1);
	PrintMessage(language,3068,"Conv");
	Newline(2);
	PrintMessage(language,3020,"Prim");
	data=(DWORD)Input__int64Num(language);
	Menu(language);
	ConvertDecimalNumber(data,language);
	return;
}
