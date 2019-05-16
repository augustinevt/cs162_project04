//////////////////////////////////////////
// Program Name: CarTypedatabase
// Filename: car.h
// Author: Augustine von Trapp
// Date: may 12th, 2019
// Assignment: project3
// Description: This program allows a user to manage a car database
//////////////////////////////////////////

#ifndef CAR_TYPE
#define CAR_TYPE

enum Origin {
  EUROPE = 0,
  US = 1,
  JAPAN = 2
};

class CarType {
  private:

    char title[200];
    double mpg;
    int cylinders;
    double displacement;
    double horsepower;
    double weight;
    double acceleration;
    int model;
    Origin origin;

  public:
    CarType();
    CarType(char []);

    void setTitle(char title[200]);
    void setMpg(double newMpg);
    void setCylinders(int newCylinders);
    void setDisplacement(double newDisplacement);
    void setHorsepower(double newHorsepower);
    void setWeight(double newHeight);
    void setAcceleration(double newAcceleration);
    void setModel(int newModel);
    void setOrigin(Origin newOrigin);

    void getTitle(char outTitle[200]);
    double getMpg();
    int getCylinders();
    double getDisplacement();
    double getHorsepower();
    double getWeight();
    double getAcceleration();
    int getModel();
    Origin getOrigin();

    void print();
};

#endif


