/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 26 de abril de 2016, 17:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Laestructura.h"

/*const int DESC_SIZE = 21;

struct inventoryData

{
        char desc[DESC_SIZE]; 
        int quantity; 
        double wholesale;
        double retail;
        char date[DATE_SIZE];

};*/


using namespace std;

void addRecord(fstream &);
void viewRecord(fstream &);
void changeRecord(fstream &);
int menu();

int main()
{
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    if (dataFile.fail())
    {
        dataFile.open("inventory.dat", ios::out);
        dataFile.close();
    }

    for (;;)
    {
        int selection = menu();
        if (selection == 4)
            break;

        switch (selection)
        {
        case 1:
            viewRecord(dataFile);
            break;
        case 2:
            addRecord(dataFile);
            break;
        case 3:
            changeRecord(dataFile);
            break;
        default:
            cout << "Invalid - Please use 1 to 4" << endl;
            break;
        }
    }

    return 0;
}

void addRecord(fstream &notused){
    fstream file("inventory.dat", ios::in | ios::out | ios::app | ios::binary);
    inventoryData item;

    cout << "Ingrese los siguientes datos." << endl;
    cout << "Descripcion: ";
    cin.ignore();
    cin.getline(item.desc, DESC_SIZE);

    cout << "Cantidad: ";
    cin >> item.quantity;

    cout << "Precio: ";
    cin >> item.wholesale;

    cout << "Precio de remate: ";
    cin >> item.retail;

    cout << "Fecha: ";
    cin >> item.date;

    file.write(reinterpret_cast<char *>(&item), sizeof(item));

    return;
}

void viewRecord(fstream &notused){
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    inventoryData item;
    while (dataFile)
    {
        dataFile.read(reinterpret_cast<char*>(&item), sizeof(item));
        cout << "Descripcion: " << item.desc << endl;
        cout << "Cantidad: " << item.quantity << endl;
        cout << "Precio: " << item.wholesale << endl;
        cout << "Precio de remate: " << item.retail << endl;
        cout << "Fecha " << item.date << endl;
        cout << endl;
    }
}


void changeRecord(fstream &file){
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);

    inventoryData item;
    int recordNumber;

    cout << "Elija el producto a modificar." << endl;
    cin >> recordNumber;
    dataFile.seekg(recordNumber * sizeof(item), ios::beg);
    dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));
    cout << "Descripcion: " << item.desc << endl;
    cout << "Cantidad: " << item.quantity << endl;
    cout << "Precio: " << item.wholesale << endl;
    cout << "Precio de remate: " << item.retail << endl;
    cout << "Fecha " << item.date << endl;
    cout << endl;

    cout << "Ingrese los nuevos datos del producto :\n";
    cout << "Descripcion: ";
    cin.ignore();
    cin.getline(item.desc, DESC_SIZE);
    cout << "Cantidad: ";
    cin >> item.quantity;
    cout << "Cantidad: ";
    cin >> item.quantity;
    cout << "Precio: ";
    cin >> item.wholesale;
    cout << "Precio de remate: ";
    cin >> item.retail;
    cout << "Fecha";
    cin >> item.date;

    dataFile.seekp(recordNumber * sizeof(item), ios::beg);
    dataFile.write(reinterpret_cast<char *>(&item), sizeof(item));

}

int menu()
{
    int menuSelection = 0;

    cout << fixed << showpoint << setprecision(2);
    cout << " Inventario" << endl;
    cout << "1 - Ver el inventario" << endl;
    cout << "2 - Agregar un producto" << endl;
    cout << "3 - Editar un producto " << endl;
    cout << "4 - Terminar el programa" << endl;

    cin.clear();
    fflush(stdin);
    cin >> menuSelection;

    return menuSelection;
}