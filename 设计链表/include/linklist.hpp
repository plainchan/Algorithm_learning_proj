#ifndef LINKLIST_HPP
#define LINKLIST_HPP

#include <iostream>

//单链表
class MyLinkedList
{
public:
  struct Node
  {
    int val;
    Node* next;
    Node(int x):val(x),next(nullptr){}
  };

  MyLinkedList()
  {
    size =0;
    head=new Node(0);
  }

  int get(int index)
  {
    if(index >size-1 or index <0)
      return -1;
    Node* cur = head;
    for(int i=0;i<index;i++)
      cur = cur->next;
    return cur->next->val;
  }

  void addAtHead(int val)
  {
    addAtIndex(0,val);
  }

  void addAtTail(int val)
  {
    addAtIndex(size,val);
  }

  void addAtIndex(int index, int val)
  {
    if(index >size)
      return;

    if(index <0)
      index =0;

    size++;

    Node* pred = head;
    for(int i=0;i<index;i++)
      pred =pred->next;
    
    Node* newNode =new Node(val);
    newNode->next = pred->next;
    pred->next = newNode;
  }

  void deleteAtIndex(int index)
  {
    if(index <0 or index >size-1)
      return;
    Node* pred = head;
    for(int i=0;i<index;i++)
      pred = pred->next;
    Node* cur = pred->next;
    pred->next = pred->next->next;
    size--;
    delete cur;
  }
  void print()
  {
    Node* cur =head;
    std::cout << "[";
    while(cur->next)
    {
      if(cur->next->next)
        std::cout << cur->next->val<<" ";
      else
        std::cout << cur->next->val;
      cur = cur->next;
    }
    std::cout << "]" << std::endl;
  }
private:
  int size;
  Node* head;  //虚拟头接点,其值没有任何意义
};

//双向链表
class MyLinkedList {
public:
    MyLinkedList() {

    }
    
    int get(int index) {

    }
    
    void addAtHead(int val) {

    }
    
    void addAtTail(int val) {

    }
    
    void addAtIndex(int index, int val) {

    }
    
    void deleteAtIndex(int index) {

    }
};















#endif