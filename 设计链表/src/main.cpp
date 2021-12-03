#include <iostream>
#include "linklist.hpp"

using namespace std;

int main()
{
  MyLinkedList* link = new MyLinkedList();
  link->addAtTail(1);
  link->addAtTail(2);
  link->addAtIndex(1,100);
  link->print();
  link->deleteAtIndex(1);
  link->print();
  return 0;
}


