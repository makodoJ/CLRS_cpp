//
// Created by Banana on 2020/11/24.
//

#ifndef prob2_2_h
#define prob2_2_h

#include "../print.h"

using std::vector;

// [Page 40]
//   BUBBLE-SORT(A)
//   - Time: O(n^2)

namespace CLRS {
    namespace CH2 {
        template <class T>
        void bubble_sort(vector<T>& A){
            int n = A.size();
            for(int i = 0; i < n - 1; i++){
                for(int j = n - 1; j >= i + 1; j--){
                    if(A[j] < A[j - 1]){
                        int temp = A[j];
                        A[j] = A[j - 1];
                        A[j - 1] = temp;
                    }
                }
            }
        }
    }  // namespace CH2
}  // namespace CLRS

#endif
