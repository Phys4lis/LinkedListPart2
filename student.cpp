#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student() {
  cout << "Please enter a first name." << endl;
  char input[20];
  cin.get(input, 20);
  cin.get();
  strcpy(firstName, input);
  // Prompt last name
  cout << "Please enter a last name." << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(lastName, input);
  // Prompt id
  cout << "Please enter an ID" << endl;
  int idInput;
  cin >> idInput;
  cin.get();
  ID = idInput;
  // Prompt gpa
  cout << "Please enter a gpa." << endl;
  float floatInput;
  cin >> floatInput;
  cin.get();
  GPA = floatInput;
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
