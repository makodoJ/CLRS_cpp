//
// Created by makodo on 2020/12/9.
//

#include "8.2.h"

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using namespace CLRS::CH8;

int main(){
    print(string("Chapter 8.2 Counting sort"));

    cout << "Initialize an array A as Figure 8.2\n";
    vector<int> A = {2, 5, 3, 0, 2, 3, 0, 3};
    print(A);

    cout << "\nInitialize an empty array B as Figure 8.2\n";
    vector<int> B(A.size(), 0);
    print(B);

    cout << "\nPerform COUNTING_SORT(A, B, 5)\n";
    counting_sort(A, B, 5);
    print(B);
}