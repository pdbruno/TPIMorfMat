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
bool pertenece(const vector<pixel>& list, const pixel& p);
bool esBorde(const imagen &A, const pixel& p);
bool tocaBackgroundAdK(const imagen &A, const pixel& p, int k);
sqPixel convertirASecuencia(const imagen &A);
imagen convertirAImagen(const sqPixel &A, int n, int m);
sqPixel dilatacion(const sqPixel &A, const sqPixel &B, int n, int m);
sqPixel erosion(const sqPixel &A, const sqPixel &B, int n, int m);
sqPixel desplazar (const sqPixel &B, const pixel &p);
bool hayInterseccion(const sqPixel &A, const sqPixel &B);
bool contenido(const sqPixel &contenedor, const sqPixel &contenido, int n, int m);
sqPixel interseccion(const sqPixel &A, const sqPixel &B);
bool iguales(const sqPixel &A, const sqPixel &B);
tuple <int, sqPixel> extraerRegion(const imagen &A, const pixel &semilla, int k);
vector<sqPixel> quitarRepetidos(const vector<sqPixel> &A);
bool perteneceInt(const vector<int>& list, const int& x);
