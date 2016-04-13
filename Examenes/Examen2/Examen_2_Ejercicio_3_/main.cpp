/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 4 de abril de 2016, 1:12
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

void imprimeArbol_preOrden(s_caja * p) {
    if (p == NULL)
        return;
    cout << " " << p->elemento << ", ";
    imprimeArbol_preOrden(p->hijo_izq);
    imprimeArbol_preOrden(p->hijo_der);
}

s_caja * BusquedaBinaria(s_caja *p, int num) {
    if (p == NULL)
        return NULL;
    if (num == p->elemento) {
        return p;
        cout << &p << endl;
    }
    if (num < p->elemento)
        return BusquedaBinaria(p->hijo_izq, num);
    if (num > p->elemento)
        return BusquedaBinaria(p->hijo_der, num);
}

int main(int argc, char** argv) {
    s_caja *inicio;
    int numero;
    cout << "Ingresa los nodos del arbol en pre-orden \n";
    cout << "Para cada nodo indicar si tiene un subarbol izq. y der"
            << " ""S"" para indicar que si, cualquier otra tecla para"
            << " indicar que no \n";
    inicio = ConstruyeArbol();
    while (true) {
        cout << "¿Que numero deseas buscar? \n";
        cin >> numero;
        BusquedaBinaria(inicio, numero);
        cout << "tu arbol en pre-orden fue: \n";
        imprimeArbol_preOrden(inicio);
        break;
    }
    return 0;
}
