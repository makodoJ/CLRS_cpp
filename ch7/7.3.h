//
// Created by makodo on 2020/12/7.
//

#ifndef ch7_3_h
#define ch7_3_h

#include "/Users/jiangrenjie/Documents/clrs/ch5/5.1.h"
#include "/Users/jiangrenjie/Documents/clrs/print/print.h"
#include "7.1.h"

namespace CLRS{ namespace CH7{
    // - Time : O(n)
    template <typename T>
    int randomized_partition(vector<T>& A, int p, int r){
        int i = CH5::random(p, r);
        swap(A[r], A[i]);
        return partition(A, p, r);
    }

    // - Time : O(nlgn)
    template <typename T>
    void randomized_quicksort(vector<T>& A, int p, int r){
        if(p < r){
            int q = randomized_partition(A, p, r);
            randomized_quicksort(A, p, q - 1);
            randomized_quicksort(A, q + 1, r);
        }
    }
}}

#endif