void R_Kutt(int N,double x,double *y,double h);
void Improved_Eyler(int N,double x,double *y,double h);
void Hemming(int N,double h,double x,double **y,double **y1);
void System(double x,double *Y,double *F);

double alfa=0.01, eps=0.000001;

#include "difury.cpp"
