//
// Created by makodo on 2020/12/4.
//

#ifndef ch7_1_h
#define ch7_1_h

#include <vector>
#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using std::swap;
using std::vector;

namespace CLRS{ namespace CH7{
        // - Time : O(n)
        template <typename T>
        int partition(vector<T>& A, int p, int r){
            T x = A[r];
            int i = p - 1;
            for(int j = p; j < r; j++){
                if(A[j] <= x){
                    ++i;
                    swap(A[i], A[j]);
                }
                print(A);
            }
            swap(A[i + 1], A[r]);
            return i + 1;
        }

        // - Time : avg O(nlgn)
        //          worst O(n^2)
        template <typename T>
        void quicksort(vector<T>& A, int p, int r){
            if(p < r){
                int q = partition(A, p, r);
                quicksort(A, p, q - 1);
                quicksort(A, q + 1, r);
            }
        }

    }} // namespace

#endif