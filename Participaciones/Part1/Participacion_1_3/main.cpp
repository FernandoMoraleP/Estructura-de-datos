/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 20:56
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int A[10][10];
int i, j;

int main(int argc, char** argv) {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cout << "Introduce el valor de A[" << i + 1 << "," << j + 1 << "]\n";
            cin >> A[i][j];
        };
    };
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cout << "A[" << i + 1 << "," << j + 1 << "]=" << A[i][j];
        };
    };
    return 0;
}

