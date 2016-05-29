
/*

  Math Zone Source
  
    Module name      - Plug_In.cpp
	Abstract         - Procedures and functions that prepare for plug_ins  
	Author           - David Zhang (30-Apr-2006) 
	
*/

#include "stdafx.h"


int IsPlug_In(int sequence, char* menu)
{
	char* path=new char[MAX_PATH];
	char* temp=new char[4];
	GetCurrentDirectory(250,path);
	strcat(path,"\\PLUG_INS\\cpi.mzi");
	if(IsFileExist(path)==FILE_NOT_EXISTED){
		delete path,temp;
		return 0;
	}
	else{
		itoa(sequence,temp,10);
		GetPrivateProfileString(temp,"Name","?Plug_In",menu,20,path);
		delete path,temp;
		if(strcmp(menu,"?Plug_In")==0){
			return 0;
		}
		else{
			return 1;
		}
	}
}

void Plug_InMain(int language)
{
	int loop=1,key;
	while(loop==1){
		ClearScreen();
		Newline(1);
		PrintMessage(language,2029,"Plin");
		Newline(1);
		Line(78);
		Newline(1);
		PrintMessage(language,2031,"Plin");
		Newline(1);
		Line(78);
		Newline(1);
		ShowPlug_In(language);
		Newline(1);
		key=tolower(_getch());
		RunPlug_In(key);
	}
	return;
}

void ShowPlug_In(int language)
{
	int i,counter=0;
	char name[20];
	for(i=1;i<=23;i++){
		if(IsPlug_In(i,name)==1){
			putchar(i+64);
			printf(": %s ",name);
			counter++;
			if(counter%5==0){
				Newline(2);
			}
		}
	}
	if(counter==0){
		PrintMessage(language,2030,"Plin");
	}
	else{
		Newline(1);
		Line(78);
	}
	return;
}

void RunPlug_In(int key)
{
	if(key=='z'){
		Reset(CURRENT_VERSION);
	}
	else if(key=='y'){
		ImportPlug_In(GetLanguageInfo());
	}
	else if(key=='x'){
		GetInTouch(ID_PLUGIN);
	}
	else{
		char* path=new char[MAX_PATH];
		char* file=new char[MAX_PATH];
		char* temp=new char[4];
		GetCurrentDirectory(250,path);
		strcat(path,"\\PLUG_INS\\cpi.mzi");
		itoa(key-96,temp,10);
		GetPrivateProfileString(temp,"File","?Plug_In",file,250,path);
		ShellExecute(NULL,"open",file,NULL,NULL,SW_SHOWNORMAL);
		delete path,file,temp;
	}
	return;
}

void ImportPlug_In(int language)
{
	int key,inkey;
	char name[250],file[MAX_PATH],temp[20],app[2];
	char* path=new char[MAX_PATH];
	ClearScreen();
	Newline(1);
	PrintMessage(language,2063,"Plin");
	Newline(2);
	PrintMessage(language,2064,"Plin");
	scanf("%s",&name);
	Newline(2);
	PrintMessage(language,2065,"Plin");
	scanf("%s",&file);
	if(IsFileExist(file)==FILE_NOT_EXISTED){
		ClearScreen();
		Newline(1);
		PrintMessage(language,2068,"Plin");
		Newline(2);
		PrintMessage(language,2069,"Plin");
		_getch();
		delete path;
		return;
	}
	Newline(2);
	PrintMessage(language,2066,"Plin");
	do{
		key=tolower(_getch());
		if(key<97 || key>119){
			ClearScreen();
			Newline(1);
			PrintMessage(language,2071,"Plin");
			Newline(2);
			PrintMessage(language,2066,"Plin");
		}
	}while(key<97 || key>119);
	if(IsPlug_In(key-96,temp)==1){
		ClearScreen();
		Newline(1);
		PrintMessage(language,2067,"Plin");
		Newline(2);
		PrintMessage(language,2070,"Plin");
		do{
			inkey=tolower(_getch());
		}while(inkey!='a' && inkey!='s');
		if(key=='s'){
			delete path;
			return;
		}
	}
	itoa(key-96,app,10);
	GetCurrentDirectory(250,path);
	strcat(path,"\\PLUG_INS\\cpi.mzi");
	WritePrivateProfileString(app,"Name",name,path);
	WritePrivateProfileString(app,"File",file,path);
	delete path;
	return;
}
