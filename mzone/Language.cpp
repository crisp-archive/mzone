
/*

  Math Zone Source
  
    Module name      - Language.cpp
	Abstract         - Functions to get and select the language you like
	Author           - David Zhang (30-Apr-2006) 
	
*/  

#include "stdafx.h"


void SelectLanguage()
{
	int key,exist;
	char* path=new char[MAX_PATH];
	GetCurrentDirectory(MAX_PATH-1,path);
	strcat(path,"\\mzg.mzl");
	char string[50];
	exist=IsFileExist(path);
	if(exist==1){
		GetPrivateProfileString("Slct","2012","",string,50,path);
		delete path;
	}
	else{
		delete path;
		printf("\n\n File error!");
		system("pause");
		exit(EXIT_SUCCESS);
		return;
	}
	ClearScreen();
	Newline(1);
	printf("%s",string);
	do{
		key=tolower(_getch());
	}while(key!='a' && key!='s' && key!='d');
	switch(key){
	case 'a':
		ChangeLanguage(CHINESE);
		break;
	case 's':
		ChangeLanguage(ENGLISH);
		break;
	}
	return;
}

int GetLanguageInfo()
{
	FILE* open;
	int language,exist;
	char sLanguageId[4];
	open=fopen("mzlg.mzi","r");
	if(!open){
		return UN_SELECTED;
	}
	else{
		fscanf(open,"%d",&language);
		fclose(open);
		if(language>=CHINESE && language<=SPANISH){
			char* path=new char[MAX_PATH];
			ConvertLanguageId(language,sLanguageId);
			GetMessageInfoPath(sLanguageId,path);
			exist=IsFileExist(path);
			delete path;
			if(exist==1){
				return language;
			}
			else{
				printf("\n\n File error!");
				system("pause");
				return FILE_NOT_EXISTED;
			}
		}
		else{
			return UN_SELECTED;
		}
	}
}

void ChangeLanguage(int language)
{
	FILE* open=fopen("mzlg.mzi","w");
	if(!open){
		PlayMediaFile();
		ClearScreen();
		system("PAUSE");
		return;
	}
	fprintf(open,"%d",language);
	fclose(open);
	return;
}
