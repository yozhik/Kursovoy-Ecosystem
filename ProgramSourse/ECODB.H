#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <mem.h>

#define TRUE 1
#define FALSE 0

#define READONLY 0
#define READnWRITE 1
#define REWRITECURRENT 2

char xArr[10]="x.dat";
char hemArr[10]="hem.dat";
char erArr[10]="er.dat";
char rkArr[10]="rk.dat";
char gArr[10]="g.dat";
//*********************
typedef struct Record1
  {
	double y0;
	double y1;
  }ECO;
typedef struct Record2
  {
	double x[SZ];
  }XY;

//***********************

//****Prototypes****//
int  CreateDB(char *path);
FILE *OpenDB(char *path,unsigned int mode);
void CloseDB(FILE *DataBase);
unsigned int GetSize(FILE *DataBase);
unsigned int GetDSize(FILE *DataBase);
void ConvertTXTtoBINARY(char *pathToTXT);
void ShowBinaryInfo(unsigned int wx1,unsigned int wy1,unsigned int tempWinLen, char *pathToBINARY, unsigned int mode);

#include "ecodb.cpp"