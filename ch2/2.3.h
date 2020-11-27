//
// Created by Banana on 2020/11/23.
//

#ifndef ch2_3_h
#define ch2_3_h

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using std::vector;

namespace CLRS{
    namespace CH2{
        template <typename T>
        void merge(vector<T>& A, int p, int q, int r){
            int n1 = q - p + 1;
            int n2 = r - q;
            vector<T>& L(n1 + 1), R(n2 + 1);
            for(int i = 0; i < n1; i++) L[i] = A[p + i];
            for(int j = 0; j < n2; j++) R[j] = A[q + j + 1];
            L[n1] = INT_MAX;
            R[n2] = INT_MAX;
            int i = 0;
            int j = 0;
            for(int k = p; k <= r; k++){
                if(L[i] <= R[j])
                    A[k] = L[i++];
                else
                    A[k] = R[j++];
            }
            print(A);
        }

        template <typename T>
        void merge_sort(vector<T>& A, int p, int r){
            if(p < r){
                int q = (p + r) / 2;;
                merge_sort(A, p, q);
                merge_sort(A, q + 1, r);
                merge(A, p, q, r);
            }
        }

        template <typename T>
        void no_sentinel_merge(vector<T>& A, int p, int q, int r){
            int n1 = q - p + 1;
            int n2 = r - q;
            vector<T>& L(n1 + 1), R(n2 + 1);

            for(int i = 0; i < n1; i++) L[i] = A[p + i];
            for(int j = 0; j < n2; j++) R[j] = A[q + j + 1];

            int i = 0, j = 0;
            for(int k = p ; k <= r; k++){
                if(i >= n1){
                    A[k] = R[j++];
                }else if(j >= n2){
                    A[k] = L[i++];
                }else if(L[i] > R[j]){
                    A[k] = R[j++];
                }else{
                    A[k] = L[i++];
                }
            }
            print(A);
        }

        template <typename T>
        int iterative_binary_search(vector<T>& A, int v, int low, int high){
            while(low <= high){
                int mid = (low + high) / 2;
                if(v == A[mid]){
                    return mid;
                } else if(v > A[mid]){
                    low = mid + 1;
                }else
                    high = mid - 1;
            }
            return -1;
        }

        template <typename T>
        int recursive_binary_search(vector<T>& A, int v, int low, int high){
            if(low > high) return -1;
            int mid = (low + high) / 2;
            if(v == A[mid]) return mid;
            else if (v > A[mid]) return recursive_binary_search(A, v, mid + 1, high);
            else return recursive_binary_search(A, v, low, mid - 1);
        }

        template <typename T>
        void insert_sort_with_binary_search(vector<T>& A){
            int n = A.size();
            for(int j = 1; j < n; j++){
                int key = A[j];
                //insert A[j] into the sorted sequence A[1...j - 1]
                int i = recursive_binary_search(A, key, 0, j - 1);
                while(A[i] > key){
                    A[i + 1] = A[i];
                    --i;
                }
                A[i + 1] = key;
            }
        }
    }
}

#endif