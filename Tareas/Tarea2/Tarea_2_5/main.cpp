/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 12 de abril de 2016, 21:43
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int arreglo[15];
    int *ptr1 = &arreglo[8];
    int *ptr2 = &arreglo[12];

    for (int i = 0; i < 15; i++) {

        arreglo[i] = rand();
    }
    cout << "Ubicacion en memoria de la posicion [8]: " << *ptr1 << "\n";
    cout << "Ubicacion en memoria de la posicion [12]: " << *ptr2 << "\n";
    cout << "Valor en la posicion [8]:" << ptr1 << "\n";
    cout << "Valor en la posicion [12]:" << ptr2 << "\n";

    return 0;
}

