//
//
#include <cstdlib>
#include <tuple>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

bool esMatriz(const imagen& A){
    bool res = (A[0].size() > 0);
    for (int i = 0; i < A.size(); ++i) {
        res &= (A[0].size() == A[i].size());
    }
    return res;
}
bool esBinaria(const imagen& A){
    bool res = true;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            res &= (A[i][j] == 0 || A[i][j] == 1);
        }
    }
    return res;
}

bool sonPixelesConectadosViniendoDe(const imagen& A, const pixel& p, const pixel& q, int k, vector<pixel> blacklist){
    bool res = false;
    if(k == 8){
        if(max(abs(p[0] - q[0]), abs(p[1] - q[1])) <= 1){
            res = true;
        } else {
            blacklist.push_back(p);
            for (int i = p[0]-1; i < p[0]+2; ++i) {
                for (int j = p[1]-1; j < p[1]+2; ++j) {
                    if(pixelValidoEncendido(A, {i, j}) && !pertenece(blacklist, {i, j})){
                        blacklist.push_back({i, j});
                        res |= sonPixelesConectadosViniendoDe(A, {i, j}, q, 8, blacklist);
                    }
                }
            }
        }

    } else {
        if(abs(p[0] - q[0]) + abs(p[1] - q[1]) <= 1){
            res = true;
        } else {
            blacklist.push_back(p);
            if(pixelValidoEncendido(A, {p[0]+1, p[1]}) && !pertenece(blacklist, {p[0]+1, p[1]})){
                blacklist.push_back({p[0]+1, p[1]});
                res |= sonPixelesConectadosViniendoDe(A, {p[0]+1, p[1]}, q, 4, blacklist);
            }

            if(pixelValidoEncendido(A, {p[0]-1, p[1]}) && !pertenece(blacklist, {p[0]-1, p[1]})){
                blacklist.push_back({p[0]-1, p[1]});
                res |= sonPixelesConectadosViniendoDe(A, {p[0]-1, p[1]}, q, 4, blacklist);
            }
            if(pixelValidoEncendido(A, {p[0], p[1]+1}) && !pertenece(blacklist, {p[0], p[1]+1})){
                blacklist.push_back({p[0], p[1]+1});
                res |= sonPixelesConectadosViniendoDe(A, {p[0], p[1]+1}, q, 4, blacklist);
            }
            if(pixelValidoEncendido(A, {p[0], p[1]-1}) && !pertenece(blacklist, {p[0], p[1]-1})){
                blacklist.push_back({p[0], p[1]-1});
                res |= sonPixelesConectadosViniendoDe(A, {p[0], p[1]-1}, q, 4, blacklist);
            }
        }
    }
    return res;
}

bool pixelValidoEncendido(const imagen &A, const pixel& p){
    return (0 <= p[0] && 0 <= p[1] && A.size() > p[0] && A[0].size() > p[1] && A[p[0]][p[1]] == 1);
}

bool pertenece(const vector<pixel>& list, const pixel& p){
    int i = 0;
    while (i < list.size() && list[i] != p){
        i++;
    }
    return i < list.size();
}

bool esBorde(const imagen &A, const pixel& p){
    return (p[0] == 0 || p[0] == A.size()-1 || p[1] == 0 || p[1] == A[0].size()-1);
}
bool tocaBackgroundAdK(const imagen &A, const pixel& p, int k){
    bool res = false;
    if(A[p[0] + 1][p[1]] == 0 || A[p[0] - 1][p[1]] == 0 || A[p[0]][p[1] + 1] == 0 || A[p[0]][p[1] - 1] == 0){
        res = true;
    }
    if(k == 8){
        if(A[p[0] + 1][p[1] + 1] == 0 || A[p[0] - 1][p[1] + 1] == 0 || A[p[0] + 1][p[1] - 1] == 0 || A[p[0] - 1][p[1] - 1] == 0){
            res = true;
        }
    }
    return res;
}

sqPixel convertirASecuencia(const imagen &A){
    sqPixel sqA;

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j]==1){
                sqA.push_back({i, j});
            }
        }
    }
    return sqA;
}

