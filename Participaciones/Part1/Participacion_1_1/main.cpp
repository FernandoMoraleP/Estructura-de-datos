/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 20:11
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *pointer_int, a, x = 7;
    float *pointer_float, b, y = 4.0;
    //el apuntador a entero se carga con la direccion de x
    pointer_int = &x;
    cout << "el contenido de x es " << x << endl;

    cout << "la direccion de x es : " << &x << endl;
    cout << "pointer_int contiene : " << pointer_int << endl;
    cout << "pointer_int apunta a : " << pointer_int << endl;
    //el apuntador a float se carga con la direccion de y
    pointer_float = &y;
    cout << "el contenido de y es " << y << endl;
    cout << "la direccion de y es : " << &y << endl;
    cout << "pointer float contiene : " << pointer_float << endl;
    cout << "pointer float apunta a : " << pointer_float << endl;
    //a se carga con lo que apunta pointer int
    a = *pointer_int;
    //b se carga con lo que apunta pointer float;
    b = *pointer_float;
    //desplegar a y b
    cout << "a = " << a << endl << "b = " << b;

    return 0;
}

