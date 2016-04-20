/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 21:34
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
double F_a_Centigrados(double f);
int main(int argc, char** argv) {
        double farenheit;
        cout << " Programa para convertir grados Farenheit a centigrados \n ";
        cout << " Cual es la temperatura en grados Farenheit?";
        cin >> farenheit;
        cout << farenheit << " equivale a: " << F_a_Centigrados(farenheit) << " centigrados";
        return 0;
    }

double F_a_Centigrados(double f) {
        return ( ((f - 32.0) * 5.0) / 9.0);
    };