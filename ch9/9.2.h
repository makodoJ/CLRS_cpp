//
// Created by makodo on 2020/12/14.
//

#ifndef ch9_1_h
#define ch9_1_h

#include "/Users/jiangrenjie/Documents/clrs/ch5/5.1.h"
#include "/Users/jiangrenjie/Documents/clrs/ch7/7.3.h"
#include "/Users/jiangrenjie/Documents/clrs/ch7/7.1.h"

#include <vector>

using namespace std;
using namespace CLRS::CH7;
using namespace CLRS::CH5;

namespace CLRS{ namespace CH9{
    // - Time : O(n)
    template <typename T>
    void randomized_select(vector<T>& A, int p, int r, int i){
        if(p == r)
            return;
        int q = randomized_partition(A, p, r);
        int k = q - p + 1;
        if(i == k)
            return A[q];
        else if(i < k)
            randomized_select(A, p, q - 1, i);
        else
            randomized_select(A, q + 1, r, i - k);
    }

    // - Time : O(n)
    template <typename T>
    void iterative_randomized_select(vector<T>& A, int p, int r, int i){
        while(p < r){
            int q = randomized_partition(A, p, r);
            int k = q - p + 1;
            if(k == i)
                return A[q];
            else if(k < i)
                r = q - 1;
            else {
                p = q;
                i = i - k;
            }
        }

        return A[p];
    }
}}

#endif