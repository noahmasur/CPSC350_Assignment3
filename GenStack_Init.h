#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
class GenStack{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack(); //destructor

    //core functions
    void push(T data); //insert
    T pop(); //remove

    //aux/helper functions
    T peek(); //AKA top
    bool isEmpty();
    bool isFull();

  private:
    T top;
    int m_size;

    T *myArray; //memory adress of the first block
};
