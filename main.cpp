#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

int validInput();
void add(Node* &head, Node* cur, Node* prev, Node* inputNode);
void print(Node* head);
void deleteNode(Node* &head, Node* cur, Node* prev, int ID);
void average(Node* head, float sumGPA, int total);

int main() {
  Node* head = NULL;
  Node* cur;
  Node* prev;
  bool running = true;
  while (running == true) {
    int option = validInput();
    // Add function
    if (option == 1) {
      Student* inputStudent = new Student();

      // Prompt first name
      cout << "Please enter a first name." << endl;
      char input[20];
      cin.get(input, 20);
      cin.get();
      strcpy(inputStudent->getFirstName(), input);

      // Prompt last name
      cout << "Please enter a last name." << endl;
      cin.get(input, 20);
      cin.get();
      strcpy(inputStudent->getLastName(), input);

      // Prompt ID
      cout << "Please enter an ID" << endl;
      int idInput;
      cin >> idInput;
      cin.get();
      inputStudent->setID(idInput);

      // Prompt gpa
      cout << "Please enter a gpa." << endl;
      float floatInput;
      cin >> floatInput;
      cin.get();
      inputStudent->setGPA(floatInput);

      Node* inputNode = new Node();
      inputNode->setStudent(inputStudent);
      
      add(head, head, head, inputNode);
    }
    // Print function 
    else if (option == 2) {
      print(head);
    }
    // Delete function
    else if (option == 3) {
      int idInput;
      // Prompt ID to delete
      cout << "Please enter the ID of the user you which to delete." << endl;
      cin >> idInput;
      cin.get();
      deleteNode(head, head, head, idInput);
    }
    // Average function
    else if (option == 4) {
      float sumGPA = 0;
      int total = 0;
      average(head, sumGPA, total);
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

void add(Node* &head, Node* cur, Node* prev, Node* inputNode) {
  // Create first node
  if (head == NULL) {
    head = inputNode;
  }
  else {
    // Replace head with input node if head has a bigger ID
    if (inputNode->getStudent()->getID() < head->getStudent()->getID()) {
	Node* tempNode = head;
	head = inputNode;
	head->setNext(tempNode);
    }
    // If input node falls in between two nodes
    else if ((inputNode->getStudent()->getID() > prev->getStudent()->getID()) && (inputNode->getStudent()->getID() < cur->getStudent()->getID())) {
      prev->setNext(inputNode);
      inputNode->setNext(cur);
    }
    // If recursion reaches the end of the list, the input node must have the biggest ID and is added at the end
    else if (cur->getNext() == NULL) {
      cur->setNext(inputNode);
    }
    // Recursion with current and previous going to the next node
    else {
      add(head, cur->getNext(), cur, inputNode);
    }
  }
}
  
void print(Node* head) {
  // Empty list
  if (head == NULL) {
    cout << "List is empty!" << endl;
  }
  // If list only contains head
  else if (head != NULL && head->getNext() == NULL) {
    head->getStudent()->printStudent();
  }
  // Print student and recurse to next node
  else if (head->getNext() != NULL) {
    head->getStudent()->printStudent();
    print(head->getNext());
  }
}

void deleteNode(Node* &head, Node* cur, Node* prev, int ID) {
  // Empty list
  if (head == NULL) {
    cout << "List is empty!" << endl;
  }
  // Recurses through to the end of the list without finding a student
  else if (cur == NULL) {
    cout << "This student does not exist in the Linked List!" << endl;
  }
  // Inputted ID matches with a node
  else if (cur->getStudent()->getID() == ID) {
    // Matched node is the head and list only contains head
    if (cur == head && head->getNext() == NULL) {
      head->~Node();
      head = NULL;
    }
    // Matched node is the head and list doesn't only contain the head
    else if (cur == head) {
      Node* tempNode = head->getNext();
      head->~Node();
      head = tempNode;
    }
    // If the deleted node has a next node, change to previous node's next node to the delete node's next node
    else if (cur != head && cur->getNext() != NULL) {
      prev->setNext(cur->getNext());
      cur->~Node();
    }
    // If the deleted node doesn't have a next node 
    else if (cur != head && cur->getNext() == NULL) {
      prev->setNext(NULL);
      cur->~Node();
    }
  }
  // Recursion with current going to the next node
  else {
    deleteNode(head, cur->getNext(), cur, ID);
  }
}

void average(Node* head, float sumGPA, int total) {
  // Empty list
  if (head == NULL && total == 0) {
    cout << "List is empty!" << endl;
  }
  // Add individual GPA to the sumpGPA and track the total amount of students in total
  else if (head != NULL) {
    sumGPA += head->getStudent()->getGPA();
    total++;
    average(head->getNext(), sumGPA, total);
  }
  // Average the GPA
  else {
    cout << fixed << setprecision(2) << (sumGPA/total);
  }
}
