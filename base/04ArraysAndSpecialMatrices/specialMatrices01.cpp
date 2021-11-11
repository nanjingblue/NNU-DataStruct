//
// Created by cherry on 2021/8/20.
// �Գƾ����ѹ���洢
//          1. �������Խ��߶Գ� a[i,j] = a[j,i]������ֻ�ô洢�����ǻ�������Ԫ�أ���Լһ��Ĵ洢�ռ�
//          2. ˼·������һά����洢��ͨ��ĳ��������ʵ�� a[i,j] = b[k] �Ķ�Ӧ
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
