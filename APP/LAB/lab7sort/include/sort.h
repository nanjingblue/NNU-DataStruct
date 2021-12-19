//
// Created by cherry on 2021/12/14.
//

#ifndef LAB7SORT_SORT_H
#define LAB7SORT_SORT_H

#include <iostream>

template <typename T>
void insertSort(T r[], int n) {
    int i, j;
    for (i = 1; i < n; ++i) {
        T temp = r[i];
        for (j = i - 1; j >= 0 && temp < r[j]; --j) {
            r[j + 1] = r[j];
        }
        r[j + 1] = temp;
    }
}

template <typename T>
void binInsertSort(T r[], int n) {
    int i, j;
    for (i = 1; i < n; ++i) {
        T temp = r[i];
        int low = 0;
        int high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (temp < r[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= low; --j)
            r[j + 1] = r[j];
        r[low] = temp;
    }
}

template <typename T>
void bubbleSort(T r[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (r[j] > r[j + 1]) {
                T temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}

#endif //LAB7SORT_SORT_H
