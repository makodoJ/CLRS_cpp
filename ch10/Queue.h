//
// Created by makodo on 2020/12/15.
//

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue : private vector<T> {
public:
    using vector<T>::vector;
    using vector<T>::operator[];
    using vector<T>::size;

    int head;
    int tail;
    void set_head();
    void set_tail();
};

template <class T>
void Queue<T>::set_head(){
    for(int i = 0; i < this -> size(); i++){
        if((*this)[i] != 0) {
            this->head = i;
            break;
        }
    }
}

template <class T>
void Queue<T>::set_tail(){
    for(int i = this -> size() - 1; i >= 0; i--){
        if((*this)[i - 1] != 0){
            this -> tail = i;
            break;
        }
    }
}

#endif