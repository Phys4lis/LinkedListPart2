#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

int validInput();
void add(Node* &head, Node* cur, Node* prev);

int main() {
  Node* head = NULL;
  Node* cur;
  Node* prev;
  bool running = true;
  while (running == true) {
    int option = validInput();
    // Add function
    if (option == 1) {
      add(head, cur, prev);
    }
    // Print function 
    else if (option == 2) {

    }
    // Delete function
    else if (option == 3) {

    }
    // Average function
    else if (option == 4) {
      
    }
    // Quit function
    else if (option == 5) {
      running = false;
    }
  }
}

// Check for valid input
int validInput() {
  char input[20];
  bool inputLoop = true;
  while (inputLoop == true) {
    cout << endl << "Enter one of the following options: ADD, PRINT, DELETE, AVERAGE or QUIT" << endl;
    char input[20];
    cin.get(input, 20);
    cin.get();
    if (strcmp(input, "ADD") == 0) {
      return 1;
    }
    else if (strcmp(input, "PRINT") == 0) {
      return 2;
    }
    else if (strcmp(input, "DELETE") == 0) {
      return 3;
    }
    else if (strcmp(input, "AVERAGE") == 0) {
      return 4;
    }
    else if (strcmp(input, "QUIT") == 0) {
      return 5;
    }
    else {
      cout << "Please enter a valid option." << endl;
    }
  }
  return -1;
}

void add(Node* &head, Node* cur, Node* prev) {
  if (head == NULL) {
    Student* s = new Student();
    head->setStudent(s);
    cout << "Please enter a first name." << endl;
    char input[20];
    cin.get(input, 20);
    cin.get();
    strcpy(s->firstName, input);
    // Prompt last name
    cout << "Please enter a last name." << endl;
    cin.get(input, 20);
    cin.get();
    strcpy(s->lastName, input);
    // Prompt id
    cout << "Please enter an ID" << endl;
    int idInput;
    cin >> idInput;
    cin.get();
    s->ID = idInput;
    // Prompt gpa
    cout << "Please enter a gpa." << endl;
    float floatInput;
    cin >> floatInput;
    cin.get();
    s->GPA = floatInput; 
  }
}
  
