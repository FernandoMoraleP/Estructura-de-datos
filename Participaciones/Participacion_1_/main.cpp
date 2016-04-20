/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 19:44
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double a = 100, b = 200;
    double *p1, *p2;
    double ** p3;
    p1 = &a;
    p2 = &b;
    p3 = &p2;
    a = *p1 + (2 * b);
    *p2 = (3 * a) + (3 * **p3);
    *p3 = &b;
    p3 = &p2;
    *p3 = &a;
    **p3 = *p2 - (*p1 * b);
    cout << "a vale:" << a << "\nb vale:" << b;
    return 0;
}

