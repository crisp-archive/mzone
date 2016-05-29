
/*

  Math Zone Source
  
    Module name      - Calculate.cpp
	Abstract         - Main mathematical functions 
	Author           - David Zhang (02-May-2006)
	
*/   

#include "stdafx.h"

void GetRemainder(int divisor, int dividend, int step)
{
	int k,i,c;
	k=(int)(divisor/dividend);
	printf("%d.",k);
	divisor=10*(divisor-k*dividend);
	for(i=1;i<=step;i++){
		c=(int)(divisor/dividend);
		printf("%d",c);
		divisor=10*(divisor-c*dividend);
		if(i%60==0){
			Newline(1);
		}
	}
	return;
}

EQUAROOT GetEquationRoot(double a, double b, double c)
{
	double temp;
	EQUAROOT root;
	temp=sqrt(b*b-4*a*c);
	root.x1=(-b+temp)/2*a;
	root.x2=(-b-temp)/2*a;
	return root;
}

int GetMaximumCommonDivisor(int a, int b)
{
	int i;
	if(a==b){
		return a;
	}
	if(a>b){
		for(i=b;i>=1;i--){
			if(a%i==0 && b%i==0){
				break;
			}
		}
	}
	if(b>a){
		for(i=a;i>=1;i--){
			if(a%i==0 && b%i==0){
				break;
			}
		}
	}
	return i;
}

int GetMinimumCommonMultiple(int a, int b)
{
	int i,j;
	int control=1;
	for(i=1;i<=b;i++){
		for(j=1;j<=a;j++){
			if(i*a==j*b){
				control=0;
				break;
			}
		}
		if(control==0){
			break;
		}
	}
	return i*a;
}

double GetCircleArea(double radius)
{
	return PI*radius*radius;
}

int GetPrime(int min, int max)
{
	int i,j,temp;
	int counter=0;
	if(max==INT_MAX){
		counter=GetPrime(min,max-1);
		printf("%d",max);
		return counter+1;
	}
	else{
		if(min==2){
			printf("2,");
			counter++;
		}
		for(j=min;j<=max;j++){
			if(j%2!=0){
				temp=(int)sqrt((double)j)+3;
				for(i=3;i<temp;i+=2){
					if(j%i==0){
						break;
					}
				}
				if(abs(i-temp)<=1){
					if(counter%8==0 && counter!=0){
						Newline(1);
					}
					printf("%d,",j);
					counter++;
				}
			}
		}
		return counter;
	}
}

void GetRandom(int min, int max, int times)
{
	int i,result;
	srand((unsigned)time(NULL));
	for(i=1;i<=times;i++){
		do{
			result=rand();
		}while(result<min || result>max);
		printf("%d,",result);
		if(i%8==0){
			Newline(1);
		}
	}
	return;
}

int GetPrimeDivisor(int data)
{
	int i,temp;
	int counter=0;
	temp=data;
	while(temp%2==0){
		temp/=2;
		if(counter==0){
			printf("%d",2);
		}
		else{
			printf("*%d",2);
		}
		counter++;
	}
	for(i=3;i<=temp;i+=2){
		while(temp%i==0){
			temp/=i;
			if(counter==0){
				printf("%d",i);
			}
			else{
				printf("*%d",i);
			}
			counter++;
		}
	}
	return counter;
}

int GetGoogle(int min, int max)
{
	int i,j,k,compare,result;
	int counter=0;
	for(i=min;i<=max;++i){
		for(j=i;j<=max;++j){
			for(k=j;k<=max;++k){
				if(i+j>k){
					result=i*i+j*j;
					compare=k*k;
					if(compare==result){
						printf("%d,%d,%d    ",i,j,k);
						counter++;
						if(counter%6==0 && counter!=0){
							Newline(1);
						}
					}
				}
			}
		}
	}
	return counter;
}

int GetDivisor(int data)
{
	int i,temp;
	int counter=0;
	for(i=1;i<=int(sqrt(double(data)));++i){
		temp=data%i;
		if(temp==0){
			if(counter%8==0 && counter!=0){
				Newline(1);
			}
			printf("%d,%d,",i,data/i);
			counter+=2;
		}
		else{
			continue;
		}
	}
	return counter;
}

void MakeMagicSquare(int a)
{
	int i,j,k,c;
	int m[MAGIC_MAX][MAGIC_MAX];
	c=a*a;
	j=0;
	k=a/2;
	for(i=1;i<=c;i++){
		m[j][k]=i;
		if(i%a==0){
			if(j==a-1){
				j=0;
			}
			else{
				j++;
			}
		}
		else{
			if(j==0){
				j=a-1;
			}
			else{
				j--;
			}
			if(k==a-1){
				k=0;
			}
			else{
				k++;
			}
		}
	}
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			printf("%4d",m[i][j]);
		}
		Newline(1);
	}
	return;
}

double GetSineValue(double degree)
{
	if(degree==90){
		return 1;
	}
	else{
		return sin(degree*PI/180);
	}
}

double GetCosineValue(double degree)
{
	if(degree==90){
		return 0;
	}
	else{
		return cos(degree*PI/180);
	}
}

double GetTangentValue(double degree)
{
	return tan(degree*PI/180);
}

double GetCotangentValue(double degree)
{
	return 1/GetTangentValue(degree);
}

double GetSecantValue(double degree)
{
	return 1/GetCosineValue(degree);
}

double GetCosecantValue(double degree)
{
	return 1/GetSineValue(degree);
}
