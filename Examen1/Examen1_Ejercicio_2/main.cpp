/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 27 de febrero de 2016, 17:45
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    double *G, *Q = NULL;

    cout << "Para iniciar asigna un numero a n \n";
    cin >> n;

    G = new double [n];
    Q = new double [n * 2];
    cout << "Estas operando en el Arreglo G";
    for (int i = 0; i < n; i++) {

        cout << "¿Cual es el valor para la posición " << i << "?: \n";
        cin >> G[i];
        G[i] = G[i] * 3;

    }
    cout << "Estas operando en el Arreglo Q";

    for (int i = 0; i < n * 2; i++) {

        cout << "¿Cual es el valor para la posición " << i << "?:\n ";
        cin >> Q[i];
        Q[i] = Q[i] + 1;
    }

    cout << "Al multiplicar los valores del primer arreglo por 3 ahora son por:" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Para G" << i << ": " << G[i];
        cout << endl;

    }

    cout << "Al sumar los valores del segundo arreglo a 1 ahora son:" << endl;

    for (int i = 0; i < n * 2; i++) {

        cout << "Para Q" << i << ": " << Q[i];
        cout << endl;

    }
    for (int i = 0; i < n; i++)
        G[i] = 0;
    for (int i = 0; i < n * 2; i++)
        Q[i] = 0;

    delete [] G;
    delete [] Q;
    return 0;
}