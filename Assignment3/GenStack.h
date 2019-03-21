#include <iostream>
#include "StackEmptyException.h"

template <typename dataType>

/*

A stack data structure implemented with an array, this
stack contains the ability to resize itself in cases where
it is full.

*/
class GenStack {

private:
  int capacity; //how many items the stack can hold
  int indexOfTopItem; //the location of the top item in the stack
  dataType* stackArray; //the array that will store the items in the stack

  //doubles the current size of the stackArray to allow the stack to increase its size when it becomes full
  void IncreaseCapacity() {

    dataType* tempArray = stackArray; //used to preserve the original data in the array

    capacity *= 2; //double the original capicity
    stackArray = new dataType[capacity]; //reallocate the array with the new capacity

    for (int i = 0; i < (capacity / 2); i++) { //i < capacity / 2 because the original capicity is always half of the new capicity since it is doubled

      stackArray[i] = tempArray[i]; //refill with original items

    }

    delete[] tempArray; //delete the old array that ran out of room

  }

public:

  //default constructor
  GenStack() {

    capacity = 10;
    stackArray = new dataType[capacity];
    indexOfTopItem = -1;

  }

  //destructor
  ~GenStack() {

    delete[] stackArray;

  }

  //removes the item at the top of the stack
  void pop() throw(StackEmptyException){

    if (empty()) {

      //throw a stack empty exception
      throw StackEmptyException("Stack is empty");

    }

    indexOfTopItem -= 1;

  }

  //returns a reference to the top of the stack without removing it
  const dataType& top() throw(StackEmptyException){

    if (empty()) {

      //throw a stack empty exception
      throw StackEmptyException("Stack is empty");

    }

    return stackArray[indexOfTopItem];

  }

  //put a new item on the top of the stack
  void push(dataType item) {

    indexOfTopItem++;

    if (isFull()) {

      //the stack is full and its size needs to be increased:
      IncreaseCapacity();

    }

    stackArray[indexOfTopItem] = item;

  }

  //checks if the stack is empty
  bool empty() {

    return (indexOfTopItem < 0);

  }

  //checks if the stack is full
  bool isFull() {

    return (indexOfTopItem > (capacity - 1));

  }

};
