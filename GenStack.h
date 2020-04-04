#include "GenStack_Init.h"

template <class T>
//Default Constructor
GenStack<T>::GenStack(){
  myArray = new T[128];
  m_size = 128;

  top = -1;
}

template <class T>
//Overload Constructor
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  m_size = maxSize;

  top = -1;
}

template <class T>
//Desturctor
GenStack<T>::~GenStack(){
  delete[] myArray;
}

template <class T>
//Adds element to top of stack
void GenStack<T>::push(T data){
  if(top >= (m_size - 1)){
    //if full create bigger array
    T* temp = myArray;
    myArray = new T[++m_size];

    copy(temp,temp + m_size, myArray);
    delete temp;
  }

  myArray[++top] = data;
}

template <class T>
//Removes element from top of stack
T GenStack<T>::pop(){
  //check if empty before attempting to remove
  if(top != -1){
    return myArray[top--];
  } else{
    cout << "Stack Empty: unable to complete pop" << endl;
    return '\0';
  }
}

template <class T>
//Returns top of stack
T GenStack<T>::peek(){
  return myArray[top];
}

template <class T>
//Checks if stack is full
bool GenStack<T>::isFull(){
  return (top == m_size -1);
}

template <class T>
//Checks if stack is empty
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
