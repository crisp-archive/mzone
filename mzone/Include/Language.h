
/*

  Math Zone Source
  
    Module name      - Language.h
	Abstract         - Functions, constants and procedures' definitions
	Author           - David Zhang (16-Apr-2006) 
	
*/

#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#define UN_SELECTED 0x00

#define CHINESE    10001
#define ENGLISH    10002
#define JAPANESE   10003
#define KOREAN     10004
#define T_CHINESE  10005
#define FRENCH     10006
#define GERMAN     10007
#define SPANISH    10008
#define RUSSIAN    10009
#define PORTUGUESE 10010
#define ITALIAN    10011
#define ARABIAN    10012

#define MIN_LANGUAGE 10001
#define MAX_LANGUAGE 10012

void SelectLanguage();
int GetLanguageInfo();
void ChangeLanguage(int language);

#endif
