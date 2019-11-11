//
// Created by pato on 18/10/19.
//

#include "gtest/gtest.h"
#include "../ejercicios.h"
#include "../auxiliares.h"

TEST(cerrarFormaTest, soloUnPixelPrendidoConElemSinCentro) {
    imagen A = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };
    imagen B = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0},
    };
    imagen esperada = {
            { 0, 0, 0, 0, 1, 1 },
            { 0, 1, 0, 1, 1, 1 },
            { 0, 1, 1, 1, 1, 1 },
            { 0, 0, 1, 1, 1, 0 },
            { 0, 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0, 1 },
};

cerrarForma(A,B);

EXPECT_EQ(esperada, A);
}

TEST(cerrarFormaTest, cierreConElementoSinCentroActivadoYConDosPixelesActivados) {
    imagen A = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
    };
    imagen B = {
            {0, 1, 0},
            {0, 0, 0},
            {0, 1, 0},
    };
    imagen esperada = {
            { 0, 0, 0, 0, 1, 1 },
            { 0, 1, 0, 1, 1, 1 },
            { 0, 1, 1, 1, 1, 1 },
            { 0, 0, 1, 1, 1, 0 },
            { 0, 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 1, 1, 0, 0, 0, 1 },
    };

    cerrarForma(A,B);

    EXPECT_EQ(esperada, A);
}