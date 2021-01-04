#include <stdio.h>
#include <stdlib.h>
#include "complex/complex.h"

int main(int argc, char *argv[])
{
    FILE *file1;
    FILE *file2;
    FILE *out;
    Complex complex1, complex2, mult;
    char Error[] = "Formato Invalido!\n\nOBS:\ncpmult <file_name_1> <file_name_2> <file_name_out>\n\n<file_name_1>:\nnome do arquivo do primeiro número complexo\n\n<file_name_2>:\nnome do arquivo do segundo número complexo\n\n<file_name_out>:\nnome do arquivo para o número complexo resultante\n";

    if (argc != 4)
    {
        printf("%s", Error);
        exit(1);
    }

    file1 = fopen(argv[1], "rb");
    file2 = fopen(argv[2], "rb");
    out = fopen(argv[3], "wb");

    fread(&complex1, 1, sizeof(complex1), file1);
    fread(&complex2, 1, sizeof(complex1), file2);

    mult = MultComplex(&complex1, &complex2);

    fwrite(&mult, 1, sizeof(mult), out);

    fclose(file1);
    fclose(file2);
    fclose(out);

    return 0;
}