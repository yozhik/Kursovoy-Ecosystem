//************Functions*****************
double GraphScanf(int len,int txtColor, int fon, int bkStyle)
{
  char dozvoleni[]={'0','1','2','3','4','5','6','7','8','9','0','.','\0'},*s=NULL;
  s=(char*)calloc(len+1,sizeof(char));
  memset(s,'\0',len+1);
  int choice=0,c=0,curX=0,curY=0;
  curX=getx();
  curY=gety();
  setfillstyle(bkStyle,fon);
  setcolor(txtColor);
  do
  {
    choice=getch();
    if((strchr(dozvoleni,choice)) && (c<len))
    {
      *s=choice; c++; curX+=8;
      outtextxy(curX,curY,s);
      s++;
    }
    if((choice==8) && (c>0))
    {
      s--; *s='\0'; c--;
      bar(curX+6,curY,curX,curY+6);
      curX-=8;
    }
  }while(choice!=13);
  s-=c;
  double result=0.0;
  result=atof(s);
  free(s);
  return result;
}
void GeneralParameters(void)
{
	      int f=0,ch=0;

	      double t0_temp=t0,tn_temp=tn,x0_temp=x0,y0_temp=y0,h_temp=h,alfa_temp=alfa;
		  char *format=(char*)calloc(10,sizeof(char));
	      winLen=300,winHeight=280;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"General Parameters");
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
	      //****
	      setcolor(textColor);
	      outtextxy(winLX+170,winLY+200,"AL: ");
	      setfillstyle(1,4);
	      bar(winLX+40+160,winLY+195,winLX+20+240,winLY+215);
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

		  sprintf(format,"%.2lf",alfa_temp);
		  outtextxy(winLX+50+160,winLY+200,format);
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
		      bar(winLX+40+160,winLY+195,winLX+20+240,winLY+215);
		      setcolor(0);
		      rectangle(winLX+40+160,winLY+195,winLX+20+240,winLY+215);
		      setcolor(15);
		      rectangle(winLX+40+160+1,winLY+195+1,winLX+20+240-1,winLY+215-1);
		      sprintf(format,"%.2lf",alfa_temp);
		      outtextxy(winLX+50+160,winLY+200,format);
			ch=getch();

		      if(ch==13)
		      {
			setfillstyle(1,4);
			bar(winLX+40+160,winLY+195,winLX+20+240,winLY+215);

			moveto(winLX+50+160,winLY+200);
			alfa_temp=GraphScanf(5,15,4,1);
		      }

		       }break;
		    case 6:
			  {
			    f=7;
			    setfillstyle(1,4);
			    bar(winLX+40+160,winLY+195,winLX+20+240,winLY+215);
			    setcolor(textColor);
			    sprintf(format,"%.2lf",alfa_temp);
			    outtextxy(winLX+50+160,winLY+200,format);
				//****
			     setfillstyle(1,4);
		      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(0);
		      rectangle(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(15);
		      rectangle(winLX+winLen-10-1,winLY+winHeight-10-1,winLX+winLen-50+1,winLY+winHeight-30+1);
		      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
		       }break;

		     case 7:
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
		    goto EXIT;
		  case 13:
		      if(f==7)
		      {
				f=0;
				t0=t0_temp,tn=tn_temp,x0=x0_temp,y0=y0_temp,h=h_temp;
				if((alfa_temp>=0.0) && (alfa_temp<=1))
				  alfa=alfa_temp;
		      }
		      //Progress BAR
		      for(int i=winLX+winLen-283;i<(winLX+winLen-57);i+=5)
		      {
				bar(i,winLY+winHeight-28,i+3,winLY+winHeight-12);
				delay(50);
		      }
		      RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    goto EXIT;
		  default:
		    break;
		}
	      }while(1);  /////////////
