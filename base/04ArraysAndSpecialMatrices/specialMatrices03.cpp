//
// Created by cherry on 2021/8/20.
// �ԽǾ����ѹ���洢
// �� ���ԽǾ��� Ϊ��
//
#include <iostream>

using namespace std;

int main() {
    int a[5][5] = {
            {1, 5, 0, 0, 0},
            {5, 0, 6, 0, 0},
            {0, 6, 4, 5, 0},
            {0, 0, 5, 9 ,7},
            {0, 0, 0, 7, 0},
    };
    int n = sizeof(a) / sizeof(a[0]);
    int sa[3*n-2] = {0};
    int k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i][j] != 0) {
                k = 2 * i + j;
                if(!sa[k]) sa[k] = a[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (const auto &item : sa) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}

