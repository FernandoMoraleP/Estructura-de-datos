/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laestructura.h
 * Author: YANET
 *
 * Created on 26 de abril de 2016, 21:00
 */

#ifndef LAESTRUCTURA_H
#define LAESTRUCTURA_H

const int DESC_SIZE = 21;

struct inventoryData

{
        char desc[DESC_SIZE]; 
        int quantity; 
        double wholesale; 
        double retail; 
        int date; 

};


#endif /* LAESTRUCTURA_H */

