//
// Created by cherry on 2021/8/20.
// 三角矩阵的压缩储存
// 三角矩阵有上三角和下三角两种
// 原理同对称矩阵 新增一个常数 c 的存储空间即可放在最后一位
//
#include <iostream>

using namespace std;

void topMatrices() {
    cout << "下三角存储：";
    int top[5][5] = {
            {1, 2, 2, 2, 2},
            {5, 0, 2, 2, 2},
            {2, 6, 4, 2, 2},
            {8, 0, 5, 9 ,2},
            {7, 3, 1, 7, 0},
    };
    int n1 = sizeof(top)/sizeof(top[1]);
    int k = n1*(n1+1)/2 + 1;
    int stop[k] = {0};
    //对于下三角矩阵, 按照行优先
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n1; ++j) {
            if (i >= j) {
                k = i * (i + 1) / 2 + j;
            } else {
                k = n1 * (n1 + 1) / 2;
            }
            if (!stop[k]) stop[k] = top[i][j];
        }
    }
    for (const auto &item : stop) {
        cout << item << " ";
    }
    cout << endl;
}

void downMatrices() {
    cout << "上三角存储：";
    int down[5][5] = {
            {1, 5, 2, 8, 7},
            {2, 0, 6, 0, 3},
            {2, 2, 4, 5, 1},
            {2, 2, 2, 9 ,7},
            {2, 2, 2, 2, 0},
    };
    int n = sizeof(down) / sizeof(down[0]);
    int k = n*(n+1) /2 +1;
    int sdown[k] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= j) k = i * (2 * n - i + 1) / 2 + j - i;
            else k = n * (n + 1) / 2;
            if (!sdown[k]) sdown[k] = down[i][j];
        }
    }
    for (const auto &item : sdown) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    topMatrices();
    downMatrices();
    return 0;
}

