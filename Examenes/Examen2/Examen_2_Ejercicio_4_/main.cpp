/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 4 de abril de 2016, 0:33
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
struct s_caja {
    int elemento;
    s_caja *hijo_izq;
    s_caja *hijo_der;
};

bool hay_hijo(int n) {
    char *lado[2] = {"izq", "der"};
    cout << " hay hijo " << lado[n] << "?";
    char c;
    cin >> c;
    return (c == 's' || c == 'S');
}

s_caja * ConstruyeArbol() {
    s_caja * raiz;
    raiz = new s_caja;
    cout << " dato? ";
    cin >> raiz->elemento;
    raiz->hijo_izq = NULL;
    raiz->hijo_der = NULL;
    if (hay_hijo(0))
        raiz->hijo_izq = ConstruyeArbol();
    if (hay_hijo(1))
        raiz->hijo_der = ConstruyeArbol();
    return raiz;
}

void DestruyeArbol(s_caja *p);
void imprimeArbol_preOrden(s_caja * p);
void imprimeArbol_postOrden(s_caja * p);
void imprimeArbol_entreOrden(s_caja * p);

int main(int argc, char** argv) {
    s_caja *inicio;
    int opcion;
    cout << "Ingresa los nodos del arbol en pre-orden \n" << "Para cada nodo indicar si tiene un subarbol izq. y der" << " ""S"" para indicar que si, cualquier otra tecla para" << " indicar que no \n";
    inicio = ConstruyeArbol();
    while (true) {
        do {
            cout << " Para imprimir el arbol, indica el recorrido: \n" << " 1: pre-orden: raíz-izq-der \n" << " 2: post-orden: izq-der-raíz \n" << " 3: entre-orden: izq-raíz-der \n" << " 4: salir \n";
            cin >> opcion;
        } while (opcion < 1 || opcion > 4);
        switch (opcion) {
            case 1: cout << " El arbol en pre-orden es: \n";
                imprimeArbol_preOrden(inicio);
                break;
            case 2: cout << " El árbol en post-orden es: \n";
                imprimeArbol_postOrden(inicio);
                break;
            case 3: cout << " El arbol en entre-orden es: \n";
                imprimeArbol_entreOrden(inicio);
                break;
            case 4: DestruyeArbol(inicio);
        };
    };
    return 0;
}

void DestruyeArbol(s_caja *p) {
    if (p == NULL)
        return;
    DestruyeArbol(p->hijo_izq);
    DestruyeArbol(p->hijo_der);
    delete p;
}

void imprimeArbol_preOrden(s_caja * p) {
    if (p == NULL) return;
    cout << " " << p->elemento << ", ";
    imprimeArbol_preOrden(p->hijo_izq);
    imprimeArbol_preOrden(p->hijo_der);
}

void imprimeArbol_postOrden(s_caja * p) {
    if (p == NULL)
        return;
    imprimeArbol_postOrden(p->hijo_izq);
    imprimeArbol_postOrden(p->hijo_der);
    cout << " " << p->elemento << ", ";
}

void imprimeArbol_entreOrden(s_caja * p) {
    if (p == NULL) return;
    imprimeArbol_entreOrden(p->hijo_izq);
    cout << " " << p->elemento << ", ";
    imprimeArbol_entreOrden(p->hijo_der);
}