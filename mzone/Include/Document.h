
/*

  Math Zone Source
  
    Module name      - Document.h
	Abstract         - Functions and procedures' definitions 
	Modified         - David Zhang (1-Oct-2004) 
	
*/

typedef struct tagMZLFILEINFO
{
	char name[50];
	int ID;
	int version;
	char copyright[50];
} MZLFILEINFO;

#define LINESIZE MAX_PATH

int ProcessFile(int argc, char* argv[], int language);
int ShowInfo(char* path, int language);
void ViewFile(char* name);
int GetLine(FILE* infile, char* line);
