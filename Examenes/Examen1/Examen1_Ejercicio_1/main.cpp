/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: FerMoral
 *
 * Created on 27 de febrero de 2016, 16:27
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float *x, *y, *z;
    float m, n;
    x = y = &m;
    z = &n;
    m = 45;
    n = 10;
    m = 3 * *y + 2 * *z;
    
    cout << "M vale:" << m << "\n\n\tN vale :" << n;
    return 0;
}

