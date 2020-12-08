//
// Created by makodo on 2020/12/8.
//

#include "7-2.h"
#include "../print.h"

using namespace CLRS::CH7;

int main(){
    cout << "Initialize an array of A\n";
    vector<int> A = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    print(A);

    cout << "\nPerform randomized_quicksort_equal(A, 0, 11)\n";
    randomized_quicksort_equal(A, 0, 11);
    print(A);
}
