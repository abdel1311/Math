#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "diskfct.h"
#include "calcul.h"

int main(int argc, char *argv[])
{

    double xmin = 0;            //valeur minimal
    double xmax = 25;           //valeur maximl

    int N = 50 ;                //nombre de points
    double h = (xmax-xmin)/N;        //PAS
    
    // Initialisation des tableaux 
    double *X=NULL; 
	double *Y=NULL; 
	Y=malloc((N+1)* sizeof(double));
	X=malloc((N+1)* sizeof(double));

    for (int i = 1;i<N+1;i++)
    {
        X[i] = (double) i*h;
    }

    //interpolation
    Euler(Y,h,N);
    Write(X,Y,"vel_euler.dat",N);


    double *Ana=NULL; 
    double *E=NULL; 
    Ana=malloc((N+1)* sizeof(double));
    E=malloc(4* sizeof(double));
    Analytique(Ana,h,N);
    Write(X,Ana,"Ana.dat",N);

    double N_list[4] = {50,100,200,400};

    for (int i = 0;i < 4;i++)
    {
        N = N_list[i];
        h = (xmax-xmin)/N;

        Analytique(Ana,h,N);

        for (int c = 0;c < N;c++)
        {
            //printf("%d %f\n",i,Ana[c]);
        }
        E[i]=Erreur(Y,Ana,h,N);
        printf("%d %f\n",N,E[i]);
    }    

    Write(N_list,E,"Erreur.dat",4);

	free(Y);
    free(X);
    free(Ana);
    free(E);
    return 0;
}