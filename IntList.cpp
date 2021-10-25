#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList(){
  dummyHead = new IntNode(0);
  dummyTail = new IntNode(0);
  dummyHead->next = dummyTail;
  dummyHead->prev = nullptr;
  dummyTail->prev = dummyHead;
  dummyTail->next = nullptr;
}

IntList::~IntList(){
  IntNode *newNode= dummyHead;
  while (newNode != dummyTail){
    IntNode* temp = newNode;
    newNode = newNode->next;
    delete temp;
  }
  delete newNode;
}

void IntList::push_front(int value){
  IntNode *node = new IntNode(value);
  node->prev = dummyHead;
  node->next = dummyHead->next;
  dummyHead->next = node;
  node->next->prev = node;
}

void IntList::pop_front(){
  IntNode *curr = dummyHead;

  if (dummyHead->next == dummyTail){
    return;
  }
  curr = dummyHead->next->next;
  dummyHead->next = curr;
  curr->prev = dummyHead;
}

void IntList::push_back(int value){
  IntNode *curr = new IntNode(value);
  curr->next = dummyTail;
  curr->prev = dummyTail->prev;
  dummyTail->prev = curr;
  curr->prev->next = curr;
}


void IntList::pop_back(){
  if (dummyHead->next == dummyTail){
    return;
  }
  dummyTail->prev = dummyTail->prev->prev;
  delete dummyTail->prev->next;
  dummyTail->prev->next = dummyTail;
}


bool IntList::empty() const{
  if (dummyHead->next == dummyTail){
    return true;
  }
  else{
    return false;
  }
}

ostream & operator<<(ostream &out, const IntList &rhs){
  if (!rhs.empty()){
    IntNode *curr = rhs.dummyHead->next;

    while(curr != rhs.dummyTail){
      if (curr->next == rhs.dummyTail){
        out << curr->data;
      }
      else{
        out << curr->data << " ";
      }
      curr = curr->next;
    }
  }
  return out;
}

void IntList::printReverse() const{
  if (!empty()){
    IntNode* curr = dummyTail->prev;
    if (curr->prev == dummyHead){
      cout << curr->data;
    }
    else{
      while (curr != dummyHead){
        if (curr->prev == dummyHead){
          cout << curr->data;
        }
        else{
          cout << curr->data << " ";
        }
        curr = curr->prev;
      }
    }
  }
}








