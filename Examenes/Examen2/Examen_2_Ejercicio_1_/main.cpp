/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 2 de abril de 2016, 21:48
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int busBin(int *, int, int, int);

int main(int argc, char** argv) {
    int *F, d, post, value;
    F = new int [d];
    cout << "Asigne un tamaño al arreglo";
    cin >> d;
    cout << "Defina los elementos de forma ordenada";
    for (int i = 0; i < d; i++) {
        cout << "Elemento" << i << "\n";
        cin >> F[i];
    }
    cout << "Que valor desea encontrar";
    cin >> value;
    post = busBin(F, value, 0, d - 1);
    if (post >= 0) {
        cout << "El valor es:" << value << "posicion:" << post;
    } else
        cout << "No se encontro el valor.";
    return 0;
}

int busBin(int* vec, int valor, int i, int s) {
    int inferior = i;
    int superior = s;
    int central;
    if (superior <= inferior) return -1;
    central = (superior + inferior) / 2;
    if (vec[central] == valor) return central;
    else if (vec[central] < valor) return busBin(vec, valor, central + 1, superior);
    else if (vec[central] > valor) return busBin(vec, valor, 0, central);
}