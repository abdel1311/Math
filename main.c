#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diskfct.h"
#include "calcul.h"

int main(int argc, char *argv[])
{

    double xmin = 0;  //valeur minimal
    double xmax = 25; //valeur maximl

    int N = 50;                   //nombre de points
    double h = (xmax - xmin) / N; //PAS

    // Initialisation des tableaux
    double *X = NULL;
    double *Y = NULL;
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));

    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }

    //interpolation méthode d'Euler
    Euler(Y, h, N);
    Write(X, Y, "vel_euler.dat", N);

    //Calcul Analytique
    double *Ana = NULL;
    Ana = malloc((N + 1) * sizeof(double));
    Analytique(Ana, h, N);
    Write(X, Ana, "Ana.dat", N);

    //Calcul d'erreur Euler
    double N_list[4] = {50, 100, 200, 400};
    int taille_list = 4;
    
    double *E = NULL;
    E = malloc(taille_list * sizeof(double));

    Erreur( E, N_list, taille_list, h, xmin, xmax,"Euler");
    Write(N_list, E, "Erreur.dat", 4);

    //RK2

    //Intégration 



    free(Y);
    free(X);
    free(Ana);
    free(E);
    return 0;
}