#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

/* Node class. Each node stores a VALUE (a student) and a NEXT NODE (a pointer
 * to the next node in the sequence
 */
class Node
{
 public:
  Node(); // default constructor
  Node(Student*); // constructor (you can set the student initially)
  ~Node(); // destructor
  void setNext(Node*); // set the next node pointer
  Node* getNext(); // get the next node in the sequence
  void setStudent(Student*); // set a student to the node
  Student* getStudent(); // get the student pointer
 private:
  Student* student; // value of the node
  Node* nextNode; // next node in the list
};
#endif
