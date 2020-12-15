//
// Created by makodo on 2020/12/15.
//

#ifndef Stack_h
#define Stack_h

#include <vector>

using namespace std;

template <class T>
class Stack : private vector<T>{
public:
    using vector<T>::vector;
    using vector<T>::operator[];
    using vector<T>::size;
    using vector<T>::resize;

    int top;
    void set_top();
};

template <class T>
void Stack<T>::set_top(){
    this -> top = this -> size() - 1;
    this -> resize(7);
}

#endif