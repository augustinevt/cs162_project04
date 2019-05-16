//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: utils.cpp
// Author: Augustine von Trapp
// Date: May 12, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "carList.h"
#include "utils.h"

void search(CarList carList) {
	int searchSelect = 1;
	double weightTerm;
	char searchTerm[200];

	cout << "\n------SEARCH MENU------\n";

	while(searchSelect != QUIT_SEARCH) {

		char searchPrompt[1000] = "\nPlease select a search criteria:\n\n"
			"search by title: 1\n"
			"search by model: 2\n"
			"search by origin: 3\n"
			"return to main menu: 0\n";

		getInt(searchSelect, searchPrompt);

		switch (searchSelect) {
			case QUIT_SEARCH:
				break;

			case TITLE_SEARCH:
				cout << "Enter search term: " << endl;
				carList.searchByTitle();
				break;

			case MODEL_SEARCH:
				carList.searchByModel();
				break;

			case ORIGIN_SEARCH:
				carList.searchByOrigin();
				break;

			default:
				cout << "Please enter a valid option";
		}
	}

  return;
}

void getInt(int &input, char prompt[200]) {

	cin.ignore(100, '\n');
	cin.clear();

	do {

		if (cin.fail()) {
			cout << "Invalid input. "
					 << "Please enter a int (2, 200, ect.)\n";
			cin.clear();
			cin.ignore();
		}

		cout << prompt << endl;
		cin >> input;

	} while(cin.fail());

	return;
}

void getDouble(double &input, char prompt[200]) {

	cin.ignore(100, '\n');
	cin.clear();

	do {

		if (cin.fail()) {
			cout << "Invalid input. "
					 << "Please enter a double (2, 2.1, ect.)\n";
			cin.clear();
			cin.ignore();
		}

		cout << prompt << endl;
		cin >> input;

	} while(cin.fail());

	return;
}