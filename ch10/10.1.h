//
// Created by makodo on 2020/12/14.
//

#ifndef ch10_1_h
#define ch10_1_h

#include "Stack.h"
#include "Queue.h"

using namespace std;

namespace CLRS{ namespace CH10{
    template <typename T>
    bool stack_empty(Stack<T>& S){
        if(S.top() == 0)
            return true;
        else
            return false;
    }

    template <typename T>
    void push(Stack<T>& S, T x){
        S.top = S.top + 1;
        S[S.top] = x;
    }

    template <typename T>
    T pop(Stack<T>& S){
        if(stack_empty(S)){
            throw("underflow");
        }else {
            S.top--;
            return S[S.top + 1];
        }
    }

    template <typename T>
    void enqueue(Queue<T>& Q, T x){
        Q[Q.tail] = x;
        if(Q.tail == Q.size() - 1)
            Q.tail = 1;
        else Q.tail = Q.tail + 1;
    }

    template <typename T>
    T dequeue(Queue<T>& Q){
        T x = Q[Q.head];
        if(Q.head == Q.size() - 1)
            Q.head = 0;
        else
            Q.head++;
        return x;
    }

    template <typename T>
    void two_stack_push(Stack<T>& S, T x){
        Stack<T> L;
        Stack<T> R;
        if(S == L){
            if(L.top + 1 == R.top){
                throw("overflow");
            }
            L.top += 1;
            L[L.top] = x;
        }

        if(S == R){
            if(R.top - 1 == L.top){
                throw("overflow");
            }
            R.top -= 1;
            R[R.top] = x;
        }
    }

    template <typename T>
    T two_stack_pop(Stack<T>& S){
        Stack<T> L;
        Stack<T> R;
        if(S == L){
            if(L.top == 0) {
                throw ("underflow");
            }
            L.top -= 1;
            return L[L.top];
        }
        if(S == R){
            if(R.top == S.size() - 1){
                throw("underflow");
            }
            R.top += 1;
            return R[R.top];
        }
    }

    template <typename T>
    void enqueue_rewrite(Queue<T>& Q, T x){
        if(Q.tail + 1 == Q.head || (Q.head == 0 && Q.tail == Q.size() - 1)) {
            throw ("overflow");
        }
        Q[Q.tail] = x;
        if(Q.tail == Q.size - 1)
            Q.tail = 1;
        else
            Q.tail++;

    }

    template <typename T>
    void dequeue_rewrite(Queue<T>& Q){
        if(Q.tail == Q.head)
            throw("underflow");
        T x = Q[Q.head];
        if(Q.head == Q.size() - 1)
            Q.head = 1;
        else
            Q.head++;
        return x;
    }

    template <typename T>
    T head_dequeue(Queue<T>& Q){
        if(Q.head == Q.tail){
            throw("underflow");
        }
        T x = Q[Q.tail];
        if(Q.tail == 0)
            Q.tail = Q.size - 1;
        else
            Q.tail--;
    }

    template <typename T>
    void tail_enqueue(Queue<T>& Q, T x){
        if(Q.tail + 1 == Q.head || (Q.head == 0 && Q.tail == Q.size - 1))
            throw("overflow");
        if(Q.tail == Q.size - 1){
            Q.tail = 0;
            Q[Q.tail] = x;
        }else{
            Q.tail += 1;
            Q[Q.tail] = x;
        }
    }
}} // namespace

#endif