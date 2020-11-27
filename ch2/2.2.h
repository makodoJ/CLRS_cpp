//
// Created by Banana on 2020/11/23.
//

#ifndef ch2_2_h
#define ch2_2_h

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using std::vector;

namespace CLRS{
    namespace CH2{
        template<typename T>
        void selection_sort(vector<T>& A){
            int n = A.size();
            for(int i = 0; i < n - 1; i++){
                int minIndex = i;
                for(int j = i; j < n; j++)
                    if(A[j] < A[minIndex]) minIndex = j;
                    swap(A[i], A[minIndex]);
                    print(A);
            }

        }
    }
}

#endif