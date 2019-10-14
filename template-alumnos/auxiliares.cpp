//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

bool esMatriz(const imagen &A){
    int rows = A[0].size();
    bool res;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == rows){
            res &= true;
        }else{
            res &= false;
        }
    }
    return res;
}

bool esBinaria(const imagen &A){
    bool res;
    for (int i = 0; i < A.size; ++i) {
        for (int j = 0; j < A[i].size; ++j) {
            if (A[i][j] == 0 || A[i][j] == 1){
                res &= true;
            }else{
                res &= false;
            }

        }
    }
    return res;
}


