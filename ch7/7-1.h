//
// Created by makodo on 2020/12/8.
//

#ifndef prob7_1_h
#define prob7_1_h

#include "7.1.h"

namespace CLRS{ namespace CH7{
    // - Time : O(n)
    template <typename T>
    int hoare_partition(vector<T>& A, int p, int r){
        T x = A[p];
        int i = p - 1;
        int j = r + 1;
        while(true){
            do{
                --j;
            }while(A[j] < x);
            do{
                ++i;
            }while(A[i] > x);
            if(i < j)
                swap(A[i], A[j]);
            else return j;
        }
    }

    // - Time : O(n^2)
    template <typename T>
    void hoare_quicksort(vector<T>& A, int p, int r){
        if(p < r){
            int q = hoare_partition(A, p, r);
            hoare_quicksort(A, p, q );
            hoare_quicksort(A, q + 1, r);
        }
    }
}}

#endif