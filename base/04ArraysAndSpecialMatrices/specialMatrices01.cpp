//
// Created by cherry on 2021/8/20.
// 对称矩阵的压缩存储
//          1. 关于主对角线对称 a[i,j] = a[j,i]，所以只用存储上三角或下三角元素，节约一半的存储空间
//          2. 思路：利用一维数组存储，通过某个函数，实现 a[i,j] = b[k] 的对应
//
#include <iostream>
using namespace std;

int main() {
    int a[5][5] = {
            {1, 5, 2, 8, 7},
            {5, 0, 6, 0, 3},
            {2, 6, 4, 5, 1},
            {8, 0, 5, 9 ,7},
            {7, 3, 1, 7, 0},
    };
    int b[15] = {0};
    int k;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(i >= j) {
                k = i * (i + 1) / 2 + j;
            } else {
                k = j * ( j + 1) / 2 + i;
            }
            if( ! b[k] ) b[k] = a[i][j];
        }
    }
    for (const auto &item : b) {
        cout << item << " ";
    }
    cout << endl << a[3][2] << endl;
    cout << b[3 * ( 3 + 1 ) / 2 + 2] << endl;

    return 0;
}
