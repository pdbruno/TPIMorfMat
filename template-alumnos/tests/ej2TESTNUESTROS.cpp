#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy4EstanConectadosAdy4v2) {
imagen img = {
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0},
};
pixel p = {0, 0};
pixel q = {0, 6};
EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy4EstanConectadosAdy4v3) {
    imagen img = {
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 2},
            {1, 1, 0, 1, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 6};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy4EstanConectadosAdy4v4) {
    imagen img = {
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 1},
            {1, 1, 0, 1, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 1},
            {1, 1, 0, 1, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0, 1, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {9, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesEnCaminoLargoAdy8EstanConectadosAdy8v1) {
    imagen img = {
            {1, 0, 0, 0, 0, 0, 1, 0},
            {0, 1, 0, 1, 0, 0, 1, 1},
            {0, 0, 1, 1, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 1},
            {0, 0, 0, 0, 1, 1, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 1, 0, 0},
            {1, 1, 0, 0, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 1, 1, 1},
            {1, 0, 1, 0, 0, 1, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {9, 0};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 8));
}