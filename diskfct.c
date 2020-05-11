#include <stdio.h>
#include <stdlib.h>

int Write(double *X, double *Y, char *nom_fichier, int taille_list)
{
	FILE *fichier = NULL;
	fichier = fopen(nom_fichier, "w");
	for (int i = 0; i < taille_list; i++)
	{
		fprintf(fichier, "%f ; %f\n", X[i], Y[i]);
	}
	return 0;
}

int Write_3(double* T,double *X, double *Y, char *nom_fichier, int taille_list)
{
	FILE *fichier = NULL;
	fichier = fopen(nom_fichier, "w");
	for (int i = 0; i < taille_list; i++)
	{
		fprintf(fichier,"%f ; %f ; %f\n",T[i], X[i], Y[i]);
	}
	return 0;
}