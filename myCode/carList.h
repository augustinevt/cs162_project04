//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: carList.h
// Author: Augustine von Trapp
// Date: May 12th, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#ifndef CAR_LIST
#define CAR_LIST

#include <fstream>
#include "car.h"

using namespace std;

class CarList {

  private:
    CarType *carList;
    int size;
    int capacity;

    void growList();

  public:
    CarList(char fileName[100]);
    ~CarList();
    void print();
    void searchByTitle();
    void searchByModel();
    void searchByOrigin();
    void remove();
    void addCar();
    void writeFile(char filename[200]);
};

#endif