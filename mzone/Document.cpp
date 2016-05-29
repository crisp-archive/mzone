
/*

  Math Zone Source
  
    Module name      - Document.cpp
	Abstract         - Functions and procedures which use to process the 'mzl' files
	Author           - David Zhang (30-Apr-2006) 
	
*/

#include "stdafx.h"


int ProcessFile(int argc, char* argv[], int language)
{
	int key,loop=1;
	FILE* open;
	if(argc==2){
		open=fopen(argv[1],"r");
		if(!open){
			return 0;
		}
		else{
			fclose(open);
			ClearScreen();
			while(loop==1){
				Newline(2);
				PrintMessage(language,2036,"File");
				Newline(2);
				ShowInfo(argv[1],language);
				Newline(2);
				PrintMessage(language,2040,"File");
				printf("\t");
				PrintMessage(language,2047,"File");
				printf("\t");
				PrintMessage(language,2042,"File");
				printf("\t");
				PrintMessage(language,2045,"File");
				printf("\t");
				do{
					key=tolower(_getch());
					switch(key){
					case 'a':
						ViewFile(argv[1]);
						PrintMessage(language,2046,"File");
						_getch();
						ClearScreen();
						break;
					case 'l':
						return 1;
						break;
					case 'd':
						SelectLanguage();
						language=GetLanguageInfo();
						ProcessFile(argc,argv,language);
						break;
					case 'q':
						exit(EXIT_SUCCESS);
						break;
					default:
						break;
					}
				}while(key!='a' && key!='l' && key!='q');
			}
			return 1;
		}
	}
	else{
		return 0;
	}
}

int ShowInfo(char* path, int language)
{
	MZLFILEINFO mzlFileInfo;
	mzlFileInfo.ID=GetPrivateProfileInt("Info","ID",0,path);
	mzlFileInfo.version=GetPrivateProfileInt("Info","Version",0,path);
	GetPrivateProfileString("Info","Language","Language",mzlFileInfo.name,50,path);
	GetPrivateProfileString("Info","Copyright","Copyright",mzlFileInfo.copyright,50,path);
	PrintMessage(language,2043,"File");
	Newline(2);
	PrintMessage(language,2037,"File");
	printf(" %s",mzlFileInfo.name);
	Newline(2);
	PrintMessage(language,2038,"File");
	printf(" %d\t",mzlFileInfo.ID);
	PrintMessage(language,2039,"File");
	printf(" %d",mzlFileInfo.version);
	Newline(2);
	PrintMessage(language,2044,"File");
	printf(" %s",mzlFileInfo.copyright);
	return 0;
}

void ViewFile(char* name)
{
	FILE* open;
	char line[LINESIZE];
	open=fopen(name,"r");
	ClearScreen();
	while(GetLine(open,line)==1){
		GetLine(open,line);
		Newline(1);
		printf("%s",line);
	}
	fclose(open);
	Newline(2);
}

int GetLine(FILE *infile, char *line)
{
	int p=0,c;
    c=fgetc(infile);
	if(c==EOF){
		return 0;
	}
	while(c!='\n'){
		if(p>LINESIZE-1){
			return 0;
		}
		if(c==EOF){
			return 0;
		}
		line[p++]=c;
		c=fgetc(infile);
	}
	line[p]=0;
	return 1;
}
