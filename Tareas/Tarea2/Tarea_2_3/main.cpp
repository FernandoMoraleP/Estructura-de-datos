/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 12 de abril de 2016, 20:52
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double x = 30, y = 45;
    double *ptr1, *ptr2;
    double ** ptr3;
    ptr1 = &x;
    ptr2 = &y;
    ptr3 = &ptr1;
    x = *ptr1 + x;
    *ptr2 = 3 * y + 2 * **ptr3;
    *ptr3 = &y;
    ptr3 = &ptr2;
    *ptr3 = &x;
    **ptr3 = *ptr2 - *ptr1*x;
    cout << "x vale:" << x << "y vale:" << y;
    return 0;
}

