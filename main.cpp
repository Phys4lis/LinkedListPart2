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

  }
  else if (head != NULL && head->getNext() == NULL) {
    if (
    Node* tempNode = head;
      head = inputNode;
      head->setNext(tempNode);
      cur = tempNode;
    }
    else {
      head->setNext(inputNode);
      cur = inputNode;
    }
  }
  else {
    if (inputNode->getStudent()->getID() > cur->getStudent->getID() && inputNode->getStudent()->getID() < head->getNext()->getStudent()->getID()) {
      
    }
  }
}
  
