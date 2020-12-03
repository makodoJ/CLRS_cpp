//
// Created by Banana on 2020/12/3.
//

#ifndef ch6_4_h
#define ch6_4_h

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"
#include "6.2.h"
#include "6.3.h"
#include "/Users/jiangrenjie/Documents/clrs/print/Heap.h"

namespace CLRS{
    namespace CH6{
        // - Time : O(nlgn)
        template <typename T>
        void heapsort(Heap<T>& A){
            build_max_heap(A);
            for(int i = A.heapsize - 1; i >= 1; i--){
                swap(A[0], A[i]);
                A.heapsize--;
                max_heapify(A, 0);
                print(A);
            }
        }
    }
}

#endif