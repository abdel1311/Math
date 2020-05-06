#include <stdio.h>
#include <stdlib.h>

int Write(double* X, double* Y,int NP) 
{
FILE* fichier = NULL;
fichier = fopen("vel_euler.dat", "w");

for (int i=0;i<NP+1;i++)
{
	fprintf(fichier,"%f %f\n",X[i],Y[i]);
}

return 0;
}