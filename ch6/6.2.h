//
// Created by Banana on 2020/12/3.
//

#ifndef ch6_2_h
#define ch6_2_h

#include "6.1.h"
#include "../Heap.h"

using std::swap;

namespace CLRS{
    namespace CH6{
        // - Time : O(lgn)
        template <typename T>
        void max_heapify(Heap<T>& A, int i){
            int l = left(i);
            int r = right(i);
            int largest;
            if(l <= A.heapsize - 1 && A[l] > A[i])
                largest = l;
            else largest = i;
            if(r <= A.heapsize - 1 && A[r] > A[largest])
                largest = r;
            if(largest != i)
                swap(A[i], A[largest]);
            max_heapify(A, largest);
        }

        // - Time : O(lgn)
        template <typename T>
        void min_heapify(Heap<T>& A, int i){
            int l = left(i);
            int r = right(i);
            int smallest;
            if(l <= A.heapsize - 1 && A[l] < A[i])
                smallest = l;
            else smallest = i;
            if(r <= A.heapsize - 1 && A[r] < A[smallest])
                smallest = r;
            if(smallest != i)
                swap(A[i], A[smallest]);
            min_heapify(A, smallest);
        }

        template <typename T>
        void iterative_max_heapify(Heap<T>& A, int i){
            while(true){
                int l = left(i);
                int r = right(i);
                int largest;
                if(l <= A.heapsize - 1 && A[l] > A[i])
                    largest = l;
                else largest = i;
                if(r <= A.heapsize - 1 && A[r] > A[largest])
                    largest = r;
                if(largest == i)
                    return;
                swap(A[i], A[largest]);
                i = largest;
            }
        }
    }
}
