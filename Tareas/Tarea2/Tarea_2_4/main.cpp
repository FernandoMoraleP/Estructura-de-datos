/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 12 de abril de 2016, 21:24
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int arreglo[10] = {1, 2, 3, 4, 4, 7, 8, 9, 5, 8};

    for (int i = 0; i < 10; i++) {
        //no, aqui imprimes valores, no direcciones de memoria
        int *ptr = &arreglo[i];
        cout << "Direccion arreglo[" << i << "]:" << *ptr << endl;
    }
        return 0;
    }

