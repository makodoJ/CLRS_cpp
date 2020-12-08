//
// Created by makodo on 2020/12/8.
//

#ifndef prob7_2_h
#define prob7_2_h

#include "../ch5/5.1.h"
#include "7.1.h"

namespace CLRS{namespace CH7{
    // - Time : O(n)
    template <typename T>
    vector<int> partition_equal(vector<T>& A, int p, int r){
        T x = A[r];
        int q = p;
        int t = p;
        int i;
        for(i = p + 1; i <= r; i++){
            if(A[i] < x){
                int y = A[i];
                A[i] = A[t + 1];
                A[q] = y;
                ++q;
                ++t;
            }
            if(A[i] == x){
                swap(A[t + 1], A[i]);
                ++t;
            }
        }
        return { q, t };
    }

    // - Time : O(n)
    template <typename T>
    vector<int> randomized_partition_equal(vector<T>& A, int p, int r){
        int i = CH5::random(p, r);
        swap(A[r], A[i]);
        return partition_equal(A, p, r);
    }

    // - Time : O(nlgn)
    template <typename T>
    void randomized_quicksort_equal(vector<T>& A, int p, int r){
        if(p < r){
            vector<int> a = randomized_partition_equal(A, p, r);
            randomized_quicksort_equal(A, p, a[0] - 1);
            randomized_quicksort_equal(A, a[1] + 1, r);
        }
    }
}}

#endif
