//************Functions*****************
void InitGraph(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }
   xmax=getmaxx();
   ymax=getmaxy();
   SetDefault();
   buttonText=(char*)calloc(LEN,sizeof(char));
   if(!buttonText) exit(1);
   memset(buttonText,'\0',LEN);
   cleardevice();
}
void Menu(unsigned int x1,unsigned int y1,unsigned int bkColor,unsigned int textColor,unsigned int ActiveButtonColor,unsigned int SpaceBetweenButtons,char *string,...)
{
  count=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    count++;
    pString=va_arg(par,char*);
  }
  va_end(par);
 x2=xmax;
 Window(x1,y1,x2,y1+WinHeight,textColor,bkColor);
 unsigned char i=0;
 buttonLenghtArray=(int*)calloc(count,sizeof(int));
 if(buttonLenghtArray==NULL)
 {
   printf("Error! No free memory!");
   exit(0);
 }
 ppString=(char**)calloc(count,sizeof(char*));
 for(i=0;i<count;i++)
 {
   *ppString=NULL;
 }
 i=0;

 pString=string;
 va_start(par,string);
 while(pString!=NULL)
 {
   ppString[i]=pString;
   unsigned char textCount=0;
   while(*pString!='\0')
   {
     textCount++;
     pString++;
   }
   buttonLenghtArray[i]=textCount*10+SpaceBetweenButtons;//+++++
   i++;
   pString=va_arg(par,char*);
 }
 va_end(par);
 unsigned int temp_x1=x1+leftVidstup;
 for(i=0;i<count;i++)
 {
   SetHButtonText(temp_x1,y1+textRiven,NON_ACTIVE,ppString[i]);
   temp_x1+=buttonLenghtArray[i];
 }
   StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");////////////////
  setcolor(ActiveButtonColor);
  rectangle(1,1,xmax,ymax);
  rectangle(2,2,xmax-1,ymax-1);
 Engine();
}
//************************
void Engine()
{
  int i=0,menuHolder=0,fEnter=0,fLastMenuItem=0; //if Right then fRIGHTorLEFT=1; if Left then fRIGHTorLEFT=-1;
  int c=count,tmp=0;
  unsigned char temp=0;
  unsigned int a=leftVidstup;
  int *ar;
  ar=(int*)calloc(c,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(0);
  }
  for(i=0;i<c;i++)
  {
    ar[i]=i+1;
  }
  MenuIndex=menuHolder;
  i=0;
  while(1)
  {
    if(fEnter)
    {
      a=leftVidstup;
      for(temp=0;temp<(menuHolder-fLastMenuItem);temp++)
      {
		a+=buttonLenghtArray[temp];
      }
      x1=1;
      if(fLastMenuItem)
      {
	    SetHButtonText(a,y1+textRiven,ACTIVE,ppString[menuHolder-fLastMenuItem]);
      }
      else
      {
	    SetHButtonText(a,y1+textRiven,NON_ACTIVE,ppString[menuHolder-fLastMenuItem]);
      }
      fEnter=0;
      fLastMenuItem=0;
      temp=0;
      MenuIndex=menuHolder;
	  menuHolder=0;
      a=leftVidstup;
    }
    symbol=getch();
    switch(symbol)
    {
      case 77:++MenuIndex;  //RIGHT:  100
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=leftVidstup;
	  for(temp=0;temp<(c-1);temp++)
	  {
	    a+=buttonLenghtArray[temp];
	  }
	  x1=1;
	  SetHButtonText(a,y1+textRiven,NON_ACTIVE,ppString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    a=leftVidstup;
	    SetHButtonText(a,y1+textRiven,ACTIVE,ppString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      x1=1;
	      temp=0;
	      a=leftVidstup;
	      for(temp=0;temp<i;temp++)
	      {
			a+=buttonLenghtArray[temp];
	      }
	      SetHButtonText(a-buttonLenghtArray[temp-1],y1+textRiven,NON_ACTIVE,ppString[i-1]);
	      SetHButtonText(a,y1+textRiven,ACTIVE,ppString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 75:--MenuIndex;//LEFT: 97
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=leftVidstup;
	  x1=1;
	  SetHButtonText(a,y1+textRiven,NON_ACTIVE,ppString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 //**************************
	  if(MenuIndex==c)
	  {
	    a=leftVidstup;
	    for(temp=0;temp<(c-1);temp++)
	    {
	      a+=buttonLenghtArray[temp];
	    }
	    SetHButtonText(a,y1+textRiven,ACTIVE,ppString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      x1=1;
	      temp=0;
	      a=leftVidstup;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=buttonLenghtArray[temp];
	      }
	      SetHButtonText(a,y1+textRiven,NON_ACTIVE,ppString[i+1]);
	      SetHButtonText(a-buttonLenghtArray[temp-1],y1+textRiven,ACTIVE,ppString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27: break;
      case 13:

	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	menuHolder=MenuIndex;
	tmp=leftVidstup;
	for(int z=0;z<MenuIndex-1;z++)
	  tmp+=buttonLenghtArray[z];
	  switch(MenuIndex)
	  {
	    case 6:
	     // closegraph();
	      exit(0);
	      fLastMenuItem=1;
	      break;
	    case 1:
	       (*pMainMenu[MenuIndex-1])(tmp,WinHeight,"About Model","About Author","Help",NULL);
		break;
	    case 2:        // init
	       (*pMainMenu[MenuIndex-1])(tmp,WinHeight,"Model Params","Experiment Params","General Params",NULL);
	       break;
	    case 3:
	       (*pMainMenu[MenuIndex-1])(tmp,WinHeight," dy/dx = x; "," dy/dx = cos(x); ",NULL);
	       break;
	    case 4:
	       (*pMainMenu[MenuIndex-1])(tmp,WinHeight,"Runge-Kutt","Improved Eyler","Hemming",NULL);
		   break;
	    case 5:
	       (*pMainMenu[MenuIndex-1])(tmp,WinHeight,"Runge-Kutt","Improved Eyler","Hemming",NULL);
	       break;
	    default: break;
	  }//end of switch(MenuIndex)
	  fEnter=1;
	  i=0;
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
}//END
//************************
void Show()
{
  x2=xmax;
  x1=1;
  Window(x1,y1,x2,y1+WinHeight,textColor,bkColor);
  for(int i=0;i<count;i++)
  {
   SetHButtonText(x1+1,y1+textRiven,NON_ACTIVE,ppString[i]);
   x1+=buttonLenghtArray[i]-1;
  }
  x1=1;
  Engine();
}

//***********************************************************
void AboutProgram(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  //Height+=5;
  Window(leftX,leftY+topVidstup,leftX+Width*10+leftVidstup,(leftY+(Height)*acrossSubButtons)+10,textColor,bkColor);
  leftY+=topVidstup+5;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    SetVButtonText(leftX+1,leftY+topVidstup,Width,NON_ACTIVE,ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  SetVButtonText(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    SetVButtonText(leftX+1,holder+topVidstup,Width,ACTIVE,ppSubString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[i-1]);
	      SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[i+1]);
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	      winLen=280,winHeight=150;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-50;

	  switch(MenuIndex)
	  {
	    case 1:
	      winLen=500,winHeight=300;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-20;

	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Individual Task");
	      while(getch()!=27)
	      {
		;
	      }
	      RefreshDesctop(winLX-1,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
	      goto EXIT;
	    case 2:
	      winLen=300,winHeight=150;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-20;

		RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	       WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"About Author");
	      while(getch()!=27)
	      {
		;
	      }
	      RefreshDesctop(winLX-1,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);

	     goto EXIT;
	    case 3:
	      winLen=250,winHeight=300;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-20;

	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	    WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Help");
	      while(getch()!=27)
	      {
		;
	      }
	      RefreshDesctop(winLX-1,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);

	    goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********************************************************
void Parameters(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  //Height+=5;
  Window(leftX,leftY+topVidstup,leftX+Width*10+leftVidstup,(leftY+(Height)*acrossSubButtons)+10,textColor,bkColor);
  leftY+=topVidstup+5;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    SetVButtonText(leftX+1,leftY+topVidstup,Width,NON_ACTIVE,ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  SetVButtonText(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    SetVButtonText(leftX+1,holder+topVidstup,Width,ACTIVE,ppSubString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[i-1]);
	      SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[i+1]);
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
       //	unsigned int tempWinLen=0;
	  switch(MenuIndex)
	  {
	    case 1: //Model Parameters
	      winLen=280,winHeight=150;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-50;
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Model Parameters");
	      setcolor(textColor);
	      settextstyle(1,0,2);
	      outtextxy(winLX+40,winLY+30,"Set alfa-parameter");
	      SetDefault();
	      outtextxy(winLX+20,winLY+80,"Alfa: ");
	      setfillstyle(1,4);
	      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
	      setcolor(5);
	      rectangle(winLX+15,winLY+100,winLX+15+250,winLY+70);
	      setcolor(textColor);
	      outtextxy(winLX+150,winLY+80,"Alfa = [0;1]");
	      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
	      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
	      setcolor(textColor);
	      rectangle(winLX+winLen-265,winLY+winHeight-30,winLX+winLen-55,winLY+winHeight-10);
	      int ch=0;
	      char *format=(char*)calloc(10,sizeof(char));
	      sprintf(format,"%.2lf",alfa);
	      outtextxy(winLX+20+50,winLY+80,format);
	      int f=0;
	      double alfa_temp=alfa;
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press TAB to switch between items");
	      do
	      {
		ch=getch();
		switch(ch)
		{
		  case 9:
		    switch(f)
		    {
		    case 0:
		    {
		      f=1;
		      setfillstyle(1,4);
		      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
		      setcolor(0);
		      rectangle(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
		      setcolor(15);
		      rectangle(winLX+20+40+1,winLY+75+1,winLX+20+90-1,winLY+95-1);

		      sprintf(format,"%.2lf",alfa_temp);
		      outtextxy(winLX+20+50,winLY+80,format);
		      ch=getch();

		      if(ch==13)
		      {
		      setfillstyle(1,4);
		      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);

		      moveto(winLX+20+40,winLY+80);
		      alfa_temp=GraphScanf(5,15,4,1);
		      }
		    }break;
		    case 1:

		    {
		      f=2;
		      setfillstyle(1,4);
		      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
		      sprintf(format,"%.2lf",alfa_temp);
		      outtextxy(winLX+20+50,winLY+80,format);
		      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(15);
		      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
		      setcolor(textColor);
		      rectangle(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(15);
		      rectangle(winLX+winLen-11,winLY+winHeight-11,winLX+winLen-49,winLY+winHeight-29);
		    }break;
		    case 2:
		    {
		      f=1;
		      setfillstyle(1,4);
		      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(textColor);
		      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
		      //***
		      setfillstyle(1,4);
		      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
		      setcolor(0);
		      rectangle(winLX+20+40,winLY+75,winLX+20+90,winLY+95);
		      setcolor(15);
		      rectangle(winLX+20+40+1,winLY+75+1,winLX+20+90-1,winLY+95-1);
		      sprintf(format,"%.2lf",alfa_temp);
		      outtextxy(winLX+20+50,winLY+80,format);

		      ch=getch();
		      if(ch==13)
		      {
		      setfillstyle(1,4);
		      bar(winLX+20+40,winLY+75,winLX+20+90,winLY+95);

		      moveto(winLX+20+40,winLY+80);
		      alfa_temp=GraphScanf(5,15,4,1);
		      }
		    }break;
		    }
		    break;
		  case 27:
		    RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    free(format);
		    goto EXIT;
		  case 13:
		      if(f==2)
		      {
			f=0;
			if((alfa_temp>=0.0) && (alfa_temp<=1))
			  alfa=alfa_temp;
		      }
		      //Progress BAR
		      for(int i=winLX+winLen-263;i<(winLX+winLen-57);i+=5)
		      {
			bar(i,winLY+winHeight-28,i+3,winLY+winHeight-12);
			delay(50);
		      }
		      free(format);
		      RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    goto EXIT;
		  default:
		    break;
		}
	      }while(1);
	     // goto EXIT; Unreachable code!!
	    case 2: //Experiment Parameters
	      f=0;
	      alfa_temp=alfa;
	      double t0_temp=t0,tn_temp=tn,x0_temp=x0,y0_temp=y0,h_temp=h;
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      winLen=300,winHeight=280;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Experiment Parameters");
	      setcolor(textColor);
	      settextstyle(1,0,2);
	      outtextxy(winLX+10,winLY+30,"Set Experiment Parameters");
	      SetDefault();
	      //*****Edit Boxes
	      outtextxy(winLX+40,winLY+80,"t0: ");
	      setfillstyle(1,4);
	      bar(winLX+40+30,winLY+75,winLX+40+90,winLY+95);
	      //****
	      outtextxy(winLX+170,winLY+80,"tn: ");
	      setfillstyle(1,4);
	      bar(winLX+40+160,winLY+75,winLX+20+240,winLY+95);
	      setcolor(5);
	      rectangle(winLX+15,winLY+100,winLX+winLen-15,winLY+70);

	      //****Edit Boxes (x0,Y0)
	      setcolor(textColor);
	      outtextxy(winLX+40,winLY+140,"x0: ");
	      setfillstyle(1,4);
	      bar(winLX+40+30,winLY+135,winLX+40+90,winLY+155);
	      //****
	      outtextxy(winLX+170,winLY+140,"y0: ");
	      setfillstyle(1,4);
	      bar(winLX+40+160,winLY+135,winLX+20+240,winLY+155);
	      setcolor(5);
	      rectangle(winLX+15,winLY+160,winLX+winLen-15,winLY+130);
	      //******
	      setcolor(textColor);
	      outtextxy(winLX+40,winLY+200,"h: ");
	      setfillstyle(1,4);
	      bar(winLX+40+30,winLY+195,winLX+40+90,winLY+215);
	      setcolor(5);
	      rectangle(winLX+15,winLY+220,winLX+winLen-15,winLY+190);
			
	      //**Progress bar
	      setcolor(textColor);
	      rectangle(winLX+winLen-285,winLY+winHeight-30,winLX+winLen-55,winLY+winHeight-10);
	      setcolor(textColor);
	      //**Button "OK"
	      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
	      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
	      ch=0;
	      format=(char*)calloc(10,sizeof(char));
	      memset(format,'\0',10);

		  sprintf(format,"%.1lf",t0_temp);
		  outtextxy(winLX+50+30,winLY+80,format);
		    memset(format,'\0',10);

		  sprintf(format,"%.1lf",tn_temp);
		  outtextxy(winLX+50+160,winLY+80,format);
		  memset(format,'\0',10);

		  sprintf(format,"%.1lf",x0_temp);
		  outtextxy(winLX+50+30,winLY+140,format);
		  memset(format,'\0',10);

		  sprintf(format,"%.1lf",y0_temp);
		  outtextxy(winLX+50+160,winLY+140,format);
		  memset(format,'\0',10);

		  sprintf(format,"%.1lf",h_temp);
		  outtextxy(winLX+50+30,winLY+200,format);
		  memset(format,'\0',10);



	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press TAB to switch between items");
	      do
	      {
		ch=getch();
		switch(ch)
		{
		  case 9:
		    switch(f)
		    {
		    case 0:
		    {
		      f=1;
		      setfillstyle(1,4);
		      bar(winLX+40+30,winLY+75,winLX+40+90,winLY+95);
		      setcolor(0);
		      rectangle(winLX+40+30,winLY+75,winLX+40+90,winLY+95);
		      setcolor(15);
		      rectangle(winLX+40+30+1,winLY+75+1,winLX+40+90-1,winLY+95-1);
		      sprintf(format,"%.1lf",t0_temp);
		      outtextxy(winLX+40+40,winLY+80,format);
		      ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+30,winLY+75,winLX+40+90,winLY+95);

			moveto(winLX+40+40,winLY+80);
			t0_temp=GraphScanf(5,15,4,1);
		      }
		    }break;
		    case 1:
			  {
			    f=2;
			    setfillstyle(1,4);
			    bar(winLX+40+30,winLY+75,winLX+40+90,winLY+95);
			    setcolor(textColor);
			    sprintf(format,"%.1lf",t0_temp);
			    outtextxy(winLX+40+40,winLY+80,format);
			    //*****
		      setfillstyle(1,4);
		      bar(winLX+40+160,winLY+75,winLX+20+240,winLY+95);
		      setcolor(0);
		      rectangle(winLX+40+160,winLY+75,winLX+20+240,winLY+95);
		      setcolor(15);
		      rectangle(winLX+40+160+1,winLY+75+1,winLX+20+240-1,winLY+95-1);
		      sprintf(format,"%.1lf",tn_temp);
		      outtextxy(winLX+50+160,winLY+80,format);
		      ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+160,winLY+75,winLX+20+240,winLY+95);

			moveto(winLX+50+160,winLY+80);
			tn_temp=GraphScanf(5,15,4,1);
		      }
			  }break;
		    case 2:
			  {
			    f=3;
			    setfillstyle(1,4);
			    bar(winLX+40+160,winLY+75,winLX+20+240,winLY+95);
			    setcolor(textColor);
			    sprintf(format,"%.1lf",tn_temp);
			    outtextxy(winLX+50+160,winLY+80,format);
			    //*****
		      setfillstyle(1,4);
		      bar(winLX+40+30,winLY+135,winLX+40+90,winLY+155);
		      setcolor(0);
		      rectangle(winLX+40+30,winLY+135,winLX+40+90,winLY+155);
		      setcolor(15);
		      rectangle(winLX+40+30+1,winLY+135+1,winLX+40+90-1,winLY+155-1);
		      sprintf(format,"%.1lf",x0_temp);
		      outtextxy(winLX+50+30,winLY+140,format);
		      ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+30,winLY+135,winLX+40+90,winLY+155);

			moveto(winLX+50+30,winLY+140);
			x0_temp=GraphScanf(5,15,4,1);
		      }

			  }break;
		    case 3:
			  {
			    f=4;
			    setfillstyle(1,4);
			    bar(winLX+40+30,winLY+135,winLX+40+90,winLY+155);
			    setcolor(textColor);
			    sprintf(format,"%.1lf",x0_temp);
			    outtextxy(winLX+50+30,winLY+140,format);
			    //*****
			    setfillstyle(1,4);
		      bar(winLX+40+160,winLY+135,winLX+20+240,winLY+155);
		      setcolor(0);
		      rectangle(winLX+40+160,winLY+135,winLX+20+240,winLY+155);
		      setcolor(15);
		      rectangle(winLX+40+160+1,winLY+135+1,winLX+20+240-1,winLY+155-1);
		      sprintf(format,"%.1lf",y0_temp);
		      outtextxy(winLX+50+160,winLY+140,format);
		      ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+160,winLY+135,winLX+20+240,winLY+155);

			moveto(winLX+50+160,winLY+140);
			y0_temp=GraphScanf(5,15,4,1);
		      }
			  }break;
		    case 4:
			  {
			    f=5;
			    setfillstyle(1,4);
			    bar(winLX+40+160,winLY+135,winLX+20+240,winLY+155);
			    setcolor(textColor);
			    sprintf(format,"%.1lf",y0_temp);
			    outtextxy(winLX+50+160,winLY+140,format);
			     setfillstyle(1,4);
			     //*****
		      bar(winLX+40+30,winLY+195,winLX+40+90,winLY+215);
		      setcolor(0);
		      rectangle(winLX+40+30,winLY+195,winLX+40+90,winLY+215);
		      setcolor(15);
		      rectangle(winLX+40+30+1,winLY+195+1,winLX+40+90-1,winLY+215-1);
		      sprintf(format,"%.1lf",h_temp);
		      outtextxy(winLX+50+30,winLY+200,format);
		      ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+30,winLY+195,winLX+40+90,winLY+215);

			moveto(winLX+50+30,winLY+200);
			h_temp=GraphScanf(5,15,4,1);
		      }
			  }break;
		    case 5:
			  {
			    f=6;
			    setfillstyle(1,4);
			    bar(winLX+40+30,winLY+195,winLX+40+90,winLY+215);
			    setcolor(textColor);
			    sprintf(format,"%.1lf",h_temp);
			    outtextxy(winLX+50+30,winLY+200,format);
				//****
			     setfillstyle(1,4);
		      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(0);
		      rectangle(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(15);
		      rectangle(winLX+winLen-10-1,winLY+winHeight-10-1,winLX+winLen-50+1,winLY+winHeight-30+1);
		      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
		       }break;
		     case 6:
		       f=0;
		       setfillstyle(1,4);
			    bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
			    setcolor(textColor);
			    outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
		       break;
		    }
			break;
		  case 27:
		    RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    free(format);
		    goto EXIT;
		  case 13:
		      if(f==6)
		      {
				f=0;
				t0=t0_temp,tn=tn_temp,x0=x0_temp,y0=y0_temp,h=h_temp;

			  }
		      //Progress BAR
		      for(int i=winLX+winLen-283;i<(winLX+winLen-57);i+=5)
		      {
				bar(i,winLY+winHeight-28,i+3,winLY+winHeight-12);
				delay(50);
		      }
		      free(format);
		      RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    goto EXIT;
		  default:
		    break;
		}
	      }while(1);  /////////////
	      //free(format);
		 //  goto EXIT; // Unrechable code  !!!
	    case 3:
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //WindowXP(50,70,590,400,textColor,bkColor,1,"General Parameters");
	      GeneralParameters();
	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********************************************************
void Testing(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  //Height+=5;
  Window(leftX,leftY+topVidstup,leftX+Width*10+leftVidstup,(leftY+(Height)*acrossSubButtons)+10,textColor,bkColor);
  leftY+=topVidstup+5;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    SetVButtonText(leftX+1,leftY+topVidstup,Width,NON_ACTIVE,ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  SetVButtonText(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    SetVButtonText(leftX+1,holder+topVidstup,Width,ACTIVE,ppSubString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[i-1]);
	      SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[i+1]);
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
      //	unsigned int tempWinLen=0;
	  switch(MenuIndex)
	  {
	    case 1:
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      SelectMethod();
	      goto EXIT;
	    case 2:
	       RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	       SelectMethod();
	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********************************************************
void Researching(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  //Height+=5;
  Window(leftX,leftY+topVidstup,leftX+Width*10+leftVidstup,(leftY+(Height)*acrossSubButtons)+10,textColor,bkColor);
  leftY+=topVidstup+5;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    SetVButtonText(leftX+1,leftY+topVidstup,Width,NON_ACTIVE,ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  SetVButtonText(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    SetVButtonText(leftX+1,holder+topVidstup,Width,ACTIVE,ppSubString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[i-1]);
	      SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[i+1]);
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	  switch(MenuIndex)
	  {
	    case 1:
	     // RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //SelectMethod();
	      //goto EXIT;
	    case 2:
	       //RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //SelectMethod();
	     //goto EXIT;
	    case 3:
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      smResult=SelectMethod();
	      SaveToFile(smResult);
	      Table(smResult);
	    goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
 free(ppSubString);
 free(ar);
 free(pString);
}
//***********************************************************
void GraphResult(int leftX,int leftY,char *string,...)
{
  int counter=0,Height=0,Width=0,i=0;
  XY xy1;
  memset(&xy1,0,sizeof(XY));
  STYLE style;
  memset(&style,0,sizeof(STYLE));
  ECO eco1;
  memset(&eco1,0,sizeof(ECO));
  int Size=1;
  xFile=OpenDB(xArr,READONLY);
  Size=GetDSize(xFile);
  if(Size==0) Size=1;

  CloseDB(xFile);
  CreateDB(gArr);
  gFile=OpenDB(gArr,READnWRITE);

  i=0;
  va_list par;
  char *pString=string;
  va_start(par,string);
  while(pString!=NULL)
  {
    counter=0;
    while(*pString!='\0')
    {
      counter++;
      pString++;
    }//end of 2 while
    Height++;
    if(counter>Width)
    {
      Width=counter;
    }
    pString=va_arg(par,char*);
  }//end of 1 while
  va_end(par);
  int *ar;
  ar=(int*)calloc(Height,sizeof(int));
  if(ar==NULL)
  {
    printf("Error! No free memory!");
    exit(1);
  }
  for(i=0;i<Height;i++)
  {
    ar[i]=i+1;
  }
  char **ppSubString=NULL;
  ppSubString=(char**)calloc(Height,sizeof(char*));
  pString=string;
  va_start(par,string);
  i=0;
  while(pString!=NULL)
  {
     ppSubString[i]=pString;
     i++;
     pString=va_arg(par,char*);
   }
  va_end(par);
  //Height+=5;
  Window(leftX,leftY+topVidstup,leftX+Width*10+leftVidstup,(leftY+(Height)*acrossSubButtons)+10,textColor,bkColor);
  leftY+=topVidstup+5;
  int holder=leftY;
  for(i=0;i<Height;i++)
  {
    SetVButtonText(leftX+1,leftY+topVidstup,Width,NON_ACTIVE,ppSubString[i]);
    leftY+=acrossSubButtons;
  }
//****SubMenu Engine***************
  int c=Height;
  unsigned char temp=0;
  unsigned int a=0;
  MenuIndex=0;
  i=0;
  while(1){
    symbol=getch();
    switch(symbol)
    {
      case 80:++MenuIndex;  //DOWN: 115
	if(MenuIndex>c)
	{
	  MenuIndex=1;
	  a=holder;
	  SetVButtonText(leftX+1,a+(Height*acrossSubButtons)-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[c-1]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==1)
	  {
	    SetVButtonText(leftX+1,holder+topVidstup,Width,ACTIVE,ppSubString[0]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[0]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<i;temp++)
	      {
		    a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,NON_ACTIVE,ppSubString[i-1]);
	      SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 100:
	break;
      case 72:--MenuIndex;//UP: 119
	if(MenuIndex<=0)
	{
	  MenuIndex=c;
	  a=holder;
	  SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[0]);
	}
	while((MenuIndex<=c)&&(MenuIndex>0))
	{
	  if((i<0)||(i>=c))
	    i=0;
	 ///**************************
	  if(MenuIndex==c)
	  {
	    a=holder+(Height*acrossSubButtons)-acrossSubButtons;
	    SetVButtonText(leftX+1,a+topVidstup,Width,ACTIVE,ppSubString[c-1]);
	    StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[c-1]);
	    break;
	  }
	  else
	  {
	    if(MenuIndex==ar[i])
	    {
	      a=holder;
	      for(temp=0;temp<(i+1);temp++)
	      {
			a+=acrossSubButtons;
	      }
	      SetVButtonText(leftX+1,a+topVidstup,Width,NON_ACTIVE,ppSubString[i+1]);
	      SetVButtonText(leftX+1,a-acrossSubButtons+topVidstup,Width,ACTIVE,ppSubString[i]);
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,ppSubString[i]);
	      break;
	    }
	  }
	i++;
	}//end of case 97
	break;
      case 27:
	RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press Esc for EXIT, and use array buttons to choose your task.");
	goto EXIT;
      case 13:
	if((MenuIndex>0)&&(MenuIndex<=c))
	{
	      winLen=600,winHeight=350;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-20;
	      style.x1=winLX;
	      style.y1=winLY;
	      style.lenght=winLen;
	      style.height=winHeight;
	      style.fon=15;
	      style.axeColor=4;
	      int otvet=0;
	      double bf=0.0;
	  switch(MenuIndex)
	  {
	    case 1: //R-Kutt
	      if( smResult!=3 && smResult!=4 && smResult!=8 )
	      {
		RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
		goto EXIT;
	      }
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //**begin graph modul**//
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Runge-Kutt. Evolution. Graphics model");
	      xFile=OpenDB(xArr,READONLY);
	      rkFile=OpenDB(rkArr,READONLY);
	      i=0;
	      bf=0.0;
	      while(i<Size)
	      {
		memset(&eco1,0,sizeof(ECO));
		memset(&xy1,0,sizeof(XY));
		bf=0.0;
		fread(&eco1,sizeof(ECO),1,rkFile);
		fread(&bf,sizeof(double),1,xFile);
		xy1.x[0]=bf;
		xy1.x[1]=eco1.y0;
		xy1.x[2]=eco1.y1;
		fwrite(&xy1,sizeof(XY),1,gFile);
		fflush(gFile);
		i++;
	       }
	      CloseDB(xFile);
	      CloseDB(rkFile);
	      CloseDB(gFile);
	      gFile=OpenDB(gArr,READONLY);
	      ShowGraph(style,K,Size,gFile);
	      SetDefault();
	      otvet=0;
	      while(otvet!=27)
	      {
		otvet=getch();
		if(otvet==27)
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
	      }
	      //***end graph modul***//
	      goto EXIT;
	    case 2://Eyler
	      if( smResult!=1 && smResult!=4 && smResult!=6 )
	      {
		RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
		goto EXIT;
	      }
	       RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //**begin graph modul**//
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Runge-Kutt. Evolution. Graphics model");
	      xFile=OpenDB(xArr,READONLY);
	      erFile=OpenDB(erArr,READONLY);
	      i=0;
	      bf=0.0;
	      while(i<Size)
	      {
		memset(&eco1,0,sizeof(ECO));
		memset(&xy1,0,sizeof(XY));
		bf=0.0;
		fread(&eco1,sizeof(ECO),1,erFile);
		fread(&bf,sizeof(double),1,xFile);
		xy1.x[0]=bf;
		xy1.x[1]=eco1.y0;
		xy1.x[2]=eco1.y1;
		fwrite(&xy1,sizeof(XY),1,gFile);
		fflush(gFile);
		i++;
	       }
	      CloseDB(xFile);
	      CloseDB(erFile);
	      CloseDB(gFile);
	      gFile=OpenDB(gArr,READONLY);
	      ShowGraph(style,K,Size,gFile);
	      SetDefault();
	      otvet=0;
	      while(otvet!=27)
	      {
		otvet=getch();
		if(otvet==27)
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
	      }

	      //***end graph modul***//

	      goto EXIT;
	    case 3: //Hemming
	      if( smResult!=5 && smResult!=6 && smResult!=8 )
	      {
		RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
		goto EXIT;
	      }
	      RefreshDesctop(leftX,holder-(topVidstup+5),leftX+Width*10+leftVidstup,holder+(Height*acrossSubButtons)+10,desctopColor);
	      //**begin graph modul**//
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Runge-Kutt. Evolution. Graphics model");
	      xFile=OpenDB(xArr,READONLY);
	      hemFile=OpenDB(hemArr,READONLY);
	      i=0;
	      bf=0.0;
	      while(i<Size)
	      {
		memset(&eco1,0,sizeof(ECO));
		memset(&xy1,0,sizeof(XY));
		bf=0.0;
		fread(&eco1,sizeof(ECO),1,hemFile);
		fread(&bf,sizeof(double),1,xFile);
		xy1.x[0]=bf;
		xy1.x[1]=eco1.y0;
		xy1.x[2]=eco1.y1;
		fwrite(&xy1,sizeof(XY),1,gFile);
		fflush(gFile);
		i++;
	       }
	      CloseDB(xFile);
	      CloseDB(hemFile);
	      CloseDB(gFile);
	      gFile=OpenDB(gArr,READONLY);
	      ShowGraph(style,K,Size,gFile);
	      SetDefault();
	      otvet=0;
	      while(otvet!=27)
	      {
		otvet=getch();
		if(otvet==27)
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
	      }

	      //***end graph modul***//

	      goto EXIT;
	    default: break;
	  }
	  break; //!!????
	}//end of case 13:
	break;
    }//End of switch(symbol)
  }//End of while(1)
EXIT: //free(ar); //free memory
//*****************
  CloseDB(gFile);
 free(ppSubString);
 free(ar);
 free(pString);
}