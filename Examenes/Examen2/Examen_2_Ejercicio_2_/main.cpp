/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 3 de abril de 2016, 13:55
 */

#include <cstdlib>
#include <iostream>


using namespace std;

/*
 * 
 */
struct s_Datcaja {
    int dato;
    s_Datcaja *siguiente;
};
s_Datcaja *fir_box = NULL, *las_box = NULL;

bool otra_caja() {
    char c;
    cout << "\n !Si deseas una nueva caja presiona s sino S¡ \n";
    cin >> c;
    return c == 's' || c == 'S';

};

s_Datcaja *hacer_caja() {
    s_Datcaja *q;
    q = new s_Datcaja;
    if (q == NULL)
        return NULL;

    int element;
    cout << "Ingrese el dato a almacenar.";
    cin >> element;
    q->dato = element;
    q->siguiente = NULL;

    return q;
}

void Formar(s_Datcaja *q);
void printList(s_Datcaja *q);
void printList1(s_Datcaja *q);

int main(int argc, char** argv) {
    s_Datcaja *q;
    int element;
    while (otra_caja())
        Formar(hacer_caja());

    int opcion;

    do {
        cout << "¡De que forma deseas imprimir la lista?" << endl << "0: Para orden (FIFO)\n" << "1: Para orden inverso\n";
        cin >> opcion;

    } while (opcion < 0 || opcion > 1);
    if (opcion == 0) {
        cout << "Esta es la lista en Orden (FIFO):\n";
        printList(fir_box);
    } else {
        cout << "Esta es la lista inversa:\n";
        printList1(fir_box);
    };
    while (fir_box != NULL) {
        q = fir_box->siguiente;
        delete fir_box;
        fir_box = q;
    }
    return 0;
}

void Formar(s_Datcaja *q) {
    if (q == NULL)
        return;
    q->siguiente = NULL;
    if (las_box == NULL)
        fir_box = q;
    else
        las_box->siguiente = q;
    las_box = q;
}

void printList(s_Datcaja *q) {
    if (q == NULL) {
        cout << "No hay datos a mostrar. \n";
        return;
    };
    cout << q->dato << endl;
    q = q->siguiente;
    printList(q);
}

void printList1(s_Datcaja *q) {
    if (q == NULL) {
        cout << "No hay datos a mostrar. \n";
        return;
    };
    printList1(q->siguiente);
    cout << q->dato << endl;

}