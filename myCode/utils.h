//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: utils.h
// Author: Augustine von Trapp
// Date: May 12, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#include <fstream>

using namespace std;

#ifndef UTILS_H
#define UTILS_H

enum SearchOptions {
  QUIT_SEARCH = 0,
  TITLE_SEARCH = 1,
  MODEL_SEARCH = 2,
  ORIGIN_SEARCH = 3
};

void search(CarList carList);
void getInt(int &input, char prompt[200]);
void getDouble(double &input, char prompt[200]);

#endif