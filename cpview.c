#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex/complex.h"

// Arrumar o view -p

int main(int argc, char *argv[])
{
    char option[3];
    FILE *arch;
    Complex complex;
    Polar polar;

    char Error[] = "\nOBS:\ncpview [OPTION] <file_name>\n\nOPTION:\n-a\tforma algébrica (default)\n-p\tforma polar/trigonométrica\n-v\tforma vetorial/geométrica\n\n<file_name>:\nnome do arquivo\n";

    if (argc != 3)
    {
        printf("Formato invalido!\n%s", Error);
        exit(1);
    }

    strcpy(option, argv[1]);
    arch = fopen(argv[2], "rb");

    if (arch == NULL)
    {
        printf("Arquivo Inexistente!\n%s", Error);
        exit(1);
    }

    if (strcmp(option, "-a") == 0)
    {
        fread(&complex, 1, sizeof(complex), arch);
        printf("%.0f+%.0fi\n", complex.real, complex.img);
    }
    else if (strcmp(option, "-p") == 0)
    {
        fread(&complex, 1, sizeof(complex), arch);
        polar = algebraicToPolar(&complex);
        printf("%.2lf;%.2lf\n", polar.r, polar.theta);
    }
    else if (strcmp(option, "-v") == 0)
    {
        fread(&complex, 1, sizeof(complex), arch);
        printf("[%.0f,%.0f]\n", complex.real, complex.img);
    }
    else
    {
        printf("Formato invalido!\n%s", Error);
        exit(1);
    }

    fclose(arch);
    return 0;
}