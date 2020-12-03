//
// Created by Banana on 2020/12/3.
//

#ifndef ch6_5_h
#define ch6_5_h

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"
#include "6.2.h"
#include "6.3.h"
#include "/Users/jiangrenjie/Documents/clrs/print/Heap.h"

namespace CLRS{
    namespace CH6{
        // - Time : O(1)
        template <typename T>
        int heap_maximum(Heap<T>& A){
            return A[0];
        }

        // - Time : O(lgn)
        template <typename T>
        T heap_extract_max(Heap<T>& A){
            if(A.heapsize < 1)
                throw("heap underflow");
            T max = A[0];
            A[0] = A[A.heapsize - 1];
            A.heapsize--;
            max_heapify(A, 0);
            return max;
        }

        // - Time : O(lgn)
        template <typename T>
        void heap_increase_key(Heap<T>& A, int i, T key){
            if(key < A[i])
                throw("new key is smaller than curren key");
            A[i] = key;
            while(i > 0 && A[parent(i)] < A[i]){
                swap(A[i], A[parent(i)]);
                i = parent(i);
            }
        }

        template <typename T>
        void max_heap_insert(Heap<T>& A, T key){
            A.heapsize++;
            A[A.heapsize - 1] = INT_MIN;
            heap_increase_key(A, A.heapsize - 1, key);
        }
    }
}

#endif