#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

// cpp file for the node class
Node::Node() // default constructor
{
  // initialize variables
  nextNode = NULL;
  student = new Student();
}

Node::Node(Student* newstudent) // constructor w student
{
  // initialize variables
  nextNode = NULL;
  student = newstudent;
}

Node::~Node() // destructor
{
  // remove things from the heap
  delete student;
  nextNode = NULL;
}

void Node::setNext(Node* newnode) // set next node
{
  nextNode = newnode;
}

Node* Node::getNext() // return next node
{
  return nextNode;
}

void Node::setStudent(Student* newstudent)
{
  student = newstudent;
}

Student* Node::getStudent()
{
  return student;
}
