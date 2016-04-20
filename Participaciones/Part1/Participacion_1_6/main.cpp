/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 21:52
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
float promedio(float arreglo[]);

int main(int argc, char** argv) {
    
    float calific[7];
    for (int i = 0; i < 7; i++) {
        cout << "\n Cual es la calificacion numero" << i + 1;
        cin >> calific[i];
    };
    cout << "Tu promedio es:" << promedio(calific);
    return 0;
}

float promedio(float arreglo[]) {
    float suma = 0;
    for (int j = 0; j < 7; j++) suma = suma + arreglo[j];
    return ( suma / 7);
};
