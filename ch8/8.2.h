//
// Created by makodo on 2020/12/9.
//

#ifndef ch8_1_h
#define ch8_1_h

#include <vector>

using std::vector;

namespace CLRS{ namespace CH8{
    void counting_sort(vector<int>& A, vector<int>& B, int k){
        vector<int> C(k + 1, 0);
        for(int i = 0; i <= k; i++){
            C[i] = 0;
        }

        for(int j = 1; j < A.size(); j++){
            C[A[j]] = C[A[j]] + 1;
        }

        for(int i = 1; i <= k; i++){
            C[i] = C[i] + C[i - 1];
        }

        for(int j = A.size() - 1; j >= 0; j--){
            B[C[A[j]]] = A[j];
            C[A[j]] = C[A[j]] - 1;
        }
    }
}} // namespace

#endif