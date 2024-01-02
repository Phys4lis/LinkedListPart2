#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

Student::Student() {
  
}

// Getters
char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return ID;
}

float Student::getGPA() {
  return GPA;
}

// Setters
void Student::setID(int newID) {
  ID = newID;
}

void Student::setGPA(float newGPA) {
  GPA = newGPA;
}

// Print function
void Student::printStudent() {
  cout << endl << firstName << " " << lastName << " " << ID << " " << fixed << setprecision(2) << GPA << endl;
}
