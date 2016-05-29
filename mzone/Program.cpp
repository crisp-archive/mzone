
/*

  Math Zone Source
  
    Module name      - Program.cpp
	Abstract         - Main procedures that control the program 
	Author           - David Zhang (03-May-2006)
	
*/ 

#include "stdafx.h"

int lastID;

void MathMain(char* version, int language)
{
	char path[]="mzg.mzl";
	int exist=IsFileExist(path);
	if(exist==FILE_NOT_EXISTED){
		ClearScreen();
		Newline(1);
		if(language==ENGLISH){
			printf("File doesn't exist: mzg.mzl");
		}
		if(language==CHINESE){
			printf("重要文件丢失: mzg.mzl");
		}
		system("pause");
		exit(EXIT_SUCCESS);
		return;
	}
	Menu(language);
#ifndef SPECIAL_VERSION
	ShowAd();
#endif
	GetKey(version,language);
	return;
}

void MathTip(int language)
{
	int key,init=2051;
	FILE* open;
	char path[]="mtip.mzi";
	int exist=IsFileExist(path);
	if(exist==FILE_NOT_EXISTED){
		do{
			ClearScreen();
			Newline(1);
			PrintMessage(language,2048,"Tips");
			Newline(2);
			PrintMessage(language,2049,"Tips");
			Newline(2);
			PrintMessage(language,2050,"Tips");
			Newline(3);
			PrintMessage(language,init,"Tips");
			Newline(2);
			PrintMessage(language,init+1,"Tips");
			key=tolower(_getch());
			if(key=='a'){
				return;
			}
			if(key=='l'){
				open=fopen(path,"w");
				return;
			}
			if(key=='m' && init<=2059){
				init+=2;
			}
			if(key=='n'  && init>=2053){
				init-=2;
			}
		}while(key!='a' || key!='n' || key!='m' || key!='l');
	}
	else{
		return;
	}
}

void GetKey(char* version, int language)
{
	int key;
	int loop=1;
	while(loop==1){
		key=tolower(_getch());
		if(key==' '){
			RunFunction(lastID,version,language);
		}
		else{
			RunFunction(key,version,language);
			lastID=key;
		}
	}
	return;
}

