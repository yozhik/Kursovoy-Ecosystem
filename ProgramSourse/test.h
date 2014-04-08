void R_Kutt_T1(int N,double x,double *y,double h);
void Improved_Eyler_T1(int N,double x,double *y,double h);
void Hemming_T1(int N,double h,double x,double **y,double **y1);

void R_Kutt_T2(int N,double x,double *y,double h);
void Improved_Eyler_T2(int N,double x,double *y,double h);
void Hemming_T2(int N,double h,double x,double **y,double **y1);

void System_T1(double x,double *Y,double *F);
void System_T2(double x,double *Y,double *F);

double Test1(double x);
double Test2(double x);

#include "test.cpp"