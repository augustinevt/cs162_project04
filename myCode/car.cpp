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

CarType::CarType() {
  char title[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[200];
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

void CarType::setTitle(char newTitle[]) {
  strcpy(title, newTitle);
}

void CarType::getTitle(char outTitle[]) {
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
