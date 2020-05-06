#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "diskfct.h"
#include "calcul.h"

int main(int argc, char *argv[])
{
    double xi = 0;          //valeur initial
    double xmax = 25;          //valeur final
    int NP = 50 ;                //nombre de points
    double h = (xmax-xi)/NP;     //PAS

    // Initialisation des tableaux 
	double *Y=NULL; 
    double *X=NULL; 
	Y=malloc((NP+1)* sizeof(double));
	X=malloc((NP+1)* sizeof(double));

    //interpolation
    Euler(Y,X,h,NP);
    
    Write(X,Y,NP);
	free(Y);
    free(X);

    return 0;
}