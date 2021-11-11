//
// Created by cherry on 2021/10/14.
//

#ifndef LAB3_1_REVERSE_WORDS_H
#define LAB3_1_REVERSE_WORDS_H
#include "sub.h"
#include <iostream>
#include <cstring>

using namespace std;

string reverseWords(char * s) {
    string str;
    int pos = 0;
    int len = strlen(s);
    int t = -1;
    while (pos != t) {
        t = pos;
        pos = (pos == 0) ? KMPMatching(s , " ") : KMPMatching(s + pos + 1, " ") + pos + 1;
        if (t == pos) break;
        cout << t << " " << pos << endl;
        for (int i = pos; i >= t; --i) {
            str = s[i] + str;
        }
    }
    for (int i = len-1; i > pos; --i) {
        str = s[i] + str;
    }
    return str;
}

void question5() {
    char s[] = "Do or do not, there is no try.";
    cout << reverseWords(s);
}

#endif //LAB3_1_REVERSE_WORDS_H
