#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
    char code[2];
    double real;
    double img;
} Complex;

typedef struct
{
    char code[2];
    double r;
    double theta;
} Polar;

/**
 * @brief Converte da forma polar/trigonometrica para a forma algebrica.
 * 
 * @param P Complexo na forma polar/trigonometrica
 * @return
 */
Complex polarToAlgebraic(Polar *P);

/**
 * @brief Converte da forma algebrica para a forma polar/trigonometrica.
 * 
 * @param C Complexo na forma algebrica
 * @return
 */
Polar algebraicToPolar(Complex *C);

/**
 * @brief Recebe dois complexos e retorna a adição de ambos (c1 + c2).
 * 
 * @param c1 fator esquerdo da soma
 * @param c2 fator direito da soma
 * @return
 */
Complex SumComplex(Complex *c1, Complex *c2);

/**
 * @brief Recebe dois complexos e retorna a subtração de ambos (c1 - c2).
 * 
 * @param c1 fator esquerdo da subtração
 * @param c2 fator direito da subtração
 * @return
 */
Complex SubComplex(Complex *c1, Complex *c2);

/**
 * @brief Recebe dois complexos e retorna o produto de ambos (c1 * c2).
 * 
 * @param c1 primeiro fator do produto
 * @param c2 segundo fator do produto
 * @return 
 */
Complex MultComplex(Complex *c1, Complex *c2);

/**
 * @brief Recebe dois complexos e retorna o quociente de ambos (c1 / c2).
 * 
 * @param c1 numerador
 * @param c2 denominador
 * @return
 */
Complex DivComplex(Complex *c1, Complex *c2);

#endif