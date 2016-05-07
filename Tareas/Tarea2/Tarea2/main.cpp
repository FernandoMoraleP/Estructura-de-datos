/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 11 de abril de 2016, 10:52
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {

    int a;
    int *a_ptr;
    a_ptr = &a;
    *a_ptr = 24;
    cout << "El resultado es:" << a << "\n";

    return 0;
}

