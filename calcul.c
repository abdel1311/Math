#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x,double y)
{
    return 9.81 - (20/80)*y*y;
}


int Euler ( double* Y,double* X,double h, int NP)
{
    for (int i = 1;i<=NP+1;i++)
    {
        X[i] = (double) i*h;
    }
    Y[0] = 0;
    for (int i = 1;i<NP+1;i++)
    {
        Y[i+1] = (double) Y[i]+ h*f(i*h,Y[i]);

    }
    return 1;
}


