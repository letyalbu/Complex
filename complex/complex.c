#include "complex.h"
#include "math.h"

Complex polarToAlgebraic(Polar *P)
{
    Complex C;

    C.img = P->r * (cos(P->theta) + sin(P->theta));
    C.real = 0;

    return C;
}

Polar algebraicToPolar(Complex *C)
{
    Polar P;

    P.r = sqrt(pow(C->real, 2) + pow(C->img, 2));

    if (P.r < 0)
        P.r *= -1;

    P.theta = 1 / (tan(C->img / C->real));

    return P;
}

Complex SumComplex(Complex *c1, Complex *c2)
{
    Complex Sum;

    Sum.real = c1->real + c2->real;
    Sum.img = c1->img + c2->img;

    return Sum;
}

Complex SubComplex(Complex *c1, Complex *c2)
{
    Complex Sub;

    Sub.real = c1->real - c2->real;
    Sub.img = c1->img - c2->img;

    return Sub;
}

Complex MultComplex(Complex *c1, Complex *c2)
{
    Complex Mult;

    Mult.real = c1->real * c2->real - c1->img * c2->img;
    Mult.img = c1->real * c2->img + c1->img * c2->real;

    return Mult;
}

Complex DivComplex(Complex *c1, Complex *c2){
    Complex Div;

    Div.real = (c1->real * c2->real + c1->img * c2->img) / (pow(c2->real,2) + pow(c2->img,2));
    Div.img = (c1->img * c2->real - c1->real * c2->img) / (pow(c2->real,2) + pow(c2->img,2));

    return Div;
}