EXIT:      free(format);
}
int SelectMethod(void)
{
     int result=0;
	      winLen=180,winHeight=180;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2-50;
	      WindowsVista(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Select Method");
	      SetDefault();
	      setfillstyle(1,4);
	      setcolor(textColor);
	      bar(winLX+15,winLY+40,winLX+30,winLY+55);
	      outtextxy(winLX+40,winLY+45,"Improved Eyler");

	      bar(winLX+15,winLY+70,winLX+30,winLY+85);
	      outtextxy(winLX+40,winLY+75,"Runge-Kutta");

	      bar(winLX+15,winLY+100,winLX+30,winLY+115);
	      outtextxy(winLX+40,winLY+105,"Hemming");

	      //**Progress bar
	      setcolor(textColor);
	      rectangle(winLX+winLen-165,winLY+winHeight-30,winLX+winLen-55,winLY+winHeight-10);
	      setcolor(textColor);
	      //**Button "OK"
	      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
	      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");

	      int ch=0,fg=0, eylerFlag=0,rungeFlag=0,hemmingFlag=0;
	      do
	      {
		ch=getch();
		switch(ch)
		{
		  case 9:
		    switch(fg)
		    {
		      case 0://Eyler
			fg=1;

			setfillstyle(1,15);
			setcolor(textColor);
			bar(winLX+15+3,winLY+40+3,winLX+30-3,winLY+55-3);
			rectangle(winLX+15,winLY+40,winLX+30,winLY+55);
			ch=getch();
			if(ch==32)
			{
			  if (eylerFlag==0)
			    eylerFlag=1;
			  else
			    eylerFlag=0;
			}

			break;
		      case 1: //Runge
			fg=2;
			if(!eylerFlag)
			{
			  setfillstyle(1,4);
			  setcolor(textColor);
			  bar(winLX+15+3,winLY+40+3,winLX+30-3,winLY+55-3);
			}
			setcolor(4);
			rectangle(winLX+15,winLY+40,winLX+30,winLY+55);
			setfillstyle(1,15);
			setcolor(textColor);
			bar(winLX+15+3,winLY+70+3,winLX+30-3,winLY+85-3);
			rectangle(winLX+15,winLY+70,winLX+30,winLY+85);
			ch=getch();
			if(ch==32)
			{
			  if (rungeFlag==0)
			    rungeFlag=3;
			  else
			    rungeFlag=0;
			}
			break;
		      case 2:        //Hemming
			fg=3;
			if(!rungeFlag)
			{
			  setfillstyle(1,4);
			  setcolor(textColor);
			  bar(winLX+15+3,winLY+70+3,winLX+30-3,winLY+85-3);
			}
			setcolor(4);
			rectangle(winLX+15,winLY+70,winLX+30,winLY+85);
			setfillstyle(1,15);
			setcolor(textColor);
			bar(winLX+15+3,winLY+100+3,winLX+30-3,winLY+115-3);
			rectangle(winLX+15,winLY+100,winLX+30,winLY+115);
			ch=getch();
			if(ch==32)
			{
			  if (hemmingFlag==0)
			    hemmingFlag=5;
			  else
			    hemmingFlag=0;
			}

			break;
		      case 3:  //button
			fg=4;
			if(!hemmingFlag)
			{
			  setfillstyle(1,4);
			  setcolor(textColor);
			  bar(winLX+15+3,winLY+100+3,winLX+30-3,winLY+115-3);
			}
			setcolor(4);
			rectangle(winLX+15,winLY+100,winLX+30,winLY+115);
		      setfillstyle(1,4);
		      bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(0);
		      rectangle(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
		      setcolor(15);
		      rectangle(winLX+winLen-10-1,winLY+winHeight-10-1,winLX+winLen-50+1,winLY+winHeight-30+1);
		      outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");

			break;
		      case 4:
			fg=0;

			bar(winLX+winLen-10,winLY+winHeight-10,winLX+winLen-50,winLY+winHeight-30);
			setcolor(textColor);
			outtextxy(winLX+winLen-36,winLY+winHeight-23,"OK");
			break;
		    }
		    break;
		  case 13:
		    if(fg==4)
		    {
		      result=rungeFlag+eylerFlag+hemmingFlag;
		    }
		      //Progress BAR
		      for(int i=winLX+winLen-163;i<(winLX+winLen-57);i+=5)
		      {
				bar(i,winLY+winHeight-28,i+3,winLY+winHeight-12);
				delay(50);
		      }
		      RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);

		    goto EXIT;
		  case 27:
		    RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		    goto EXIT;
		  default: break;
		}
	      }while(1);
EXIT:
  return result;
}
void SaveToFile(int shyfr)
{
  CreateDB(xArr);

  xFile=OpenDB(xArr,READnWRITE);
  unsigned int i=0, N=(tn-t0)/h+1;
  double x=0.0, *y=NULL, *f1=NULL, *y2=NULL,
  **RK_Y=NULL, **F=NULL;
  ECO eco1, eco2;
  memset(&eco1,0,sizeof(ECO));
  memset(&eco2,0,sizeof(ECO));

  y=(double*)calloc(K,sizeof(double));
  if(!y) exit(1);

  y2=(double*)calloc(K,sizeof(double));
  if(!y2) exit(1);

  f1=(double*)calloc(K,sizeof(double));
  if(!f1) exit(1);

  RK_Y=(double**)calloc(K,sizeof(double));
  if(!RK_Y) exit(1);
  for(i=0;i<K;i++)
  {
    RK_Y[i]=(double*)calloc(4,sizeof(double));
    if(!RK_Y[i]) exit(1);
  }

  F=(double**)calloc(K,sizeof(double));
  if(!F) exit(1);
  for(i=0;i<K;i++)
  {
    F[i]=(double*)calloc(4,sizeof(double));
    if(!F[i]) exit(1);
  }

  y[0]=x0;
  y[1]=y0;
  y2[0]=x0;
  y2[1]=y0;

  x=t0;
  switch(shyfr)
  {
      case 1: //Eyler
	CreateDB(erArr);
	erFile=OpenDB(erArr,READnWRITE);
	//***Eyler*******
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<N;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=y[0];
	  eco1.y1=y[1];
	  fwrite(&eco1,sizeof(ECO),1,erFile);
	  fflush(erFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  Improved_Eyler(K,x,y,h);
	  x=x+h;
	}
	//**end Eyler******
	CloseDB(erFile);
      break;
      case 3: //R-Kutt
	CreateDB(rkArr);
	rkFile=OpenDB(rkArr,READnWRITE);
	//**R-Kutt******
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<N;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=y[0];
	  eco1.y1=y[1];
	  fwrite(&eco1,sizeof(ECO),1,rkFile);
	  fflush(rkFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  R_Kutt(K,x,y,h);
	  x=x+h;
	}
	//***end R-Kutt*****
	CloseDB(rkFile);
      break;
      case 5: //Hemming
	CreateDB(hemArr);
	hemFile=OpenDB(hemArr,READnWRITE);
	/***For Hemming!!***/
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<4;i++)
	{
	  //**finding pohidni!!
	  RK_Y[0][i]=y[0];
	  RK_Y[1][i]=y[1];
	  R_Kutt(K,x,y,h);
	  System(x,y,f1);
	  F[0][i]=f1[0];
	  F[1][i]=f1[1];
	  x=x+h;
	}
	x=t0;
	for(i=0;i<4;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][i];
	  eco1.y1=RK_Y[1][i];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  x=x+h;
	}
	x-=h; //back step
	for(i=4;i<N;i++)
	{
	  Hemming(K,h,x,RK_Y,F);
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][3];
	  eco1.y1=RK_Y[1][3];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  x=x+h;
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	}
	//***end Hemming****///
	CloseDB(hemFile);
      break;
      case 4://R-Kutt && Eyler
	CreateDB(erArr);
	CreateDB(rkArr);
	erFile=OpenDB(erArr,READnWRITE);
	rkFile=OpenDB(rkArr,READnWRITE);
	y2[0]=x0;
	y2[1]=y0;
	//**R-Kutt && Eyler******
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<N;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  memset(&eco2,0,sizeof(ECO));
	  eco1.y0=y[0];
	  eco1.y1=y[1];
	  eco2.y0=y2[0];
	  eco2.y1=y2[1];
	  fwrite(&eco1,sizeof(ECO),1,rkFile);
	  fflush(rkFile);
	  fwrite(&eco2,sizeof(ECO),1,erFile);
	  fflush(erFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  R_Kutt(K,x,y,h);
	  Improved_Eyler(K,x,y2,h);
	  x=x+h;
	}
	//***end R-Kutt && Eyler*****
	CloseDB(erFile);
	CloseDB(rkFile);
      break;
      case 6://Eyler && Hemming
	CreateDB(hemArr);
	CreateDB(erArr);
	hemFile=OpenDB(hemArr,READnWRITE);
	erFile=OpenDB(erArr,READnWRITE);
	//***Eyler*******
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<N;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=y[0];
	  eco1.y1=y[1];
	  fwrite(&eco1,sizeof(ECO),1,erFile);
	  fflush(erFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  Improved_Eyler(K,x,y,h);
	  x=x+h;
	}
	//**end Eyler******
	CloseDB(erFile);
	/***For Hemming!!***/
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<4;i++)
	{
	  //**finding pohidni!!
	  RK_Y[0][i]=y[0];
	  RK_Y[1][i]=y[1];
	  R_Kutt(K,x,y,h);
	  System(x,y,f1);
	  F[0][i]=f1[0];
	  F[1][i]=f1[1];
	  x=x+h;
	}
	x=t0;
	for(i=0;i<4;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][i];
	  eco1.y1=RK_Y[1][i];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  x=x+h;
	}
	x-=h; //back step
	for(i=4;i<N;i++)
	{
	  Hemming(K,h,x,RK_Y,F);
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][3];
	  eco1.y1=RK_Y[1][3];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  x=x+h;
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	}
	//***end Hemming****///
	CloseDB(hemFile);
      break;
      case 8://R-Kutt && Hemming
	CreateDB(hemArr);
	CreateDB(rkArr);
	hemFile=OpenDB(hemArr,READnWRITE);
	rkFile=OpenDB(rkArr,READnWRITE);
	//**R-Kutt******
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<N;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=y[0];
	  eco1.y1=y[1];
	  fwrite(&eco1,sizeof(ECO),1,rkFile);
	  fflush(rkFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  R_Kutt(K,x,y,h);
	  x=x+h;
	}
	//***end R-Kutt*****
	CloseDB(rkFile);
	/***For Hemming!!***/
	x=t0;
	y[0]=x0;
	y[1]=y0;
	for(i=0;i<4;i++)
	{
	  //**finding pohidni!!
	  RK_Y[0][i]=y[0];
	  RK_Y[1][i]=y[1];
	  R_Kutt(K,x,y,h);
	  System(x,y,f1);
	  F[0][i]=f1[0];
	  F[1][i]=f1[1];
	  x=x+h;
	}
	x=t0;
	for(i=0;i<4;i++)
	{
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][i];
	  eco1.y1=RK_Y[1][i];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	  x=x+h;
	}
	x-=h; //back step
	for(i=4;i<N;i++) ///
	{
	  Hemming(K,h,x,RK_Y,F);
	  memset(&eco1,0,sizeof(ECO));
	  eco1.y0=RK_Y[0][3];
	  eco1.y1=RK_Y[1][3];
	  fwrite(&eco1,sizeof(ECO),1,hemFile);
	  fflush(hemFile);
	  x=x+h;
	  fwrite(&x,sizeof(double),1,xFile);
	  fflush(xFile);
	}
	//***end Hemming****///
	CloseDB(hemFile);
      break;
      case 9://All Methods
	break;
      default:
	break;
  }
  CloseDB(xFile);

  for(i=0;i<K;i++)
    free(RK_Y[i]);
  free(RK_Y);

  for(i=0;i<K;i++)
    free(F[i]);
  free(F);
  free(y);
  free(y2);
  free(f1);
}
void Table(int shyfr)
{
  int hCell=20, wCell=100,
      lOffset=10, vOffset=5,
      borderColor=14,i=0,j=0,
      otvet=0, dbSize=0, txtColor=15, upOffset=40;
  double *X=NULL;
  char *buf=NULL, *buf2=NULL;
  FILE *xFile=NULL, *erFile=NULL, *rkFile=NULL, *hemFile=NULL;
  ECO *ecoArray=NULL, *eco2Array=NULL;
  buf=(char*)calloc(20,sizeof(char));
  if(!buf) exit(1);
  buf2=(char*)calloc(10,sizeof(char));
  if(!buf2) exit(1);
  X=(double*)calloc(13,sizeof(double));
  if(!X) exit(1);
  ecoArray=(ECO*)calloc(13,sizeof(ECO));
  if(!ecoArray) exit (1);
  eco2Array=(ECO*)calloc(13,sizeof(ECO));
  if(!eco2Array) exit (1);

  xFile=OpenDB(xArr,READONLY);
  memset(buf,'\0',20);
  memset(buf2,'\0',10);
  switch(shyfr)
  {
      case 1: //Eyler
	      erFile=OpenDB(erArr,READONLY);
	      winLen=440,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<4;i++)
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Improved Eyler");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(erFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(erFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),erFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(erFile);
	      //************************
      break;
      //**************************
      case 3://R-Kutt
	      rkFile=OpenDB(rkArr,READONLY);
	      winLen=440,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<4;i++)
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Runge-Kutt");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(rkFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(rkFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),rkFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(rkFile);
	      //************************
      break;
      //**************************
      case 5: //Hemming
	      hemFile=OpenDB(hemArr,READONLY);
	      winLen=440,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<4;i++)
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Hemming");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(hemFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(hemFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),hemFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<4;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(hemFile);
	      //************************
      break;
      //**************************
      case 4: //Eyler && R-Kutt
	      erFile=OpenDB(erArr,READONLY);
	      rkFile=OpenDB(rkArr,READONLY);
	      winLen=620,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<6;i++)
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Improved Eyler");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+vOffset,"Runge-Kutt");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Rabbits");
	      outtextxy(winLX+20+5*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Foxes");

	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(erFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(eco2Array,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(erFile,j*13*sizeof(ECO),SEEK_SET);
		fseek(rkFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),erFile);
		fread(eco2Array,13,sizeof(ECO),rkFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y0);
		  outtextxy(winLX+20+4*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y1);
		  outtextxy(winLX+20+5*wCell,winLY+110+vOffset+i*hCell,buf);

		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(erFile);
	      CloseDB(rkFile);
	      //************************
      break;
      case 6: //Eyler && Hemming
	      erFile=OpenDB(erArr,READONLY);
	      hemFile=OpenDB(hemArr,READONLY);
	      winLen=620,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<6;i++)
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Improved Eyler");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+vOffset,"Hemming");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Rabbits");
	      outtextxy(winLX+20+5*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Foxes");

	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(erFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(eco2Array,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(erFile,j*13*sizeof(ECO),SEEK_SET);
		fseek(hemFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),erFile);
		fread(eco2Array,13,sizeof(ECO),hemFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y0);
		  outtextxy(winLX+20+4*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y1);
		  outtextxy(winLX+20+5*wCell,winLY+110+vOffset+i*hCell,buf);

		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(erFile);
	      CloseDB(hemFile);
	      //************************
      break;
      //**************************
      case 8: //Hemming && R-Kutt
	      rkFile=OpenDB(rkArr,READONLY);
	      hemFile=OpenDB(hemArr,READONLY);
	      winLen=620,winHeight=400;
	      winLX=(xmax-winLen)/2;
	      winLY=(ymax-winHeight)/2;
	      WindowXP(winLX,winLY,winLX+winLen,winLY+winHeight,textColor,bkColor,"Evolution Table");
	      StatusBar(1,ymax,xmax,ymax,textColor,bkColor,"Press cursor buttons to switch between tables. Esc to EXIT");
	      memset(buf,'\0',20);
	      setcolor(borderColor);
	      setfillstyle(1,0);
	      bar(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+20,winLY+110,winLX+winLen-20,winLY+winHeight-20);
	      rectangle(winLX+21,winLY+111,winLX+winLen-19,winLY+winHeight-19);
	      //*Header******
	      setcolor(borderColor);
	      bar(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      rectangle(winLX+20,winLY+upOffset,winLX+winLen-20,winLY+100);
	      setcolor(borderColor);
	      line(winLX+wCell,winLY+upOffset,winLX+wCell,winLY+80);
	      for(i=2;i<6;i++)
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+upOffset,winLX+i*wCell,winLY+100);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+80,winLX+i*wCell+lOffset,winLY+100);
		  line(winLX+20,winLY+80,winLX+winLen-20,winLY+80);
		}
	      }
	      setcolor(15);
	      outtextxy(winLX+20+lOffset,winLY+upOffset+vOffset,"#");
	      outtextxy(winLX+20+wCell+lOffset,winLY+upOffset+vOffset,"t");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+vOffset,"Runge-Kutt");
	      outtextxy(winLX+20+2*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Rabbits");
	      outtextxy(winLX+20+3*wCell+lOffset,winLY+upOffset+2*vOffset+hCell+15,"Foxes");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+vOffset,"Hemming");
	      outtextxy(winLX+20+4*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Rabbits");
	      outtextxy(winLX+20+5*wCell+lOffset,winLY+upOffset+3*vOffset+hCell+10,"Foxes");

	      //*************
	      //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //*****Full TAble**//////
	      setcolor(txtColor);
	      j=0,i=0;
	      otvet=0;
	      dbSize=GetSize(rkFile);
	      memset(buf2,'\0',10);
	      sprintf(buf2,"%d",dbSize/13+1);
	      while(1)
	      {
		memset(X,0,13*sizeof(double));
		memset(ecoArray,0,13*sizeof(ECO));
		memset(eco2Array,0,13*sizeof(ECO));
		memset(buf,'\0',20);
		if(j<0)
		  j=0;
		if(j>(dbSize/13))
		  j=dbSize/13;
		fseek(xFile,j*13*sizeof(double),SEEK_SET);
		fseek(rkFile,j*13*sizeof(ECO),SEEK_SET);
		fseek(hemFile,j*13*sizeof(ECO),SEEK_SET);
		fread(X,13,sizeof(double),xFile);
		fread(ecoArray,13,sizeof(ECO),rkFile);
		fread(eco2Array,13,sizeof(ECO),hemFile);
		setcolor(txtColor);
		bar(winLX+20+lOffset,winLY+85,winLX+100+lOffset,winLY+95);
		sprintf(buf,"%d",j+1);
		strcat(buf," of ");
		strcat(buf,buf2);
		outtextxy(winLX+20+lOffset,winLY+85,buf);
		memset(buf,'\0',20);
		for(i=0;i<13;i++)
		{
		  if(X[i]<=0.0)
		  {
		    if(j!=0)
		      break;
		  }
		  memset(buf,'\0',20);
		  sprintf(buf,"%d",i+j*13);
		  outtextxy(winLX+20+lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.3lf",X[i]);
		  outtextxy(winLX+20+wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y0);
		  outtextxy(winLX+20+2*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",ecoArray[i].y1);
		  outtextxy(winLX+20+3*wCell,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y0);
		  outtextxy(winLX+20+4*wCell-lOffset,winLY+110+vOffset+i*hCell,buf);
		  memset(buf,'\0',20);
		  sprintf(buf,"%.4lf",eco2Array[i].y1);
		  outtextxy(winLX+20+5*wCell,winLY+110+vOffset+i*hCell,buf);

		}
		otvet=getch();
		if(((otvet==77)||(otvet==72)) && (j<(dbSize/13)))
		{
		  j++;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(((otvet==75)||(otvet==80)) && (j>0))
		{
		  j--;
		  RefreshDesctop(winLX+22,winLY+112,winLX+winLen-22,winLY+winHeight-22,0);
	       //***table***//
	      for(i=1;i<14;i++)//horizontal
	      {
		setcolor(borderColor);
		line(winLX+20+2,winLY+110+i*hCell,winLX+winLen-20-2,winLY+110+i*hCell);
	      }
	      for(i=1;i<6;i++)//vertical
	      {
		setcolor(borderColor);
		if(i!=3 && i!=5)
		  line(winLX+i*wCell,winLY+110+2,winLX+i*wCell,winLY+winHeight-20-2);
		else
		{
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		  line(winLX+i*wCell+lOffset,winLY+110+2,winLX+i*wCell+lOffset,winLY+winHeight-20-2);
		}
	      }
	      //***********
		}
		if(otvet==27)
		{
		  RefreshDesctop(winLX,winLY-2,winLX+winLen,winLY+winHeight,desctopColor);
		  j=i=0;
		  break;
		}
	      }
	      CloseDB(rkFile);
	      CloseDB(hemFile);
	      //************************
      break;
      //**************************
      case 9: //All methods
      break;
      //**************************
      default:
      break;
  }
  CloseDB(xFile);
  free(X);
  free(ecoArray);
  free(eco2Array);
  free(buf);
  free(buf2);
}