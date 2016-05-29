
/*

  Math Zone Source
  
    Module name      - Message.h
	Abstract         - Functions' definition
	Author           - David Zhang (30-Apr-2006) 
	
*/

#ifndef _MESSAGE_H
#define _MESSAGE_H

#define MAX_MESSAGE 250

int GetMessageInfoPath(char* language, char* path);
int PrintMessage(int nLanguageId, int nMessageId, char* appname);
int ConvertLanguageId(int nLanguageId, char* sLanguageId);
int GetProfileValue(int nLanguageId, int nValueId);

#endif
