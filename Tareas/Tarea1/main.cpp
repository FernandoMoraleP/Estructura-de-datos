/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fernando Morales Prado.
 *
 * Created on 19 de enero de 2016, 15:40
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int suma = 0;
    int numeros;
    int ingreso, n;

    cout << "¿Cuantos numeros quiere sumar?\n";
    cin>>numeros;
    for (n = 1; n <= numeros; n++) {
        cout << "Ingrese los numeros " << n << ":";
        cin>>ingreso;
        suma = suma + ingreso;
    }
    cout << "El resultado de la suma es:" << suma;

}

