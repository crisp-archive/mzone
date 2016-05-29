
/*

  Math Zone Source
  
    Module name      - mzone.cpp
	Abstract         - Main program of Math Zone
	Author           - David Zhang (16-Apr-2006) 
	
*/ 

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#endif

CWinApp theApp;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int language,key;
	if(!AfxWinInit(::GetModuleHandle(NULL),NULL,::GetCommandLine(),0)){
		PlayMediaFile();
		key=tolower(_getch());
		ExitWindowsEx(EWX_REBOOT,NULL);
		return 0;
	}
	else{
		do{
			language=GetLanguageInfo();
			if(language==UN_SELECTED){
				SelectLanguage();
				language=GetLanguageInfo();
			}
		}while(language==UN_SELECTED);
		ProcessFile(argc,argv,language);
		do{
			language=GetLanguageInfo();
			if(language==UN_SELECTED){
				SelectLanguage();
				language=GetLanguageInfo();
			}
		}while(language==UN_SELECTED);
		MathTip(language);
		MathMain(CURRENT_VERSION,language);
		return 0;
	}
}
