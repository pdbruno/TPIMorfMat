//
//
#include <cstdlib>
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
    if(k==8){
        if(max(abs(p[0] - q[0]), abs(p[1] - q[1])) <= 1){
            res = true;
        } else {
            blacklist.push_back(p);
            for (int i = p[0]-1; i < p[0]+2; ++i) {
                for (int j = p[1]-1; j < p[1]+2; ++j) {
                    if(pixelValidoEncendido(A, {i, j}) && notIn(blacklist, {i, j})){
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
            if(pixelValidoEncendido(A, {p[0]+1, p[1]}) && notIn(blacklist, {p[0]+1, p[1]})){
                blacklist.push_back({p[0]+1, p[1]});
                res |= sonPixelesConectadosViniendoDe(A, {p[0]+1, p[1]}, q, 4, blacklist);
            }

            if(pixelValidoEncendido(A, {p[0]-1, p[1]}) && notIn(blacklist, {p[0]-1, p[1]})){
                blacklist.push_back({p[0]-1, p[1]});
                res |= sonPixelesConectadosViniendoDe(A, {p[0]-1, p[1]}, q, 4, blacklist);
            }
            if(pixelValidoEncendido(A, {p[0], p[1]+1}) && notIn(blacklist, {p[0], p[1]+1})){
                blacklist.push_back({p[0], p[1]+1});
                res |= sonPixelesConectadosViniendoDe(A, {p[0], p[1]+1}, q, 4, blacklist);
            }
            if(pixelValidoEncendido(A, {p[0], p[1]-1}) && notIn(blacklist, {p[0], p[1]-1})){
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

bool notIn(const vector<pixel>& list, const pixel& p){
    int i = 0;
    while (i < list.size() && list[i] != p){
        i++;
    }
    return i == list.size();
}


