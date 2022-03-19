#include <iostream>

int zamenaColumn(int[3], int[3][3], int);

int matrixDeltaFind(int[3][3]);


int main() {

    int uravnenie[3][3] = {{1, 2,  -3},
                           {3, 2,  -4},
                           {2, -1, 0}};
    int reshenie[3] = {1, 0, -1};
    int matrixMain[3][3];

//    matrixMain[3][3] = uravnenie[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrixMain[i][j] = uravnenie[i][j];
        }
    }
    int matrixDelta = matrixDeltaFind(matrixMain);


    int deltaMatrix1[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            deltaMatrix1[i][j] = matrixMain[i][j];
        }
    }
    zamenaColumn(reshenie,deltaMatrix1, 0);
    int matrixDelta1 = matrixDeltaFind(deltaMatrix1);

    int deltaMatrix2[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            deltaMatrix2[i][j] = matrixMain[i][j];
        }
    }
    zamenaColumn(reshenie,deltaMatrix2, 1);
    int matrixDelta2 = matrixDeltaFind(deltaMatrix2);

    int deltaMatrix3[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            deltaMatrix3[i][j] = matrixMain[i][j];
        }
    }
    zamenaColumn(reshenie,deltaMatrix3, 2);
    int matrixDelta3 = matrixDeltaFind(deltaMatrix3);

    std::cout << "Главная дельта: " << matrixDelta << std::endl;
    std::cout << "Дельта 1: " << matrixDelta1 << std::endl;
    std::cout << "Дельта 2: " << matrixDelta2 << std::endl;
    std::cout << "Дельта 3: " << matrixDelta3 << std::endl;

    int x1 = matrixDelta1 / matrixDelta;
    int x2 = matrixDelta2 / matrixDelta;
    int x3 = matrixDelta3 / matrixDelta;

    std::cout << "X: " << x1 << std::endl;
    std::cout << "Y: " << x2 << std::endl;
    std::cout << "Z: " << x3 << std::endl;

    return 0;
}

int matrixDeltaFind(int matrixMain[3][3]) {
    int delta = matrixMain[0][0] * matrixMain[1][1] * matrixMain[2][2] +
                matrixMain[0][1] * matrixMain[1][2] * matrixMain[2][0] +
                matrixMain[0][2] * matrixMain[1][0] * matrixMain[2][1] -
                matrixMain[0][2] * matrixMain[1][1] * matrixMain[2][0] -
                matrixMain[0][1] * matrixMain[1][0] * matrixMain[2][2] -
                matrixMain[0][0] * matrixMain[1][2] * matrixMain[2][1];
    return delta;
}

int zamenaColumn(int matrixFromChange[3], int matrixToChange[3][3], int column) {
    matrixToChange[0][column] = matrixFromChange[0];
    matrixToChange[1][column] = matrixFromChange[1];
    matrixToChange[2][column] = matrixFromChange[2];
    return 0;
}