imagen convertirAImagen(const sqPixel &A, int n, int m){
    imagen res(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = pertenece(A, {i, j}) ? 1 : 0;
        }
    }
    return res;
}


sqPixel interseccion(const sqPixel &A, const sqPixel &B){
    sqPixel res;
    for (int i = 0; i < A.size(); ++i) {
        if(pertenece(B, A[i])){
            res.push_back(A[i]);
        }
    }
    return res;
}

sqPixel quitarPixelesRepetidos(const sqPixel &A){
    sqPixel res;
    vector<int> posRedun;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i+1; j < A.size(); ++j) {
            if(A[i] == A[j]){
                posRedun.push_back(j);
            }
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        if(!perteneceInt(posRedun, i)){
            res.push_back(A[i]);
        }
    }
    return res;
}

sqPixel dilatacion(const sqPixel &A, const sqPixel &B, int n, int m){
    sqPixel res;
    sqPixel Bdesplazado;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Bdesplazado = desplazar(B, {i, j});
            if(hayInterseccion(A, Bdesplazado)){
                res.push_back({i, j});
            }
        }
    }
    res.insert( res.end(), A.begin(), A.end() );
    return quitarPixelesRepetidos(res);
}

sqPixel erosion(const sqPixel &A, const sqPixel &B, int n, int m){
    sqPixel res;
    sqPixel Bdesplazado;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(pertenece(A, {i, j})) {
                Bdesplazado = desplazar(B, {i, j});
                if (contenido(A, Bdesplazado, n, m)) {
                    res.push_back({i, j});
                }
            }
        }
    }
    return res;
}

sqPixel desplazar(const sqPixel &B, const pixel &p){
    sqPixel res;
    for (int i = 0; i < B.size(); ++i) {
        res.push_back({B[i][0] + p[0], B[i][1] + p[1]});
    }
    return res;
}

bool hayInterseccion(const sqPixel &A, const sqPixel &B){
    bool res = false;
    for (int i = 0; i < A.size(); ++i) {
        res |= pertenece(B, A[i]);
    }
    return res;
}

bool contenido(const sqPixel &contenedor, const sqPixel &contenido, int n, int m){
    bool res = true;
    for (int i = 0; i < contenido.size(); ++i) {
        if(0 <= contenido[i][0] && 0 <= contenido[i][1] && n > contenido[i][0] && m > contenido[i][1]){
            res &= pertenece(contenedor, contenido[i]);
        }
    }
    return res;
}
bool iguales(const sqPixel &A, const sqPixel &B){
    bool res = true;
    if(A.size() != B.size()){
        res = false;
    } else {
        for (int i = 0; i < A.size(); ++i) {
            res &= (pertenece(B, A[i]) && pertenece(A, B[i]));
        }
    }
    return res;
}



tuple <int, sqPixel> extraerRegion(const imagen &A, const pixel &semilla, int k){
    sqPixel dilPrev, interPrev, dilNext, interNext;
    sqPixel sqA = convertirASecuencia(A);
    sqPixel sqB;
    if(k==8){
        sqB = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    } else {
        sqB = {{-1,0},{0,-1},{0,0},{0,1},{1,0}};
    }

    interPrev = {semilla};
    dilNext = dilatacion(interPrev, sqB, A.size(), A[0].size());
    interNext = interseccion(dilNext, sqA);

    int i = 1;
    while (!iguales(interPrev, interNext)){
        dilPrev = dilNext;
        interPrev = interNext;
        dilNext = dilatacion(interPrev, sqB, A.size(), A[0].size());
        interNext = interseccion(dilNext, sqA);
        i++;
    }

    return make_tuple(i, interNext);
}

vector<sqPixel> quitarRepetidos(const vector<sqPixel> &A){
    vector<sqPixel> res;
    vector<int> posRedun;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i+1; j < A.size(); ++j) {
            if(iguales(A[i], A[j])){
               posRedun.push_back(j);
            }
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        if(!perteneceInt(posRedun, i)){
            res.push_back(A[i]);
        }
    }
    return res;
}


bool perteneceInt(const vector<int>& list, const int& x){
    int i = 0;
    while (i < list.size() && list[i] != x){
        i++;
    }
    return i < list.size();
}
