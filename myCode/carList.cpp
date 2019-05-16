//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: carList.cpp
// Author: Augustine von Trapp
// Date: May 12th, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "carList.h"
#include "utils.h"
#include "car.h"

using namespace std;

CarList::CarList(char fileName[]) {

  size = 0;

  ifstream inFile;
  inFile.open(fileName);

  inFile.clear();
  inFile.seekg(0);

  CarType car;

  char title[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[200];
  Origin enumOrigin;

  while(!inFile.eof()) {

    inFile.get(title, 200, ';');
    car.setTitle(title);
    inFile.ignore(200, ';');

    inFile >> mpg;
    car.setMpg(mpg);
    inFile.ignore(100, ';');

    inFile >> cylinders;
    car.setCylinders(cylinders);
    inFile.ignore(100, ';');

    inFile >> displacement;
    car.setDisplacement(displacement);
    inFile.ignore(100, ';');

    inFile >> horsepower;
    car.setHorsepower(horsepower);
    inFile.ignore(100, ';');

    inFile >> weight;
    car.setWeight(weight);
    inFile.ignore(100, ';');

    inFile >> acceleration;
    car.setAcceleration(acceleration);
    inFile.ignore(100, ';');

    inFile >> model;
    car.setModel(model);
    inFile.ignore(100, ';');

    inFile.get(origin, 200, '\n');

    if (strcmp(origin, "Europe") == 0) {
    	enumOrigin = EUROPE;
    } else if (strcmp(origin, "US") == 0) {
    	enumOrigin = US;
    } else if (strcmp(origin, "Japan") == 0) {
    	enumOrigin = JAPAN;
    }

    car.setOrigin(enumOrigin);
    inFile.ignore(200, '\n');

    carList[size] = car;
    size++;
  }
}

void CarList::searchByTitle() {
	char term[200];
  char carTitle[200];

  cin.ignore();
	cin.get(term, 200, '\n');

	for(int i = 0; i < size; i++) {
    carList[i].getTitle(carTitle);
		if(strstr(carTitle, term)) {
			carList[i].print();
		}
	}

	return;
}

void CarList::searchByModel() {
	int model;

	cout << "Enter model: \n";
	cin >> model;

	for(int i = 0; i < size; i++) {
		if(carList[i].getModel() == model) {
			carList[i].print();
		}
	}

	return;
}

void CarList::searchByOrigin() {
	bool validOrigin = false;
	int origin;

	do {
		cout << "\n\nSelect Origin:\n\n"
				 << "Europe: 0\n"
				 << "US: 1\n"
				 << "Japan: 2\n"
				 << endl;

		cin >> origin;

		switch (origin) {
			case EUROPE:
				validOrigin = true;
				break;

			case US:
				validOrigin = true;
				break;

			case JAPAN:
				validOrigin = true;
				break;

			default:
				cout << "Invalid Origin!\n";
		}
	} while(!validOrigin);

	for(int i = 0; i < size; i++) {
		if (carList[i].getOrigin() == origin) {
			carList[i].print();
		}
	}

	return;
}

void CarList::remove() {
  char removePrompt[200] = "Enter index:";
  int position = 0;

  getInt(position, removePrompt);

  if(position > size) {
    cout << "This index does not exist! \n\n";
    return;
  }

  for (int i = position; i < size; i++) {
    carList[i] = carList[i + 1];
  }

  size--;

  return;
}

void CarList::print() {
  for(int i = 0; i < size; i++) {
    cout << i << " : ";
    carList[i].print();
  }
  return;
}

void CarList::addCar() {
	CarType car;

	int origin = 0;
  Origin enumOrigin = EUROPE;
	bool validOrigin = false;

	char mpgPrompt[200] = "Enter MPG (double): ";
	char cylinderPrompt[200] = "Enter Cylinders (int): ";
	char displacementPrompt[200] = "Enter the displacement (double): ";
	char horsepowerPrompt[200] = "Enter the horsepower (double): ";
	char weightPrompt[200] = "Enter the weight (double): ";
	char accelerationPrompt[200] = "Enter the acceleration (double): ";
	char modelPrompt[200] = "Enter the model (int): ";
	char originPrompt[200] = "Enter the origin: ";

  char title[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;

	cout << "\nEnter the title: " << endl;
	cin.ignore();
	cin.get(title, 200);

	getDouble(mpg, mpgPrompt);
	getInt(cylinders, cylinderPrompt);
	getDouble(displacement, displacementPrompt);
	getDouble(horsepower, horsepowerPrompt);
	getDouble(weight, weightPrompt);
	getDouble(acceleration, accelerationPrompt);
	getInt(model, modelPrompt);

  car.setTitle(title);
	car.setMpg(mpg);
	car.setCylinders(cylinders);
	car.setDisplacement(displacement);
	car.setHorsepower(horsepower);
	car.setWeight(weight);
	car.setAcceleration(acceleration);
	car.setModel(model);

	do {
		cout << "\nSelect Origin:\n\n"
				 << "Europe: 0\n"
				 << "US: 1\n"
				 << "JAPAN: 2\n"
				 << endl;

		cin >> origin;

		switch (origin) {
			case EUROPE:
				enumOrigin = EUROPE;
				validOrigin = true;
				break;
			case US:
				enumOrigin = US;
				validOrigin = true;
				break;
			case JAPAN:
				enumOrigin = JAPAN;
				validOrigin = true;
				break;
			default:
				cout << "Invalid Origin!\n";
		}
	} while(!validOrigin);

  car.setOrigin(enumOrigin);
	carList[size] = car;
	cout << "\ncar added!\n\n";
	size++;

	return;
}

void CarList::writeFile(char filename[200]) {
	char title[200];
	Origin origin;
	ofstream outFile;

	outFile.open("cars.txt");

	for(int i = 0; i < size; i++) {

		carList[i].getTitle(title);

		outFile << title << ";";
 		outFile << carList[i].getMpg() << ";";
 		outFile << carList[i].getCylinders() << ";";
 		outFile << carList[i].getDisplacement() << ";";
 		outFile << carList[i].getHorsepower() << ";";
 		outFile << carList[i].getWeight() << ";";
 		outFile << carList[i].getAcceleration() << ";";
 		outFile << carList[i].getModel() << ";";

		origin = carList[i].getOrigin();

		switch (origin) {
			case EUROPE:
				outFile << "Europe";
				break;
			case US:
				outFile << "US";
				break;
			default:
				outFile << "Japan";
				break;
		}

		if(i != size - 1) {
			outFile << endl;
		}
	}

	outFile.close();
}