//
// Created by cherry on 2021/10/12.
//

#ifndef LAB3_1_GET_NEXT_H
#define LAB3_1_GET_NEXT_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void callNext(string p, int next[]) {
    int len = p.length();
    next[0] = -1;
    int j = 0, k = -1;
    while (j < len - 1) {
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

void question1() {
    string a[] = {
            "ABCDEFG",
            "AAAAAAAA",
            "BABBABAB",
            "AAAAAAB",
            "ABCABDAAABC",
            "ABCABDABEABCABDABF",
            "ABBACXY"
    };
    int next[20];
    for (const auto& it : a) {
        callNext(it, next);
        cout << it << ": ";
        for (int i = 0; i < it.length(); ++i) {
            cout << next[i] << " ";
        }
        cout << endl;
    }
}

#endif //LAB3_1_GET_NEXT_H
