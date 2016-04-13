/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 9 de febrero de 2016, 13:15
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
void PideDatosVector(int *vector, int tamanio);
void PideDatosMatriz(int **Matriz, int n, int m);
//void PideDatosMatriz (int **A, int n, int m);
void MatrizPorMatriz(int **A, int **B, int **ProdMatrMatr, int n1, int n2, int m2);
void ProdMatrizVector(int **A, int *v, int *prod, int n, int m);
void ProgramaVector();
void ProgramaMatriz();

int main(int argc, char** argv) {
    ProgramaVector();
    ProgramaMatriz();

    return 0;
}

void PideDatosMatriz(int **A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "a(" << i + 1 << "," << j + 1 << ")=?";
            cin >> A[i][j];
        };
    };
}

/*
void PideDatosMatriz(int **Matriz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "(" << i + 1 << "," << j + 1 << ")=?";
            cin >> Matriz[i][j];
        };
    };
}*/

void MatrizPorMatriz(int **A, int **B, int **ProdMatrMatr, int n1, int n2, int m2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            ProdMatrMatr[i][j] = 0;
            for (int k = 0; k < n2; k++) {
                ProdMatrMatr[i][j] = ProdMatrMatr[i][j] + A[i][k] * B[k][j];
            };
        };
    };
}

void PideDatosVector(int *vector, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << "Dato" << i + 1 << "=?";
        cin >> vector[i];
    };
}

void ProdMatrizVector(int **A, int *v, int *prod, int n, int m) {
    for (int i = 0; i < n; i++) {
        prod [i] = 0;
        for (int j = 0; j < m; j++)
            prod [i] = prod[i] + A [i][j] * v[j];
    };
}

void ProgramaVector() {
    int *v, n, m;

    cout << "¿De que tamaño es el vector?";
    cin >> n;

    v = new int [n];

    cout << "¿Cuales son los datos del vector v?\n";
    PideDatosVector(v, n);

    int *ProdMatrVect, **A;

    ProdMatrVect = new int [n];

    A = new int *[n];

    cout << "La matriz debe tener " << n << "renglones. ¿Cuantas columnas tiene?";
    cin >> m;

    for (int i = 0; i < n; i++)
        A[i] = new int [m];

    PideDatosMatriz(A, n, m);
    ProdMatrizVector(A, v, ProdMatrVect, n, m);

    cout << "El producto de A por v es: \n ";

    for (int i = 0; i < n; i++)
        cout << ProdMatrVect[i] << endl;

}

void ProgramaMatriz() {
    int **A;
    int n1, m1;

    cout << "¿De que tamaño es la matris A" << endl << "renglones =?";
    cin >> n1;
    cout << "columnas =?";
    cin >> m1;

    A = new int *[n1];
    for (int i = 0; i < n1; i++)
        A[i] = new int [m1];

    int **B;
    int n2, m2;

    cout << "De que tamaño es la matriz B" << endl << "renglones =?";
    cin >> n2;
    cout << "columnas =?";
    cin >> m2;

    if (m1 != n2) {
        cout << "Error el numero de columnas de A debe ser igual al de renglones de B";
        //no sirve
        //system("PAUSE");
        //se quita el return 
        //return -1;
        //se agrega un else
    } else {

        B = new int *[n2];

        for (int i = 0; i < n2; i++)
            B[i] = new int [m2];

        int **ProdMatrMatr;
        ProdMatrMatr = new int *[n1];
        for (int i = 0; i < n1; i++)
            ProdMatrMatr[i] = new int[m2];
        cout << "proporciona los datos de la matriz A \n";
        PideDatosMatriz(A, n1, m1);
        cout << "proporciona los datos de la matriz B \n";
        PideDatosMatriz(B, n2, m2);
        MatrizPorMatriz(A, B, ProdMatrMatr, n1, m1, m2);
        cout << "El producto de A por B es : \n";

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {
                cout << ProdMatrMatr[i][j] << "";
            };
        };
        for (int i = 0; i < n1; i++)
            delete A[i];
        delete A;
        for (int i = 0; i < n2; i++)
            delete B[i];
        delete B;
    }
}
