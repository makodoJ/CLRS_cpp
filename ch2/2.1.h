//
// Created by Banana on 2020/11/23.
//

#ifndef ch2_1_h
#define ch2_1_h

#include "../print.h"

using std::vector;

// [page 18]
//  INSERTION-SORT(A)
// -Time: O(n^2)

namespace CLRS{
    namespace CH2{
        template <typename T>
        void insert_sort(vector<T>& A){
            for(int j = 1; j < A.size(); j++){
                int key = A[j];
                //insert A[j] into the sorted sequence A[0...j - 2]
                int i = j - 1;
                while(i >= 0 && A[i] > key){
                    A[i + 1] = A[i];
                    --i;
                }
                A[i + 1] = key;
                print(A);
            }
        }

        template <typename T>
        void nonincreasing_insert_sort(vector<T>& A){
            for(int j = 1; j < A.size(); j++){
                int key = A[j];
                int i = j - 1;
                while(i >= 0 && A[i] < key){
                    A[i + 1] = A[i];
                    --i;
                }
                A[i + 1] = key;
                print(A);
            }
        }

        template <typename T>
        int linear_search(vector<T>& A, int v){
            for(int i = 0; i < A.size(); i++){
                if(A[i] == v)
                    return i;
            }
            return -1;
        }

        vector<int>& add_two_binary_num(vector<int>& A, vector<int>& B, int n){
            vector<int> C[n + 1];
            int carry = 0;
            for(int i = 0; i < n; i++){
                int sum = A[i] + B[i];
                C->push_back((sum + carry) % 2);
                carry = (A[i] + B[i] + carry) / 2;
            }
            C->push_back(carry);
        }
    }
}

#endif
