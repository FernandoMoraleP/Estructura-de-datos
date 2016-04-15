/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 14 de abril de 2016, 19:49
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    double *a, *b;
    cout << "De que tamaño sera el arreglo A, solo numeros enteros \n";
    cin >> n;

    a = new double [n];
    b = new double [n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese los valores del arreglo A, para la posición " << i << ": " << "\n";
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        b[i] = a[i] * 2.00;
    }

    cout << "Valores en el Arreglo B: \n";

    for (int i = 0; i < n; i++) {
        cout << "Posición" << i << ": " << b[i] << "\n";
    }
    return 0;
}

