#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
 public:
  Student();
  // Getters
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  // Setters
  void setID(int newID);
  void setGPA(float newGPA);
  // Print function
  void printStudent();
  // Variables
  char firstName[20];
  char lastName[20];
  int ID;
  float GPA; 
};
#endif
