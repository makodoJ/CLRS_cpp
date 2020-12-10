//
// Created by makodo on 2020/12/10.
//

#ifndef ch8_4_h
#define ch8_4_h

#include <vector>
#include <list>

using namespace std;

namespace CLRS { namespace CH8{
    void bucket_sort(vector<double>& A){
        int n = A.size();
        vector<list<double>> B(n);

        for(int i = 0; i < n; i++){
            B[n * A[i]].push_back(A[i]);
        }

        for(int i = 0; i < n; i++){
            B[i].sort();
        }

        A.clear();

        for(auto b : B){
            for(auto val : b){
                A.push_back(val);
            }
        }
    }
}}


#endif