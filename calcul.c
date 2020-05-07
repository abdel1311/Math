#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double m = 80;
double alpha = 30;
double g = 9.81 ;
double VO = 0; 

double f(double x,double y)
{
    double tau = m/alpha;
    return g - (1/tau)*y*y;
}
int Euler (double* Y,double h, int N)
{
    Y[0] = 0;
    for (int i = 0;i<N;i++)
    {
        Y[i+1] = (double) Y[i]+ h*f(i*h,Y[i]);
    }
    return 1;
}


int Analytique(double* Ana, double h, double N)
{
    double t;
    double tau = m/alpha;
    double k = sqrt(tau * g);

    for (int i = 1;i<N;i++)
    {
        t = i*h;
        Ana[i] = k * (((VO-k)/(VO+k)) * exp((-2*k*t)/tau) +1) / (1-(VO-k)/(VO+k) * exp((-2*k*t)/tau));
    }
    return 1;
}


double Erreur( double* Y,double* Ana,double h,int N)
{
    double Erreur = 0;
    double Erreur_temp = 0;
    for (int i = 0;i<N+1;i++)
    {
        Erreur_temp = fabs(Y[i]-Ana[i]);
        if (Erreur_temp>Erreur)
        {
            Erreur = Erreur_temp;
        }
    }
    //printf("%f\n",Erreur);
    return Erreur;
}
