/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 13 de abril de 2016, 15:55
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int a = 17;
    int b = 26;
    int c;

    int *ptr1 = &a;
    int *ptr2 = &b;

    int *ptr3 = &c;



    cout << "Resultado de la suma: " << *ptr1 + *ptr2 ;
    return 0;
}

