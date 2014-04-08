//****Create DataBase******//
int CreateDB(char *path)
{
  FILE *db;
  db=fopen(path,"wb");
  if(!db)
  {
    perror("Cannot create Data Base: ");
    exit(1);
  }
  fclose(db);
  return TRUE;
}
//******Get Number of records*****/////
unsigned int GetSize(FILE *DataBase)
{
  long endPosition=0;
  unsigned int Size=0;
  fseek(DataBase,0L,SEEK_END);
  endPosition=ftell(DataBase);
  fseek(DataBase,0L,SEEK_SET);
  Size=endPosition/sizeof(ECO);
  return Size;
}
unsigned int GetDSize(FILE *DataBase)
{
  long endPosition=0;
  unsigned int Size=0;
  fseek(DataBase,0L,SEEK_END);
  endPosition=ftell(DataBase);
  fseek(DataBase,0L,SEEK_SET);
  Size=endPosition/sizeof(double);
  return Size;
}

//**********************
FILE *OpenDB(char *path,unsigned int mode)
{
  FILE *DataBase;
  switch(mode)
  {
    case READONLY:
      DataBase=fopen(path,"rb");
      break;
    case READnWRITE:
      DataBase=fopen(path,"r+b");
      break;
    case REWRITECURRENT:
      DataBase=fopen(path,"wb");
      break;
  }
  return DataBase;
}
//*********************
void CloseDB(FILE *DataBase)
{
  fclose(DataBase);
}
//*********************
		     /*
void ConvertTXTtoBINARY(char *pathToTXT)
{
	memset(strres,'\0',sizeof(strres));
	strcpy(strres,pathToTXT);
	strcat(strres,".rsd");
	strcat(pathToTXT,".txt");
	FILE *text;
	int i=0;
	char *s;
	memset(s,'\0',sizeof(s));
	if((text=fopen(pathToTXT,"r"))==NULL)
	{
		perror("Error code: ");
		getch();
		exit(1);
	}
	FILE *binary=fopen(strres,"wb");
	while(!feof(text))
	{
		fgets(s,10,text);
		fseek(binary,0L,SEEK_END);
		fwrite(s,strlen(s),1,binary);
		i++;
	}
	fclose(text);
	fclose(binary);
}
void ShowBinaryInfo(unsigned int wx1,unsigned int wy1,unsigned int tempWinLen, char *pathToBINARY, unsigned int mode)
{
	strcpy(strres,pathToBINARY);
	FILE *binary=fopen(strres,"rb");
	long size=0;
	char s1;
	int y=wy1,k=wx1,i=0;
	switch(mode)
	{
	  case DONTMODIFYTEXT:
	    fseek(binary,0L,SEEK_END);
	    size=ftell(binary)/sizeof(char);
	    y=wy1,k=wx1,i=0;
	    while(i<size)
	    {
	      fseek(binary,i*sizeof(char),SEEK_SET);
	      fread(&s1,sizeof(char),1,binary);
	      delay(5);
	      if(s1=='\n')
	      {
				k=wx1;
				y=wherey()+1;
	      }
	      gotoxy(k,y);
	      cprintf("%c",s1);
	      i++;
	      k++;
	    }
	 break;
  case MODIFYTEXT:
	fseek(binary,0L,SEEK_END);
	size=ftell(binary)/sizeof(char);
	y=wy1,k=wx1,i=0;
	while(i<size)
	{
	 fseek(binary,i*sizeof(char),SEEK_SET);
	 fread(&s1,sizeof(char),1,binary);
	 delay(5);
	if(s1=='<')
	{
	  while(s1!=' ')
	  {
	    textcolor(14);
	    cprintf("%c",s1);
		i++;   k++; y=wherey();
			    fseek(binary,i*sizeof(char),SEEK_SET);
	    fread(&s1,sizeof(char),1,binary);

	  }
	}
	textcolor(7);
	if(s1=='\n'||k>tempWinLen)
	{
	 k=wx1;
	 y=wherey()+1;
	}
	gotoxy(k,y);
	cprintf("%c",s1);
	i++;
	k++;
	}break;
	}
	fclose(binary);
}*/