#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex/complex.h"

int main(int argc, char *argv[])
{
    char option[3], *pch;
    char num_complex[10];
    FILE *arch;
    Complex complex;
    Polar polar;

    char Error[] = "Formato Invalido!\n\nOBS:\ncpbuild [OPTION] <complex_number_string> <file_name>\n\nOPTION:\n-a\tforma algébrica (default)\n-p\tforma polar/trigonométrica\n-v\tforma vetorial/geométrica\n\n<complex_number_string>:\na+bi\tpara a forma algébrica\nr;theta\tpara a forma polar/trigonométrica\n[a,b]\tpara a forma vetorial/geométrica\n\n<file_name>:\nnome do arquivo\n";

    if (argc != 4)
    {
        printf("%s", Error);
        exit(1);
    }

    strcpy(option, argv[1]);
    strcpy(num_complex, argv[2]);
    arch = fopen(argv[3], "wb");

    if (strcmp(option, "-a") == 0)
    {
        pch = strtok(num_complex, "+i");
        complex.real = atof(pch);
        pch = strtok(NULL, "+i");
        complex.img = atof(pch);

        fwrite(&complex, 1, sizeof(complex), arch);
    }
    else if (strcmp(option, "-p") == 0)
    {
        pch = strtok(num_complex, ";");
        polar.r = atof(pch);
        pch = strtok(NULL, ";");
        polar.theta = atof(pch);

        complex = polarToAlgebraic(&polar);

        fwrite(&complex,sizeof(complex), 1, arch);
    }
    else if (strcmp(option, "-v") == 0)
    {
        pch = strtok(num_complex, "[,]");
        complex.real = atof(pch);
        pch = strtok(NULL, "[,]");
        complex.img = atof(pch);

        fwrite(&complex, 1, sizeof(complex), arch);
    }
    else
    {
        printf("%s", Error);
        exit(1);
    }

    fclose(arch);
    return 0;
}