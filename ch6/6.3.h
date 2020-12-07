//
// Created by Banana on 2020/12/3.
//

#ifndef ch6_3_h
#define ch6_3_h

#include "../print.h"
#include "6.2.h"
#include "../Heap.h"

namespace CLRS{
    namespace CH6{
        // - Time : O(n)
        template <typename T>
        void build_max_heap(Heap<T>& A){
            for(int i = A.heapsize / 2; i >= 0; i--){
                max_heapify(A, i);
                print(A);
            }
        }
    }
}
