void System_T1(double x,double *y,double *F)
{
  F[0] = x;
}
void System_T2(double x,double *y,double *F)
{
  F[0] = cos(x);
}
double Test1(double x)
{
  return ((x*x)/2);
}
double Test2(double x)
{
  return sin(x);
}
//*********************
void R_Kutt_T1(int N,double x,double *y,double h)
{
  int i=0;
  double *k1=NULL, *k2=NULL, *k3=NULL, *k4=NULL, *y_temp=NULL, *F=NULL;

  k1=(double*)calloc(N,sizeof(double));
  k2=(double*)calloc(N,sizeof(double));
  k3=(double*)calloc(N,sizeof(double));
  k4=(double*)calloc(N,sizeof(double));
  y_temp=(double*)calloc(N,sizeof(double));
  F=(double*)calloc(N,sizeof(double));
  if(!k1 || !k2 || !k3 || !k4 || !y_temp || !F) exit(1);
    System_T1(x,y,F);
    for(i=0;i<N;i++)
    {
	  k1[i]=h*F[i];
	  y_temp[i]=y[i]+0.5*k1[i];
    }
    x=x+h*0.5;
    System_T1(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k2[i]=h*F[i];
	  y_temp[i]=y[i]+0.5*k2[i];
    }
    System_T1(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k3[i]=h*F[i];
	  y_temp[i]=y[i]+k3[i];
    }
    x=x+h*0.5;
    System_T1(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k4[i]=h*F[i];
	  y[i]=y[i]+(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6;
    }
//***Free memory***
  free(k1);
  free(k2);
  free(k3);
  free(k4);
  free(y_temp);
  free(F);
}
//************************
void Improved_Eyler_T1(int N,double x,double *y,double h)
{
  int i=0;
  double *y_temp=NULL, *F=NULL;

  y_temp=(double*)calloc(N,sizeof(double));
  F=(double*)calloc(N,sizeof(double));
  if(!y_temp || !F) exit(1);
    System_T1(x,y,F);
  x=x+h*0.5;

  for(i=0;i<N;i++)
  {
    y_temp[i]=y[i]+0.5*h*F[i];
  }
      System_T1(x,y_temp,F);

  x=x+h*0.5;
  for(i=0;i<N;i++)
  {
    y[i]=y[i]+h*F[i];
  }
  //***Free memory**//
  free(y_temp);
  free(F);
}
void Hemming_T1(int N,double h,double x,double **y,double **y1)
{
  int k=0,j=0;

  double *fp=NULL,*fk=NULL,*yp=NULL,*yk=NULL,max=0.0,c=0.0;
  fp=(double*)calloc(N,sizeof(double));
  fk=(double*)calloc(N,sizeof(double));
  yp=(double*)calloc(N,sizeof(double));
  yk=(double*)calloc(N,sizeof(double));
  if(!fp || !fk || !yp || !yk) exit(1);
  for(k=0;k<N;k++)
    yp[k]=y[k][0]+(4/3)*h*(2*y1[k][3]-y1[k][2]+2*y1[k][1]);
  System_T1(x,yp,fp);
  x=x+h;
  do
  {
	for(k=0;k<N;k++)
	  yk[k]=(9*y[k][3]-y[k][1]+3*h*(fp[k]+2*y1[k][3]-y1[k][2]))/8;
	System_T1(x,yk,fk);
	max=0.0;
	for(k=0;k<N;k++)
	{
	  c=fabs(fk[k]-fp[k]);
	  if(c>max) max=c;
	}
	if(max<=eps) break;
	else
	{
	  for(k=0;k<N;k++)
		  fp[k]=fk[k];
	}
  }while(1);
  for(k=0;k<N;k++) //cycle for rivnannja
  {
	for(j=0;j<3;j++) // cycle for tochkax
	{
		y[k][j]=y[k][j+1];
		y1[k][j]=y1[k][j+1];

	}
	y[k][3]=yk[k];
	y1[k][3]=fk[k];

  }
  free(yp);
  free(yk);
  free(fp);
  free(fk);
}
//*********************
void R_Kutt_T2(int N,double x,double *y,double h)
{
  int i=0;
  double *k1=NULL, *k2=NULL, *k3=NULL, *k4=NULL, *y_temp=NULL, *F=NULL;

  k1=(double*)calloc(N,sizeof(double));
  k2=(double*)calloc(N,sizeof(double));
  k3=(double*)calloc(N,sizeof(double));
  k4=(double*)calloc(N,sizeof(double));
  y_temp=(double*)calloc(N,sizeof(double));
  F=(double*)calloc(N,sizeof(double));
  if(!k1 || !k2 || !k3 || !k4 || !y_temp || !F) exit(1);
    System_T2(x,y,F);
    for(i=0;i<N;i++)
    {
	  k1[i]=h*F[i];
	  y_temp[i]=y[i]+0.5*k1[i];
    }
    x=x+h*0.5;
    System_T2(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k2[i]=h*F[i];
	  y_temp[i]=y[i]+0.5*k2[i];
    }
    System_T2(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k3[i]=h*F[i];
	  y_temp[i]=y[i]+k3[i];
    }
    x=x+h*0.5;
    System_T2(x,y_temp,F);
    for(i=0;i<N;i++)
    {
	  k4[i]=h*F[i];
	  y[i]=y[i]+(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6;
    }
//***Free memory***
  free(k1);
  free(k2);
  free(k3);
  free(k4);
  free(y_temp);
  free(F);
}
//************************
void Improved_Eyler_T2(int N,double x,double *y,double h)
{
  int i=0;
  double *y_temp=NULL, *F=NULL;

  y_temp=(double*)calloc(N,sizeof(double));
  F=(double*)calloc(N,sizeof(double));
  if(!y_temp || !F) exit(1);
    System_T2(x,y,F);
  x=x+h*0.5;

  for(i=0;i<N;i++)
  {
    y_temp[i]=y[i]+0.5*h*F[i];
  }
      System_T2(x,y_temp,F);

  x=x+h*0.5;
  for(i=0;i<N;i++)
  {
    y[i]=y[i]+h*F[i];
  }
  //***Free memory**//
  free(y_temp);
  free(F);
}
void Hemming_T2(int N,double h,double x,double **y,double **y1)
{
  int k=0,j=0;

  double *fp=NULL,*fk=NULL,*yp=NULL,*yk=NULL,max=0.0,c=0.0;
  fp=(double*)calloc(N,sizeof(double));
  fk=(double*)calloc(N,sizeof(double));
  yp=(double*)calloc(N,sizeof(double));
  yk=(double*)calloc(N,sizeof(double));
  if(!fp || !fk || !yp || !yk) exit(1);
  for(k=0;k<N;k++)
    yp[k]=y[k][0]+(4/3)*h*(2*y1[k][3]-y1[k][2]+2*y1[k][1]);
  System_T2(x,yp,fp);
  x=x+h;
  do
  {
	for(k=0;k<N;k++)
	  yk[k]=(9*y[k][3]-y[k][1]+3*h*(fp[k]+2*y1[k][3]-y1[k][2]))/8;
	System_T2(x,yk,fk);
	max=0.0;
	for(k=0;k<N;k++)
	{
	  c=fabs(fk[k]-fp[k]);
	  if(c>max) max=c;
	}
	if(max<=eps) break;
	else
	{
	  for(k=0;k<N;k++)
		  fp[k]=fk[k];
	}
  }while(1);
  for(k=0;k<N;k++) //cycle for rivnannja
  {
	for(j=0;j<3;j++) // cycle for tochkax
	{
		y[k][j]=y[k][j+1];
		y1[k][j]=y1[k][j+1];

	}
	y[k][3]=yk[k];
	y1[k][3]=fk[k];

  }
  free(yp);
  free(yk);
  free(fp);
  free(fk);
}