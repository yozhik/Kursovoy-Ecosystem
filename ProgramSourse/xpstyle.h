void RefreshDesctop(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2, int desctopColor);

void WindowsVista(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkCol,char *msg);
void Window(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkColor);
void WindowXP(unsigned int lx,unsigned int ly,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkColor, char *msg);

unsigned int GetLeftXPos(unsigned int tempWinLen);
void StatusBar(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int textColor,unsigned int bkColor,char *statusText);
void SetHButtonText(unsigned int lx, unsigned int ly, int mode,char *str);
void SetVButtonText(unsigned int lx, unsigned int ly, unsigned int Width, int mode, char *str);
void SetDefault(void);

#include "xpstyle.cpp"