
/*

  Math Zone Source
  
    Module name      - Message.cpp
	Abstract         - Functions to process messages
	Author           - David Zhang (30-Apr-2006)
	
*/

#include "stdafx.h"


int GetMessageInfoPath(char* language, char* path)
{
	GetCurrentDirectory(250,path);
	strcat(path,"\\");
	strcat(path,language);
	strcat(path,".mzl");
	return 1;
}

int PrintMessage(int nLanguageId, int nMessageId, char* appname)
{
	char path[MAX_PATH];
	char MessageName[5];
	char message[MAX_MESSAGE];
	char sLanguageId[10];
	FILE* test;
	ConvertLanguageId(nLanguageId,sLanguageId);
	itoa(nMessageId,MessageName,10);
	GetMessageInfoPath(sLanguageId,path);
	test=fopen(path,"r");
	if(!test){
		return 0;
	}
	else{
		fclose(test);
	}
	GetPrivateProfileString(appname,MessageName,MessageName,message,MAX_MESSAGE,path);
	printf("%s",message);
	return 1;
}

int ConvertLanguageId(int nLanguageId, char* sLanguageId)
{
	int use;
	switch(nLanguageId){
	case CHINESE:
		strcpy(sLanguageId,"sch");
		use=1;
		break;
	case ENGLISH:
		strcpy(sLanguageId,"eng");
		use=1;
		break;
	case JAPANESE:
		strcpy(sLanguageId,"jpn");
		use=1;
		break;
	case KOREAN:
		strcpy(sLanguageId,"kor");
		use=1;
		break;
	case T_CHINESE:
		strcpy(sLanguageId,"tch");
		use=1;
		break;
	case FRENCH:
		strcpy(sLanguageId,"fre");
		use=1;
		break;
	case GERMAN:
		strcpy(sLanguageId,"ger");
		use=1;
		break;
	case SPANISH:
		strcpy(sLanguageId,"spa");
		use=1;
		break;
	case RUSSIAN:
		strcpy(sLanguageId,"ras");
		use=1;
		break;
	case PORTUGUESE:
		strcpy(sLanguageId,"por");
		use=1;
		break;
	case ITALIAN:
		strcpy(sLanguageId,"ita");
		use=1;
		break;
	case ARABIAN:
		strcpy(sLanguageId,"ara");
		use=1;
		break;
	default:
		use=0;
		break;
	}
	return use;
}

int GetProfileValue(int nLanguageId, int nValueId)
{
	char path[MAX_PATH];
	char sValueId[5];
	char sLanguageId[10];
	FILE* test;
	int data;
	ConvertLanguageId(nLanguageId,sLanguageId);
	GetMessageInfoPath(sLanguageId,path);
	test=fopen(path,"r");
	if(!test){
		return 0;
	}
	else{
		fclose(test);
	}
	itoa(nValueId,sValueId,10);
	data=GetPrivateProfileInt("Menu",sValueId,1,path);
	return data;
}
