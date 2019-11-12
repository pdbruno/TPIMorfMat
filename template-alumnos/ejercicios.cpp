#include <tuple>
#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& A) {
    return (A.size() > 0 && esMatriz(A) && esBinaria(A));
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& A, const pixel& p, const pixel& q, int k) {
    return pixelValidoEncendido(A, p) && pixelValidoEncendido(A, q) && sonPixelesConectadosViniendoDe(A, p, q, k, {});
}

// Ejercicio 3

float devolverPromedioAreas(const imagen &A, int k){
	float prom = -1.0;
    vector<sqPixel> regionesConRepetidos;
    vector<sqPixel> regionesSinRepetidos;
    sqPixel region;

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] == 1){
                region = get<1>(extraerRegion(A, {i, j}, k));
                regionesConRepetidos.push_back(region);
            }
        }
    }
    if(regionesConRepetidos.empty()){
        prom = 0;
    } else {
        regionesSinRepetidos = quitarRepetidos(regionesConRepetidos);
        float acum = 0;
        for (int i = 0; i < regionesSinRepetidos.size(); ++i) {
            acum+= regionesSinRepetidos[i].size();
        }
        prom = acum/regionesSinRepetidos.size();
    }


    return prom;
}

// Ejercicio 4

sqPixel calcularContorno(const imagen &A, int k){
    sqPixel edges;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] == 1){
                if(esBorde(A, {i, j}) || tocaBackgroundAdK(A, {i, j}, k)){
                    edges.push_back({i, j});
                }
            }
        }
    }
    return edges;
}

// Ejercicio 5

void cerrarForma(imagen &A, const imagen &B){
    sqPixel sqB = convertirASecuencia(B);
    sqPixel sqA = convertirASecuencia(A);
    int centroB = (B.size() - 1)/2;
    //"centro" la secuencia para que el punto medio sea el (0,0)
    for (int i = 0; i < sqB.size(); ++i) {
        sqB[i] = {sqB[i][0] - centroB, sqB[i][1] - centroB};
    }

    sqPixel dil = dilatacion(sqA, sqB, A.size(), A[0].size());
    sqPixel ero = erosion(dil, sqB, A.size(), A[0].size());
    A = convertirAImagen(ero, A.size(), A[0].size());
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
    int res;
    sqPixel region;
    tie(res, region) = extraerRegion(A, semilla, 8);
    A = convertirAImagen(region, A.size(), A[0].size());

    return res;
}



