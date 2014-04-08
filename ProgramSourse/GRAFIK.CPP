void ShowGraph(STYLE st1, int N, int arrSize, FILE *file/*, double *Xi, double **Yi*/)
{
  double mx, my, kx, ky, XMAX, YMAX, XMIN, YMIN;
  mx=my=kx=ky=XMAX=YMAX=XMIN=YMIN=0.0;
  int yPos=0, xPos=0, y2Pos=0, x2Pos=0, centerX=0, centerY=0, yWidth=0, xWidth=0;
  centerX=st1.x1+20;
  centerY=st1.y1+st1.height-20;
  yWidth=centerY-st1.y1-60;
  xWidth=st1.x1+st1.lenght-40-centerX;

  int i=0,j=0;
  char *buf=NULL;
  XY xy1, xy2;
  memset(&xy1,0,sizeof(XY));
  memset(&xy1,0,sizeof(XY));
  buf=(char*)calloc(10,sizeof(char));
  for(i=0;i<arrSize;i++)
  {
    memset(&xy1,0,sizeof(XY));
    fread(&xy1,sizeof(XY),1,file);
    if(xy1.x[0]>XMAX)
    {
      XMAX=xy1.x[0];
    }
    else
    {
      if(xy1.x[0]<XMIN)
      {
	XMIN=xy1.x[0];
      }
    }
  }
  fseek(file,0L,SEEK_SET);
  YMAX=-1.0;
  YMIN=32500.0;//Yi[0][0];
for(i=1;i<(N+1);i++)
{
  fseek(file,0L,SEEK_SET);
  for(j=0;j<arrSize;j++)
  {
    memset(&xy1,0,sizeof(XY));
    fread(&xy1,sizeof(XY),1,file);
    if(xy1.x[i]>YMAX)
    {
      YMAX=xy1.x[i];
    }
    else
    {
      if(xy1.x[i]<YMIN)
      {
	YMIN=xy1.x[i];
      }
    }
  }
}
  setfillstyle(1,st1.fon);
  bar(st1.x1+20,st1.y1+40,st1.x1+st1.lenght-20,st1.y1+st1.height-20);

  setcolor(st1.axeColor);

  line(centerX,centerY+10,centerX,st1.y1+40);//vert
  line(centerX-10,centerY,st1.x1+st1.lenght-20,centerY);//horiz
  line(centerX+1,centerY+10,centerX+1,st1.y1+40);//vert+1
  line(centerX-10,centerY+1,st1.x1+st1.lenght-20,centerY+1);//horiz+1

  line(centerX,st1.y1+40,centerX+5,st1.y1+50);//top right
  line(centerX,st1.y1+40,centerX-5,st1.y1+50);//top left

  line(st1.x1+st1.lenght-20,centerY,st1.x1+st1.lenght-30,centerY+5);//horizontal right
  line(st1.x1+st1.lenght-20,centerY,st1.x1+st1.lenght-30,centerY-5);//horizontal left
  //*****
  line(centerX,st1.y1+40,centerX+4,st1.y1+50);//top right+1
  line(centerX,st1.y1+40,centerX-4,st1.y1+50);//top left+1

  line(st1.x1+st1.lenght-20,centerY,st1.x1+st1.lenght-30,centerY+4);//horizontal right+1
  line(st1.x1+st1.lenght-20,centerY,st1.x1+st1.lenght-30,centerY-4);//horizontal left +1

  setcolor(st1.axeColor+1);
  outtextxy(centerX-15,st1.y1+40,"y");
  outtextxy(st1.x1+st1.lenght-25,centerY+7,"x");
  outtextxy(centerX-10,centerY+5,"0");

  memset(buf,'\0',10);
  sprintf(buf,"%.1lf",XMAX/2);
  outtextxy(centerX+xWidth/2,centerY+7,buf);
  memset(buf,'\0',10);
  sprintf(buf,"%.1lf",XMAX);
  outtextxy(centerX+xWidth-40,centerY+7,buf);
  setcolor(7);
  for(i=20;i<=yWidth;i+=20)
    line(centerX+2,centerY-i,st1.x1+st1.lenght-20,centerY-i);//horiz
  setcolor(st1.axeColor+1);
  memset(buf,'\0',10);
  sprintf(buf,"%.1lf",YMAX/2);
  outtextxy(centerX+5,centerY-yWidth/2,buf);
  memset(buf,'\0',10);
  sprintf(buf,"%.1lf",YMAX);
  outtextxy(centerX+5,st1.y1+50,buf);
  memset(buf,'\0',10);
  if(fabs(XMIN)>fabs(XMAX))
    mx=fabs(XMIN);
  else
    mx=fabs(XMAX);
  if(fabs(YMIN)>fabs(YMAX))
    my=fabs(YMIN);
  else
    my=fabs(YMAX);
  kx=xWidth/(mx);
  ky=yWidth/(my);

  setcolor(2);
  setlinestyle(0,1,1);
  for(i=1;i<(N+1);i++)
  {
    fseek(file,0L,SEEK_SET);
      setlinestyle(i-1,1,1);
      setcolor(i);
    for(j=0;j<arrSize-1;j++)
    {
      if(j%2==0)
      {
	memset(&xy1,0,sizeof(XY));
	fread(&xy1,sizeof(XY),1,file);
      if(xy1.x[0]==0 && j>0 )
	 break;
      }
      else
      {
	memset(&xy2,0,sizeof(XY));
	fread(&xy2,sizeof(XY),1,file);
      if(xy2.x[0]==0 && j>0 )
	break;
      }
      if(xy1.x[0]>0 || xy2.x[0]>0 && j>0)
      {
	xPos=xy1.x[0]*kx+centerX;
	yPos=centerY-xy1.x[i]*ky;
	x2Pos=xy2.x[0]*kx+centerX;
	y2Pos=centerY-xy2.x[i]*ky;
      }
      line(xPos,yPos,x2Pos,y2Pos);
    }
  }
  free(buf);
}