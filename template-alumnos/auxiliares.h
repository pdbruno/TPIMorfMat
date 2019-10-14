//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"


#endif //SOLUCION_AUXILIARES_H

bool esMatriz(const imagen &A);
bool esBinaria(const imagen &A);
bool sonPixelesConectadosViniendoDe(const imagen& A, const pixel& p, const pixel& q, int k, vector<pixel> blacklist);
bool pixelValidoEncendido(const imagen &A, const pixel& p);
bool notIn(const vector<pixel>& list, const pixel& p);
