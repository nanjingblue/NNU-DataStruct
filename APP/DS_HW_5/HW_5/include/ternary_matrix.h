//
// Created by cherry on 2021/10/17.
//

#ifndef LAB3_1_TERNARY_MATRIX_H
#define LAB3_1_TERNARY_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Triple {
    int r, c;
    T elem;
};

template<typename T>
class SpareMatrix {
    vector<Triple<T>> triList;
    int rows, clos, num;
public:
    SpareMatrix();
    SpareMatrix(Triple<T> * tlist, int rs, int cs, int n) : triList(*tlist),rows(rs), clos(cs), num(n){}
    T diagonalSum() {
        T sum;
        for (auto i = triList.begin(); it < triList.end(); ++i) {
            if (triList[i].r == triList[i].c) {
                sum += triList[i].elem;
            }
        }
        return sum;
    }
};


#endif //LAB3_1_TERNARY_MATRIX_H
