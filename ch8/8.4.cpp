//
// Created by makodo on 2020/12/10.
//

#include "8.4.h"

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"

using namespace CLRS::CH8;

int main(){
    print(string("Chapter 8.4 bucket sort"));

    cout << "Initialize an array A as Figure 8.4\n";
    vector<double> A = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    print(A);


    cout << "\nPerform bucket_sort(A)\n";
    bucket_sort(A);
    print(A);
}
