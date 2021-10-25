#include "IntList.h"
#include <iostream>
using namespace std;

int main() {

  IntList* newList = new IntList();

  cout << "Testing push front function: ";
  newList->push_front(10);
  newList->push_front(20);
  newList->push_front(30);
  newList->push_front(40);
  newList->push_front(50);
  cout << *newList << endl << endl;

  cout << "Testing pop front function: ";
  newList->pop_front();
  cout << *newList << endl << endl;

  cout << "Testing push back function: ";
  newList->push_back(100);
  newList->push_back(150);
  cout << *newList << endl << endl;
  

  cout << "Testing pop back function: ";
  newList->pop_back();
  cout << *newList << endl << endl;
  

  cout << "Testing print reverse function: ";
  newList->printReverse();
  cout << *newList << endl;
  return 0;
}