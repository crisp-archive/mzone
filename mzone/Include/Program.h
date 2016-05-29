
/*

  Math Zone Source
  
    Module name      - Program.h
	Abstract         - Procedures' and constants definitions and reference
	Author           - David Zhang (02-May-2006) 
	
*/

#ifndef _PROGRAM_H
#define _PROGRAM_H

void MathMain(char* version, int language);
void MathTip(int language);
void Menu(int language);
void GetKey(char* version, int language);
void RunFunction(int key, char* version, int language);
void About(char* version, int language);
void Reset(char* version);
int MathHelp(int language);

void Line(int time);
void Newline(int time);
#define ClearScreen() system("cls")

#define FILE_NOT_EXISTED 0
int IsFileExist(char* path);

int PlayMediaFile();
#ifndef SPECIAL_VERSION
void MathAd(int adID);
void ShowAd();
#endif

#define ID_WEBSITE 1001
#define ID_EMAIL 1002
#define ID_UPDATE 1003
#define ID_CALLHELP 1004
#define ID_PLUGIN 1005
int GetInTouch(int nInTouchId);

void BestWishes();

#endif
