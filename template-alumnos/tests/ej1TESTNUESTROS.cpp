#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida2) {
imagen img = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 1},
        {1, 0, 0},
        {1, 0, 0},
        {1, 1, 2},
};
EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida3) {
    imagen img = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 0, 1},
            {1, 0, 0, 0},
            {1, 0, 0},
            {1, 1, 0},
    };
    EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida4) {
    imagen img = {
            {0, 1, 0, 0, 1, 3, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 2, 3, 1, 0, 2, 6, 1},
    };
    EXPECT_FALSE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida5) {
    imagen img = {
            {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
    };
    EXPECT_TRUE(esImagenValida(img));
}

TEST(esImagenValidaTest, ImagenNoCuadradaEsValida6) {
    imagen img = {
            {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {},
            {1, 0, 0, 0, 1, 1, 1, 1, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
    };
    EXPECT_FALSE(esImagenValida(img));
}