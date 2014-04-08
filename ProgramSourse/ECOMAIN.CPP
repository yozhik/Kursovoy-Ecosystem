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

#include "gvalue.h"
#include "xpstyle.h"
#include "ecodb.h"
#include  "difury.h"
#include "test.h"
#include "grafik.h"
#include "model.h"
#include "menu.h"


//***************Main****************
void main()
{
  clrscr();
  InitGraph();

  RefreshDesctop(1,1,xmax,ymax,desctopColor);//screen definition!!! BUG
  Menu(x1,y1,bkColor,textColor,ActiveButtonColor,SpaceBetweenButtons,
  "About Program","Parameters","Testing","Researching","Graph Result","Exit",NULL);
  closegraph();
  //*******FREE MEMORY********************
  free(buttonLenghtArray);
  free(buttonText);
  free(ppString);
}