
/*

  Math Zone Source
  
    Module name      - Factorial.cpp
	Abstract         - Functions that calculate factorial
	Modified         - David Zhang (30-Apr-2006) 
	
	  - The functions for calculating factorial is based on another programmer, 
	  but I have forgotten his name. So I could only say 'Thanks' to him.
	  
*/ 

#include "stdafx.h"


inline DWORD Div_TEN9_1(UINT64 x, DWORD* remainder)
{
	*remainder=(DWORD)(x%(UINT64)TEN9);
	return (DWORD)(x/(UINT64)TEN9);
}

inline DWORD Div_TEN9_2(UINT64 x, DWORD* remainder)
{
	_asm{
		lea ebx,x
			mov eax,[ebx]
			mov edx,[ebx+4]
			mov ebx,TEN9
			div ebx
			mov ebx,remainder
			mov [ebx],edx
	}
}

double GetResultLength(DWORD n)
{
	return log10(2*PI*(double)n)/2+n*log10((double)n/E)+1;
}

void PrintResult(DWORD n, DWORD* buff, int bufflen, int language)
{
	int i;
	DWORD* p=buff;
	while(*p==0){
		p++;
	}
	Newline(1);
	PrintMessage(language,3082,"Fact");
	printf(" %d",n);
	Newline(2);
	for(i=0;i<bufflen;i++){
		if(i==0){
			printf("%9d",p[i]);
		}
		else{
			printf("%09d",p[i]);
		}
		if(i%8==7){
			Newline(1);
		}
	}
	Newline(1);
	return;
}

void GetFactorial(DWORD* buff, int bufflen, DWORD n)
{
	int	len=1;
	DWORD i,carry,*p,*pEnd,*pBeg;
	UINT64 prod;
	memset(buff,0,sizeof(DWORD)*bufflen);
	pBeg=buff+bufflen-1;
	*pBeg=1;
	for(i=2;i<=n;){
		DWORD k;
		if(i<n-3){
			if(i<1000){
				k=i*(i+1)*(i+2);
				i+=3;	
			}
			else if(i<31621){ 
				k=i*(i+1);
				i+=2;
			}
			else{
				k=i; 
				i++;
			}
		}
		else{
			k=i;
			i++;
		}
		for(p=pBeg,pEnd=p-len,carry=0;p>pEnd;p--){
			prod=(UINT64)(*p)*(UINT64)k+(UINT64)carry;
			carry=Div_TEN9_2(prod,p);
		}
		if(carry>0){
			*(pBeg-len)=carry;
			len++;
		}
	}
	return;
}
