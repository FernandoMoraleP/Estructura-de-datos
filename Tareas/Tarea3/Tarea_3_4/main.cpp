/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 14 de abril de 2016, 20:42
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int n, i;
    char cr[2];

    struct s_materia {
        char nombre[30];
        float calific;
    };

    s_materia *materias;

    cout << "Indique el tamaño del arreglo ? \n";
    cin >> n;

    materias = new s_materia[n];

    if (materias == NULL)
        return -1;

    for (i = 0; i < n; i++) {
        cin.getline(cr, 2);
        cout << "Cuál es el nombre de la materia\t" << i + 1 << "?\n";
        cin.getline(materias[i].nombre, 30);
        cout << "Idique la calificación\n";
        cin >> materias[i].calific;
    };

    for (i = 0; i < n; i++) {
        cout << "En " << materias[i].nombre << " tienes: " << materias[i].calific <<" de calificacion.\n";
    };
    delete [] materias;
    return 0;
}

