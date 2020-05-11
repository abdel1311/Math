#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double m = 80;
double alpha = 30;
double g = 9.81;
double VO = 0;



double f(double x, double y)
{
    double tau = m / alpha;
    return g - (1 / tau) * y * y;
}
int Euler(double *Y, double h, int N)
{
    Y[0] = 0;
    for (int i = 0; i < N; i++)
    {
        Y[i + 1] = (double)Y[i] + h * f(i * h, Y[i]);
    }
    return 1;
}

int RK2(double* Y,double h,int N)
{
    double K1;
    double K2;
     Y[0] = 0+VO; 
      for (int i = 0;i<N;i++)
    {
        K1 = h*f(i*h,Y[i]);
        K2 = 0.5*(K1+f(i*h+h,Y[i]+h*K1));
        Y[i+1]=(double) Y[i]+0.5*(K1+K2);

    }
    return 1;
}

int Analytique(double *Ana, double h, double N)
{
    double t;
    double tau = m / alpha;
    double k = sqrt(tau * g);

    for (int i = 1; i < N+1; i++)
    {
        t = i * h;
        Ana[i] = k * (((VO-k)/(VO+k)) * exp((-2*k*t)/tau)+1) / (1- (VO-k)/(VO+k) *exp((-2*k*t)/tau) );
    }
    return 1;
}

int Erreur( double* E, double* N_list, int taille_list, double h, double xmin, double xmax,char* selecteur )
{
    double N;
    double Erreur = 0;
    double Erreur_temp = 0;

    for (int i = 0; i < taille_list; i++)
    {

        N = N_list[i];
        h = (xmax - xmin) / N;
        double *Y = NULL;
        Y = malloc((N + 1) * sizeof(double));
        if (strcmp(selecteur,"Euler") == 0)
        {
            Euler(Y, h, N);
        }
        else if (strcmp(selecteur,"RK2") == 0)
        {
            RK2(Y ,h , N);
        }
        else 
        {
            printf("Méthode non reconnue\n");
            return 0;
        }

        double *Ana = NULL;
        Ana = malloc((N + 1) * sizeof(double));
        Analytique(Ana, h, N);

        Erreur = 0;
        Erreur_temp = 0;

        for (int j = 0; j < N + 1; j++)
        {
            Erreur_temp = fabs(Y[j] - Ana[j]);
            if (Erreur_temp > Erreur)
            {
                Erreur = Erreur_temp;
            }
        }
        E[i] = Erreur;
        free(Ana);
    }
    return 1;
}


int choix ()
{
    printf("veuillez rentrer la valeur de alpha souhaité:");
    scanf("%lf",&alpha);    
    printf("veuillez rentrer la valeur de V0 souhaité:");
    scanf("%lf",&VO);
    
    return 0;
}
