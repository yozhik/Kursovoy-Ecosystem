void SetDefault(void)
{
  settextstyle(0,0,0);
  setlinestyle(0,1,1);
}
unsigned int GetLeftXPos(unsigned int tempWinLen)
{
  unsigned int resLeftx1=(xmax-tempWinLen)/2;
  return resLeftx1;
}
//***********************
void Window(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkColor)
{
  setfillstyle(WINSTYLE,bkColor);
  setcolor(textColor);
  bar(lx,ly,x2,y2);
  setcolor(ActiveButtonColor);
  rectangle(lx,ly,x2,y2);
  rectangle(lx+1,ly+1,x2-1,y2-1);
  rectangle(lx+4,ly+4,x2-4,y2-4);
}
//********************
void WindowsVista(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkCol, char *msg)
{
  int i=0, zKin=lx+winLen,
  x_cen=(lx+winLen/2),
  y_cen=(ly+winHeight/2);
  //bar(lx,ly,x2,y2);
  setfillstyle(WINSTYLE,bkCol);
  for(i=1;i<(winLen/2);i+=1)
  {
    bar(x_cen-i,y_cen-i,x_cen+i,y_cen+i);
    delay(DELAYTIME+2);
  }
  setfillstyle(1,winHEAD);
  //bar(lx,ly,x2,ly+20);
  for(i=lx;i<zKin;i++)
  {
    bar(lx,ly,i,ly+20);
    delay(DELAYTIME+1);
  }
  setfillstyle(1,4);
  setcolor(2);
  bar(x2-17,ly+3,x2-3,ly+17);

  setcolor(15);
  line(x2-14,ly+6,x2-6,ly+14);
  line(x2-6,ly+6,x2-14,ly+14);

  rectangle(x2-16,ly+4,x2-4,ly+16);
//*******
  setfillstyle(1,4);
  setcolor(textColor);
  bar(x2-32,ly+3,x2-20,ly+17);

  setcolor(15);
  setfillstyle(1,15);
  rectangle(x2-31,ly+4,x2-21,ly+16);
  bar(x2-28,ly+6,x2-23,ly+12);
//********
  setfillstyle(1,4);
  setcolor(2);
  bar(x2-47,ly+3,x2-35,ly+17);

  setcolor(15);
  setfillstyle(1,15);
  rectangle(x2-46,ly+4,x2-36,ly+16);
  bar(x2-44,ly+13,x2-39,ly+14);
//************
  setcolor(ActiveButtonColor);
  rectangle(lx,ly,x2,y2);
  rectangle(lx+1,ly+1,x2-1,y2-1);
  setfillstyle(1,4);
  SetHButtonText(lx+5,ly+2,TEXT,msg);
}
//***********************
void WindowXP(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkCol, char *msg)
{

  int i=0, zKin=lx+winLen;
  setfillstyle(1,winHEAD);
  for(i=lx;i<zKin;i++)
  {
    bar(lx,ly,i,ly+20);
    delay(DELAYTIME);
  }
  setfillstyle(WINSTYLE,bkCol);
  for(i=ly+20;i<y2;i++)
  {
    bar(lx,ly+20,x2,i);
    delay(DELAYTIME);
  }
  setfillstyle(1,4);
  setcolor(2);
  bar(x2-17,ly+3,x2-3,ly+17);

  setcolor(15);
  line(x2-14,ly+6,x2-6,ly+14);
  line(x2-6,ly+6,x2-14,ly+14);

  rectangle(x2-16,ly+4,x2-4,ly+16);
//*******
  setfillstyle(1,4);
  setcolor(2);
  bar(x2-32,ly+3,x2-20,ly+17);

  setcolor(15);
  setfillstyle(1,15);
  rectangle(x2-31,ly+4,x2-21,ly+16);
  bar(x2-28,ly+6,x2-23,ly+12);
//********
  setfillstyle(1,4);
  setcolor(textColor);
  bar(x2-47,ly+3,x2-35,ly+17);

  setcolor(15);
  setfillstyle(1,15);
  rectangle(x2-46,ly+4,x2-36,ly+16);
  bar(x2-44,ly+13,x2-39,ly+14);
//************
  setcolor(ActiveButtonColor);
  rectangle(lx,ly,x2,y2);
  rectangle(lx+1,ly+1,x2-1,y2-1);
  setfillstyle(1,4);
  SetHButtonText(lx+5,ly+2,TEXT,msg);
}
//****************************
void StatusBar(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkColor,char *statusText)
{
  setfillstyle(WINSTYLE,bkColor);
  setcolor(textColor);
  bar(lx+2,ly-20,x2-2,y2-2);
  SetHButtonText(lx+leftVidstup,ly-20,TEXT,statusText);
}
//****************************
void RefreshDesctop(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2, int desctopColor)
{
  setfillstyle(DESCTOP_STYLE,desctopColor);
  setcolor(desctopColor);
  bar(x1,y1+2,x2,y2);//!!!!!!!!!!
}
//********************
void Hide()
{
  x1=1,x2=xmax,y1=1;
  RefreshDesctop(x1,y1,x2,y1+WinHeight,desctopColor);
}
//*****************
void SetHButtonText(unsigned int lx, unsigned int ly, int mode,char *str)
{
  memset(buttonText,'\0',LEN);
  strcpy(buttonText,str);
  int len=strlen(buttonText);
  switch(mode)
  {
    case ACTIVE:
      setfillstyle(1,ActiveButtonColor);
      setcolor(ActiveTextColor);
      bar(lx,ly,lx+8*len,ly+19);
      break;
    case NON_ACTIVE:
      setfillstyle(WINSTYLE,bkColor);
      setcolor(textColor);
      bar(lx,ly,lx+8*len,ly+19);
      break;
    case TEXT:
      setcolor(textColor);
    default: break;
  }
  outtextxy(lx,ly+5,buttonText);
}
//*****************
void SetVButtonText(unsigned int lx, unsigned int ly, unsigned int Width, int mode, char *str)
{
  memset(buttonText,'\0',LEN);
  strcpy(buttonText,str);
  switch(mode)
  {
    case ACTIVE:
      setfillstyle(1,ActiveButtonColor);
      setcolor(ActiveTextColor);
      bar(lx+5,ly,lx+Width*10+4,ly+18);
      break;
    case NON_ACTIVE:
      setfillstyle(WINSTYLE,bkColor);
      setcolor(textColor);
      bar(lx+5,ly,lx+Width*10+4,ly+18);
      break;
    case TEXT:
      setcolor(textColor);
    default: break;
  }
  outtextxy(lx+leftVidstup,ly+5,buttonText);
}
