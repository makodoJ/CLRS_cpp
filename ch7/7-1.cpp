//
// Created by makodo on 2020/12/7.
//

#include "7-1.h"

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using namespace CLRS::CH7;

int main(){
    print(string("Chapter 7.3 randomized version of quicksort"));

    cout << "Initialize an array of A as Figure 7.1\n";
    vector<int> A = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    print(A);

    cout << "\nPerform RANDOMIZED-QUICKSORT(A, 0, 11)\n";
    hoare_quicksort(A, 0, 11);
    print(A);
}