//
// Created by Banana on 2020/12/3.
//

#ifndef ch6_1_h
#define ch6_1_h

namespace CLRS{
    namespace CH6{
        int parent(int i){
            return (i - 1) / 2;
        }

        int left(int i){
            return 2 * i + 1;
        }

        int right(int i){
            return 2 * i + 2;
        }
    }
}

#endif