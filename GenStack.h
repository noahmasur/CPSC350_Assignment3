#include "GenStack_Init.h"

template <class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  m_size = 128;

  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  m_size = maxSize;

  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete[] myArray;
}
template <class T>
void GenStack<T>::push(T data){
  //check if full before attempting to insert
  if(top >= (m_size - 1)){
    T* temp = myArray;
    myArray = new T[++m_size];
    copy(temp,temp + m_size, myArray);
    delete temp;
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop(){
  //check if empty before attempting to remove
  if(top != -1){
    return myArray[top--];
  } else{
    return '\0';
  }
}

template <class T>
T GenStack<T>::peek(){
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return (top == m_size -1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
