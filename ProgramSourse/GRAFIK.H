#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <mem.h>
#include <string.h>

typedef struct ST
  {
    int x1;
    int y1;
    int lenght;
    int height;
    char fon;
    char axeColor;
  }STYLE;
void ShowGraph(STYLE st1, int N, int arrSize, FILE *file/*, double *X, double **Y*/);

#include "grafik.cpp"