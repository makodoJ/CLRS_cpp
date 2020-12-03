//
// Created by Banana on 2020/12/2.
//

#ifndef ch5_1_h
#define ch5_1_h

#include <bits/stdc++.h>

namespace CLRS{
    namespace CH5{
        int RANDOM(){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::mt19937_64 generator(seed);
            std::uniform_int_distribution<int> distribution(0, 1);
            return distribution(generator);
        }

        int random(int a, int b){
            if (a == b)
                return a;
            int r = RANDOM();
            int mid = (a + b) / 2;
            if(r == 0)
                return random(a, (int)floor(mid));
            else
                return random((int) ceil(mid), b);
        }
    }
}