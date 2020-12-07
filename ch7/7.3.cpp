//
// Created by makodo on 2020/12/7.
//

#include "7.3.h"

#include "../print.h"

using namespace CLRS::CH7;

int main(){
    print(string("Chapter 7.3 randomized version of quicksort"));

    cout << "Initialize an array of A as Figure 7.1\n";
    vector<int> A = {2, 8, 7, 1, 3, 5, 6, 4};
    print(A);

    cout << "\nPerform RANDOMIZED-QUICKSORT(A, 0, 7)\n";
    randomized_quicksort(A, 0, 7);
    print(A);
}
