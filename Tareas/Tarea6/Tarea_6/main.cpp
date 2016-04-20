/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 17:05
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
struct caja {
    int valor;
    caja *next;
};

void Pila(int tamano);
void Cola(int tamano);

int main(int argc, char** argv) {
    int tam_datos, opcion;
    bool repetir;

    do {
        cout << "Ingrese la cantidad de cajas que se desea crear: ";
        cin >> tam_datos;
        cout << endl;
        cout << "Elige el tipo de estructura requerida: " << endl;
        cout << endl;
        cout << "1.) Pila" << endl;
        cout << "2.) Cola" << endl;
        cout << "3.) Terminar programa" << endl;

        
        cin >> opcion;

        switch (opcion) {

            case 1:
                Pila(tam_datos);

                repetir = true;
                break;
            case 2:

                Cola(tam_datos);
                repetir = true;
                break;
            case 3:

                cout << "Hasta luego." << endl;
                repetir = false;
                break;

        }
    } while (repetir);


    return 0;
}

void Pila(int tamano) {

    caja *p, *q;

    p = NULL;

    for (int i = 0; i < tamano; i++) {

        q = new caja;
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> q->valor;
        q->next = p;
        p = q;


    }

    int j = 1;
    q = p;

    cout << endl;

    while (q != NULL) {

        cout << "El valor almacenado en Caja #" << j << " es: " << q->valor << endl;
        q = q->next;
        j++;

    };

}

void Cola(int tamano) {

    caja *p, *q, *inicio;

    p = NULL;

    for (int i = 0; i < tamano; i++) {

        q = new caja;
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> q->valor;
        if (p == NULL) inicio = q;
        if (p != NULL) p->next = q;
        p = q;
    }

    int j = 1;
    q = inicio;

    cout << endl;

    while (q != NULL) {

        cout << "El valor almacenado en Caja #" << j << " es: " << q->valor << endl;
        q = q->next;
        j++;
    }


}
