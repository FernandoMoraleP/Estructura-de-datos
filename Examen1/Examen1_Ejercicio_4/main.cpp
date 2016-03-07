/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 28 de febrero de 2016, 23:24
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct s_caja {
    int elemento;
    s_caja *siguiente;
};

s_caja *hacer_caja();
void Push(s_caja *p);
s_caja *Pop();
bool otra_caja();

s_caja *inicio, *caja_inicial, *caja_aux;

int main(int argc, char** argv) {
    s_caja *p;
    p = NULL;
    int j = 1;
    while (otra_caja())
        Push(hacer_caja());
    while ((p = Pop()) != NULL) {
        cout << "El elemento #" << j << ": " << p->elemento << endl;
        delete p;
        j++;
    }



}

s_caja *hacer_caja() {

    s_caja *p;
    p = new s_caja;
    if (p == NULL) return NULL;
    cout << "Ingrese el elemento: ";
    cin >> p->elemento;
    return p;

}

void Push(s_caja *p) {
    if (p == NULL) return;
    p->siguiente = inicio;
    inicio = p;
}

s_caja *Pop() {
    s_caja *p;
    p = inicio;
    if (inicio != NULL) inicio = inicio->siguiente;
    return p;
}

bool otra_caja() {
    int otre;
    cout << " Quieres hacer otra caja? (1 - Si, 0 - No): ";
    cin >> otre;
    return otre != 0;

}

