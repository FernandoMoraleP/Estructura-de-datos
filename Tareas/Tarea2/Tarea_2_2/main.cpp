/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 12 de abril de 2016, 20:49
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *a, *b, *c;
    int i, j;
    a = b = &i;
    c = &j;
    *b = 4;
    *c = 3;
    *a = 2 * *b + *c;
    cout << "\n I vale:" << i << "\n\n\t J vale :" << j;

    return 0;
}

