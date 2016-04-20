/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 21:13
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int **A;
int i, j, n, m;

int main(int argc, char** argv) {
    cout << "Número de renglones: ";
    cin >> n;
    cout << "Número de columnas: ";
    cin >> m;
    A = new int * [n];
    for (i = 0; i < n; i++)
        A[i] = new int[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << "Introduce el valor de A[" << i + 1 << "," << j + 1 << "]\n";
            cin >> A[i][j];
        };
    };
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << "A[" << i + 1 << "," << j + 1 << "]=" << A[i][j];
        };
    };
    for (i = 0; i < n; i++)
        delete [] A[i];
    delete [] A;
    return 0;
}

