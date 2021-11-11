//
// Created by cherry on 2021/10/16.
//

#ifndef LAB3_1_SPECIAL_MATRICES_H
#define LAB3_1_SPECIAL_MATRICES_H

void question6() {
    int a[5][5] = {
            {1, 5, 0, 0, 0},
            {5, 0, 6, 0, 0},
            {0, 6, 4, 5, 0},
            {0, 0, 5, 9 ,7},
            {0, 0, 0, 7, 0},
    };
    int n = sizeof(a) / sizeof(a[0]);
    int sa[3 * n - 2] = { 0 };
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
}

void question7() {
    int a[5][5] = {
            {1, 5, 6, 3, 6},
            {5, 0, 6, 7, 7},
            {5, 6, 4, 5, 0},
            {7, 6, 5, 0 ,7},
            {4, 1, 2, 7, 3},
    };
    int n = sizeof(a) / sizeof(a[0]);
    int minRow[n] = {0};
    for (int i = 0; i < n; ++i) {
        minRow[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] < a[i][minRow[i]]) {
                minRow[i] = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int mmin = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] < a[mmin][i]) {
                mmin = j;
            }
        }
        if (mmin == minRow[mmin]) {
            cout << a[mmin][i] << endl;
        }
    }
}

#endif //LAB3_1_SPECIAL_MATRICES_H
