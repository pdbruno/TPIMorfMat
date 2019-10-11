//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

bool esMatriz(const imagen& img){
    bool res = (img[0].size() > 0);
    for (int i = 0; i < img.size(); ++i) {
        res &= (img[0].size() == img[i].size());
    }
    return res;
}
bool esBinaria(const imagen& img){
    bool res = true;
    for (int i = 0; i < img.size(); ++i) {
        for (int j = 0; j < img[0].size(); ++j) {
            res &= (img[i][j] == 0 || img[i][j] == 1);
        }
    }
    return res;
}