void RunFunction(int key, char* version, int language)
{
	switch(key){
	case 'z':
		PreRemainder(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'x':
		PreEquationRoot(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'c':
		PrePrime(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'v':
		PreFactorial(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'b':
		PreRandom(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'm':
		PreGoogle(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'a':
		PreDivisor(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 's':
		PreMagicSquare(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'n':
		PrePrimeDivisor(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'd':
		PreMaximumDivisor(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'f':
		PreMinimumMultiple(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'g':
		PreTrigonometricFunctions(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'h':
		PreSystemConvert(language);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'j':
		PreStat(language);
		Newline(1);
		PrintMessage(language,2012,"Menu");
		Newline(1);
		break;
	case 'w':
		About(version,language);
#ifndef SPECIAL_VERSION
		ShowAd();
#endif
		break;
	case 't':
		if(language==CHINESE || language==ENGLISH){
			MathHelp(language);
			Reset(version);
			break;
		}
		else{
			break;
		}
	case 'y':
		GetMathMark(language);
		break;
	case 'e':
		SelectLanguage();
		Reset(version);
		break;
	case 'u':
		Plug_InMain(language);
		break;
	case 'r':
		Reset(version);
		break;
	case 'q':
		ClearScreen();
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}
	return;
}

void Menu(int language)
{
	ClearScreen();
	int linenumber,menuline,i;
	Newline(1);
	PrintMessage(language,2014,"Menu");BestWishes();
	Newline(1);
	menuline=GetProfileValue(language,2013);
	linenumber=GetProfileValue(language,2015);
	Line(linenumber);
	for(i=2016;i<2016+menuline;i++){
		Newline(1);
		PrintMessage(language,i,"Menu");
		Newline(1);
	}
	Line(linenumber);
	Newline(1);
	return;
}

void About(char* version, int language)
{
	int key;
	ClearScreen();
	Newline(1);
	PrintMessage(language,2020,"About");
	Newline(2);
	PrintMessage(language,2021,"About");
	Newline(2);
	PrintMessage(language,2022,"About");
	printf(" <%s>",version);
	Newline(3);
	PrintMessage(language,2023,"About");
	Newline(2);
	PrintMessage(language,2026,"About");
	Newline(2);
	PrintMessage(language,2028,"About");
	Newline(3);
	PrintMessage(language,2024,"About");
	Newline(2);
	PrintMessage(language,2025,"About");
	Newline(2);
	PrintMessage(language,2027,"About");
	Newline(1);
	key=tolower(_getch());
	switch(key){
	case 'a':
		GetInTouch(ID_WEBSITE);
		break;
	case 's':
		GetInTouch(ID_EMAIL);
		break;
	case 'd':
		MathHelp(language);
		break;
	case 'f':
		GetInTouch(ID_UPDATE);
		break;
	default:
		Menu(language);
	}
	Menu(language);
	return;
}

void Reset(char* version)
{
	int language;
	do{
		language=GetLanguageInfo();
		if(language==UN_SELECTED){
			SelectLanguage();
			language=GetLanguageInfo();
		}
	}while(language==UN_SELECTED);
	MathMain(version,language);
	return;
}

void Line(int time)
{
	int i;
	for(i=0;i<time;++i){
		printf("-");
	}
	return;
}

void Newline(int time)
{
	int i;
	if(time==0){
		return;
	}
	if(time==1){
		printf("\n ");
	}
	else{
		for(i=1;i<=time;i++){
			printf("\n");
		}
		printf(" ");
	}
	return;
}

int MathHelp(int language)
{
	int status;
	status=GetInTouch(ID_CALLHELP);
	if(status==0){
		ClearScreen();
		Newline(1);
		PrintMessage(language,2032,"Help");
		Newline(2);
		PrintMessage(language,2033,"Help");
		Newline(1);
		_getch();
		return 0;
	}
	return 1;
}

int PlayMediaFile()
{
	int status;
	status=PlaySound("CHORD.wav",NULL,SND_ALIAS);
	if(status==0){
		return 0;
	}
	return 1;
}

int GetInTouch(int nInTouchId)
{
	int status;
	switch(nInTouchId){
	case ID_UPDATE:
		status=(int)ShellExecute(NULL,"open","http://crispgm.googlepages.com/mzone.rar",NULL,NULL,SW_SHOWNORMAL);
		break;
	case ID_WEBSITE:
		status=(int)ShellExecute(NULL,"open","http://crispgm.googlepages.com/",NULL,NULL,SW_SHOWNORMAL);
		break;
	case ID_EMAIL:
		status=(int)ShellExecute(NULL,"open","mailto:zhangwanlong@126.com?subject=Get in touch with author",NULL,NULL,SW_SHOWNORMAL);
		break;
	case ID_CALLHELP:
		status=(int)ShellExecute(NULL,"open","help.chm",NULL,NULL,SW_SHOWNORMAL);
		break;
	case ID_PLUGIN:
		status=(int)ShellExecute(NULL,"open","http://crispgm.googlepages.com/mathzoneplug_in",NULL,NULL,SW_SHOWNORMAL);
		break;
	default:
		status=31;
		break;
	}
	if(status<=32)
		return 0;
	else
		return 1;
}

#ifndef SPECIAL_VERSION
void MathAd(int adID)
{
	char* path=new char[MAX_PATH];
	char string[100],sID[5];
	GetCurrentDirectory(MAX_PATH-1,path);
	strcat(path,"\\mzg.mzl");
	itoa(adID,sID,10);
	GetPrivateProfileString("Advs",sID,sID,string,50,path);
	delete path;
	Newline(1);
	printf("%s",string);
	Newline(1);
}
#endif

int IsFileExist(char* path)
{
	FILE* open;
	open=fopen(path,"r");
	if(!open)
		return 0;
	else{
		fclose(open);
		return 1;
	}
}

#ifndef SPECIAL_VERSION
void ShowAd()
{
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);
	if(SystemTime.wYear-RELEASE_YEAR<=1){
		MathAd(2011);
	}
	return;
}
#endif

void BestWishes()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	int c=st.wMonth*100+st.wDay;
	char* path=new char[MAX_PATH];
	char temp[20],con[30];
	GetCurrentDirectory(MAX_PATH-1,path);
	strcat(path,"\\wish.mzl");
	int i,n;
	for(i=1;;i++){
		itoa(i,temp,10);
		n=GetPrivateProfileInt(temp,"date",0,path);
		if(n==0){
			break;
		}
		else{
			if(n==c){
				GetPrivateProfileString(temp,"con","",con,30,path);
				printf(" (%s)",con);
			}
		}
	}
	delete path;
	return;
}
