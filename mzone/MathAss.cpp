
/*

  Math Zone Source
  
    Module name      - Calculate.cpp
	Abstract         - Math assistants' procedure
	Author           - David Zhang (10-Oct-2004) 
	
*/

#include "stdafx.h"


void PrintEquation(double a, double b, double c)
{
	if(a!=0){
		printf("%f X^2",a);
	}
	if(b!=0){
		if(b<0){
			printf("%f",b);
		}
		if(b>0){
			if(a!=0){
				printf("+ %f",b);
			}
			if(a==0){
				printf(" %f",b);
			}
		}
		printf(" X");
	}
	if(c!=0){
		if(c<0){
			printf("%f",c);
		}
		if(c>0){
			if(b!=0){
				printf("+ %f",c);
			}
			if(b==0){
				printf(" %f",c);
			}
		}
	}
	if(a!=0 || b!=0 || c!=0){
		printf("=0");
	}
	if(a==0 && b==0 && c==0){
		printf("0");
	}
	return;
}
