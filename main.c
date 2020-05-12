#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "diskfct.h"
#include "calcul.h"

int main(int argc, char *argv[])
{
    //
    double xmin = 0;  //valeur minimal
    double xmax = 25; //valeur maximl

    int N = 50;                                 //Nombre de points
    double h = (xmax - xmin) / N;               //Pas
    choix_condition((double)30,(double)0);      //Choix de alpha et V0

    //interpolation méthode d'Euler
    double *X = NULL;
    double *Y = NULL;
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    Euler(Y, h, N);
    Write(X, Y, "vel_euler.dat", N);
    //Euler N=100
    N = 100;                                 //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    Euler(Y, h, N);
    Write(X, Y, "vel_euler_100.dat", N);
    //Euler N=200
    N = 200;                                 //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    Euler(Y, h, N);
    Write(X, Y, "vel_euler_200.dat", N);
    //Euler N=400
    N = 400;                                 //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    Euler(Y, h, N);
    Write(X, Y, "vel_euler_400.dat", N);


    //interpolation méthode RK2
    N = 50;                             //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    RK2(Y, h, N);
    Write(X, Y, "vel_RK2.dat", N);
    //RK2 N = 100
    N = 100;                             //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    RK2(Y, h, N);
    Write(X, Y, "vel_RK2_100.dat", N);
    //RK2 N = 200
    N = 200;                             //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    RK2(Y, h, N);
    Write(X, Y, "vel_RK2_200.dat", N);
    //RK2 N = 400
    N = 400;                             //Nombre de points
    h = (xmax - xmin) / N;               //Pas
    Y = malloc((N + 1) * sizeof(double));
    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }
    RK2(Y, h, N);
    Write(X, Y, "vel_RK2_400.dat", N);



    //Calcul Analytique
    double *Ana = NULL;
    Ana = malloc((N + 1) * sizeof(double));
    Analytique(Ana, h, N);
    Write(X, Ana, "Ana.dat", N);


    double N_list[4] = {50, 100, 200, 400};
    int taille_N_list = 4;

    //Calcul d'erreur Euler
    double *E = NULL;
    E = malloc(taille_N_list * sizeof(double));

    Erreur_list(E, N_list, taille_N_list, h, xmin, xmax,"Euler");
    Write(N_list, E, "Erreur_euler.dat", 4);

    //Calcul d'erreur rk2
    E = malloc(taille_N_list * sizeof(double));

    Erreur_list(E, N_list, taille_N_list, h, xmin, xmax,"RK2");
    Write(N_list, E, "Erreur_RK2.dat", 4);
    

    //choix d'alpha 
    double alpha_list[4] = {10, 20, 30, 40};
    int taille_alpha_list = 4;
    E = malloc(taille_alpha_list * sizeof(double));
    for (int i = 0; i < taille_alpha_list; i++)
    {
        choix_condition(alpha_list[i],(double)0);
        Euler(Y, h, N);
        Erreur(E,Y,N,h,i);
    }
    Write(alpha_list, E, "Erreur_alpha.dat", 4);
    
    //choix VO
     choix_condition((double)10,(double)10);
    Euler(Y, h, N);
    Write(X, Y, "Euler_V0_10.dat", N);

    choix_condition((double)10,(double)0);
    Euler(Y, h, N);
    Write(X, Y, "Euler_V0_0.dat", N);




    N = (double) 400;
    double *IAna = NULL;
    IAna = malloc((N + 1) * sizeof(double));
    iAnalytique( IAna, X,N);
    Write(X, IAna,"Ana_x.dat", N);


    //Intégration point milieu 
    N = (double) 800;
    h = (xmax - xmin) / N; 
    Ana = malloc((N + 1) * sizeof(double));
    Analytique(Ana, h, N);

    double *x_p = NULL;
    x_p = malloc((N + 1) * sizeof(double));

    point_milieu(x_p,Ana,N);

    //Intégration Trapéze
    N = (double) 400;
    h = (xmax - xmin) / N; 

    X = malloc((N + 1) * sizeof(double));
    for (int i = 1; i < N + 1; i++)
    {
        X[i] = (double)i * h;
    }

    Ana = malloc((N + 1) * sizeof(double));
    Analytique(Ana, h, N);
    choix_condition((double)20,0);

    double *x_t = NULL;
    x_t = malloc((N + 1) * sizeof(double));

    trapeze(x_t,Ana, h, N);



    Write_3(X, x_t,x_p,"Pos.dat", N);



    //acceleration vroom vroom
    N = (double) 400;

    double *P = NULL;
    P = malloc((N-1) * sizeof(double));
    acceleration_RK2(X,P,Y,h,N);
    Write(X, P, "Accel_RK2.dat", N); 
    double *P2 = NULL;
    P2 = malloc((N-1) * sizeof(double));

    acceleration_EULER(X, P2, Y, h, N);
    Write(X, P2, "Accel_EULER.dat", N); 

    double *P3 = NULL;
    P3 = malloc((N-1) * sizeof(double));
    acceleration_ANA(X, P3, Y, h, N);
    Write(X, P3, "Accel_ANA.dat", N); 

    N = (double) 400;
    double *DAna = NULL;
    DAna = malloc((N + 1) * sizeof(double));
    dAnalytique(DAna, X,N);

    Write(X, DAna,"Ana_a.dat", N);

    free(Y);
    free(X);
    free(Ana);
    free(E);
    free(x_p);
    free(x_t);
    free(P);
    free(IAna);
    free(DAna);

    return 0;
}