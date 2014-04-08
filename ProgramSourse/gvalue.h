//******COLORS*************
#define LEN 100

#define WINSTYLE 1//9
#define DESCTOP_STYLE 1//9

#define ACTIVE 1
#define NON_ACTIVE 0
#define TEXT 2

#define K 2
#define DELAYTIME 1
typedef void(*MENU)(int x1,int y1,char *string,...);
const SZ=K+1;
char **ppString=NULL;
int *buttonLenghtArray=NULL;
char *buttonText=NULL;

unsigned int x1=1,
y1=1,
y2=0,
x2=0,
dx=30,
leftVidstup=10,
topVidstup=2,
count=0,
bkColor=15,
textColor=0,
ActiveButtonColor=5,
ActiveTextColor=15,
winBK=15,
winTEXT=15,
winHEAD=13,
winLen=0,
winHeight=0,
winLX=1,
winLY=1,
leftXX=2,
leftYY=20,
SpaceBetweenButtons=3,
acrossSubButtons=25,
mashtab=1,
WinHeight=30,
textRiven=6;

int const desctopColor=0;
int MenuIndex=0,symbol=0;
unsigned int wx1=30,
wy1=10,
xmax=0,
ymax=0;
//******Experiment Data************
double t0=0.0, tn=20.0, h=0.1;
unsigned int x0=300, y0=150;//xo-rabbits, y0-foxes
int smResult=0;
FILE *xFile=NULL, *erFile=NULL, *rkFile=NULL, *hemFile=NULL, *gFile=NULL;