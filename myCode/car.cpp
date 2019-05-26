//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: car.cpp
// Author: Augustine von Trapp
// Date: May 12th, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "car.h"

using namespace std;

ostream & operator << (ostream &out, CarType &car) {

  char title[200] = "";
  car.getTitle(title);
  double mpg = car.getMpg();
  int cylinders = car.getCylinders();
  double displacement = car.getDisplacement();
  double horsepower = car.getHorsepower();
  double weight = car.getWeight();
  double acceleration = car.getAcceleration();
  int model = car.getModel();
  // char origin[200];

  cout << title << ";"
       << mpg << ";"
       << mpg << ";"
       << cylinders << ";"
       << displacement << ";"
       << horsepower << ";"
       << weight << ";"
       << acceleration << ";"
       << model << ";";

  switch (car.getOrigin()) {
    case EUROPE:
      cout << "Europe;" << endl;
      break;
    case US:
      cout << "US;" << endl;
      break;
    default:
      cout << "Japan;" << endl;
      break;
  }

  return out;
}

CarType::CarType() {
  title = new char[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[200];
}

CarType::~CarType() {
	//deallocate memory for title

  if (title) {
    delete [] title;
    title = NULL;
  }
}

CarType::CarType(char newTitle[]) {
  strcpy(title, newTitle);
}

void CarType::print() {
  cout << title << ";"
       << mpg << ";"
       << cylinders << ";"
       << displacement << ";"
       << horsepower << ";"
       << weight << ";"
       << acceleration << ";"
       << model << ";";

  switch (origin) {
    case EUROPE:
      cout << "Europe;" << endl;
      break;
    case US:
      cout << "US;" << endl;
      break;
    default:
      cout << "Japan;" << endl;
      break;
  }

  return;
}

void CarType::print(ofstream &outFile) {
  cout << title << ";"
       << mpg << ";"
       << cylinders << ";"
       << displacement << ";"
       << horsepower << ";"
       << weight << ";"
       << acceleration << ";"
       << model << ";";

  switch (origin) {
    case EUROPE:
      cout << "Europe;" << endl;
      break;
    case US:
      cout << "US;" << endl;
      break;
    default:
      cout << "Japan;" << endl;
      break;
  }

  return;
}


const void CarType::setTitle(char newTitle[]) {
  if(title) {
		delete [] title;
		title = NULL;
	}

	title = new char[strlen(newTitle)+1];
	strcpy(title, newTitle);
}

const void CarType::getTitle(char outTitle[]) {
  strcpy(outTitle, title);
}

void CarType::setMpg(double newMpg) {
  mpg = newMpg;
  return;
}

double CarType::getMpg() {
  return mpg;
}

void CarType::setCylinders(int newCylinders) {
  cylinders = newCylinders;
  return;
}

int CarType::getCylinders() {
  return cylinders;
}

void CarType::setDisplacement(double newDisplacement) {
  displacement = newDisplacement;
  return;
}

double CarType::getDisplacement() {
  return displacement;
}

void CarType::setHorsepower(double newHorsepower) {
  horsepower = newHorsepower;
  return;
}

double CarType::getHorsepower() {
  return horsepower;
}

void CarType::setWeight(double newWeight) {
  weight = newWeight;
  return;
}

double CarType::getWeight() {
  return weight;
}

void CarType::setAcceleration(double newAcceleration) {
  acceleration = newAcceleration;
  return;
}

double CarType::getAcceleration() {
  return acceleration;
}

void CarType::setModel(int newModel) {
  model = newModel;
  return;
}

int CarType::getModel() {
  return model;
}

void CarType::setOrigin(Origin newOrigin) {
  origin = newOrigin;
}

Origin CarType::getOrigin() {
  return origin;
}

CarType& CarType::operator= (CarType& car) {
  char tmpTitle[200];

  if (this == &car) {
    return *this;
  } else {
    car.getTitle(tmpTitle);
    this->setTitle(tmpTitle);
    this->setMpg(car.getMpg());
    this->setCylinders(car.getCylinders());
    this->setDisplacement(car.getDisplacement());
    this->setHorsepower(car.getHorsepower());
    this->setWeight(car.getWeight());
    this->setAcceleration(car.getAcceleration());
    this->setModel(car.getModel());
    this->setOrigin(car.getOrigin());

    return *this;
  }
}
