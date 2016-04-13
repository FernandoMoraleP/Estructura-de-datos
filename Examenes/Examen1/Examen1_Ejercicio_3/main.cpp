/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 27 de febrero de 2016, 17:50
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * falta porcentaje
 */
int main(int argc, char** argv) {

    struct venta {
        char nombre[30];
        float precio;
        double cantidad;
        venta *enlace;
    };

    int nue= 1;
    venta *inicio, *opcional;

    inicio = NULL;

    cout << "Enpiesa a registrar tus ventas" << endl;
    cout << endl;

    do {
        opcional = new venta;
        cout << "Nombre articulo: ";
        cin >> opcional->nombre;
        cout << "Precio articulo: ";
        cin >> opcional->precio;
        cout << "Cantidad articulo: ";
        cin >> opcional->cantidad;
        opcional->enlace = inicio;
        inicio = opcional;
        cout << "Desea registrar otra venta? (1 - Si / 0 - No) : ";
        cin >> nue;
        cout << endl;

    } while (nue != 0);
    cout << "Este es el numero de ventas realizadas" << endl;
    cout << endl;

    opcional = inicio; 

    while (opcional != NULL) {

        cout << "Nombre: " << opcional->nombre << endl;
        cout << "Precio: " << opcional->precio << endl;
        cout << "Cantidad: " << opcional->cantidad << endl;
        cout << endl;
        opcional = opcional->enlace;

    };
    while (opcional != NULL) {
        inicio = opcional->enlace;
        delete opcional;
        opcional = inicio;
    };
    return 0;
}

