#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <alloc.h>
#include <stdarg.h>
#include <mem.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

//*********************************
//---------------------------------
//************Prototypes***********
//++++++++++++Menu Functions+++++++
void Menu(unsigned int x1,unsigned int y1,unsigned int bkColor,unsigned int textColor,unsigned int ActiveButtonColor,unsigned int SpaceBetweenButtons,char *string,...);
void Hide();
void Show();
void InitGraph(void);

void Engine();

//+++++++++++SubMenu Functions++++++
void AboutProgram(int x1,int y1,char *string,...);
void Parameters(int x1,int y1,char *string,...);
void Testing(int x1,int y1,char *string,...);
void Researching(int x1,int y1,char *string,...);
void GraphResult(int x1,int y1,char *string,...); //for buing tovar

//******************
MENU pMainMenu[5]={AboutProgram,Parameters,Testing,Researching,GraphResult};

#include "menu.cpp"