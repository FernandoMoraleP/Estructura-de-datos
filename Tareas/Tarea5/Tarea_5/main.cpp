/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: YANET
 *
 * Created on 19 de abril de 2016, 16:31
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void addRecord(fstream &);
void viewRecord(fstream &);
void changeRecord(fstream &);
int menu();

const int DESC_SIZE = 21;
const int DATE_SIZE = 11;

struct inventoryData

{
        char desc[DESC_SIZE]; //Desc up to 20 chars
        int quantity; //Item quantity
        double wholesale; //Item wholsale Cost
        double retail; //Item retail Cost
        char date[DATE_SIZE]; //Date able to hold info up to xx/xx/xxxx

};


int main()
{
    int selection;
    int recordNumber;

    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    if (dataFile.fail())
    {
        // The file does not exist, so create it.
        dataFile.open("inventory.dat", ios::out);
    }


    selection = menu();

    while (selection != 4)
    {
        switch (selection)
            {
                case 1:
                    {
                         viewRecord(dataFile);
                         break;
                    }
                case 2:
                {
                          addRecord(dataFile);
                          break;
                }
                case 3:
                    {
                         changeRecord(dataFile);
                         break;
                    }
                default:
                    {
                        cout << "Invalid - Please use 1 to 4" << endl;
                        break;
                    }
                    selection = menu();
            }
    }

    dataFile.close();

    return 0;
}

void addRecord(fstream &file)
{
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
    inventoryData item;

    cout << "Please enter the following data about the item" << endl;
    cout << "Description: ";
    cin.ignore();
    cin.getline(item.desc, DESC_SIZE);
    cout << "Quantity: ";
    cin >> item.quantity;
    cout << "Quantity: ";
    cin >> item.quantity;
    cout << "Wholesale cost: ";
    cin >> item.wholesale;
    cout << "Retail price: ";
    cin >> item.retail;
    cout << "Date (Please use MO/DA/YEAR format: ";
    cin >> item.date;
    dataFile.write(reinterpret_cast<char *>(&item), sizeof(item));

    return;
}

void viewRecord(fstream &file)
{
    string output;
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);

    inventoryData item;
    fstream items;
    char again;

    dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!items.eof())
    {
    // Display the record.
    cout << "Description: " << item.desc << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Wholesale Cost: " << item.wholesale << endl;
    cout << "Retail Cost: " << item.retail << endl;
    cout << "Date: " << item.date << endl;

    // Wait for the user to press the Enter key.
    cout << "\nPress the Enter key to see the next record.\n";

    cin.get(again);
    // Read the next record from the file.
    dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
}


void changeRecord(fstream &file)
{
    fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);

    inventoryData item;
    int recordNumber;

    cout << "Please choose a record number you want to edit" << endl;
    cin >> recordNumber;
    dataFile.seekg(recordNumber * sizeof(item), ios::beg);
    dataFile.read(reinterpret_cast<char *>(&item), sizeof(item));
    cout << "Description: " << item.desc << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Wholesale cost: " << item.wholesale << endl;
    cout << "Retail price: " << item.retail << endl;
    cout << "Date: " << item.date << endl;
    cout << endl;

    // Get the new record data.
    cout << "Enter the new data:\n";
    cout << "Description: ";
    cin.ignore();
    cin.getline(item.desc, DESC_SIZE);
    cout << "Quantity: ";
    cin >> item.quantity;
    cout << "Quantity: ";
    cin >> item.quantity;
    cout << "Wholesale cost: ";
    cin >> item.wholesale;
    cout << "Retail price: ";
    cin >> item.retail;
    cout << "Date (Please use MO/DA/YEAR format: ";
    cin >> item.date;

    // Move back to the beginning of this record's position
    dataFile.seekp(recordNumber * sizeof(item), ios::beg);
    // Write new record over the current record
    dataFile.write(reinterpret_cast<char *>(&item), sizeof(item));

}

int menu()
{
    int menuSelection;

    cout << fixed << showpoint << setprecision(2);
    cout << "----------Inventory----------" << endl;
    cout << "1 - View inventory" << endl;
    cout << "2 - Add an item" << endl;
    cout << "3 - Edit an item" << endl;
    cout << "4 - End Program" << endl;
    cin >> menuSelection;

    if (!cin)
    {
        cout << "Invalid - Please use 1 to 4" << endl;
        cin >> menuSelection;
    }

    if (menuSelection < 1 || menuSelection > 4)
    {
        cout << "Invalid - Please use 1 to 4" << endl;
        cin >> menuSelection;
    }

    return menuSelection;
}