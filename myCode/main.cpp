//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: main.cpp
// Author: Augustine von Trapp
// Date: May 12th, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "carList.h"
#include "utils.h"

using namespace std;

int main() {
  char fileName[100] = "cars.txt";
  char cmd = 'a';

  CarList carList(fileName);

  cout << "\n\nHello and welcome to project 3!\n\n";

  while(tolower(cmd) != 'q') {
    cout << "------MAIN MENU--------\n"
         << "Please select an option. Enter \n\n"
         << "S to search cars by title, model, or origin\n"
         << "P to print all cars\n"
         << "R to remove a car\n"
         << "A to add a car\n";
    cin >> cmd;

    switch(tolower(cmd)){
      case 's':
        search(carList);
        break;

      case 'p':
        carList.print();
        break;

      case 'r':
        carList.remove();
        break;

      case 'a':
        carList.addCar();
        break;

      case 'q':
        carList.writeFile(fileName);
        cout << "Goodbye" << endl;
        break;

      default:
        cout << "Please enter a valid option.\n";
        break;
    }
  }

  return 0;
}



