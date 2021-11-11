//
// Created by cherry on 2021/10/18.
//

#ifndef LAB3_1_PATTERN_MATCHING_H
#define LAB3_1_PATTERN_MATCHING_H

#include <iostream>
#include <cstring>

using namespace std;

int BForcePatternMatch(char *s, char *t) {
    int cnt = 0;
    int len1 = strlen(s), len2 = strlen(t);
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= len2) {
        return i - j;
    }
    return -1;
}

void callNext(char *t, int next[]) {
    int len = strlen(t);
    next[0] = -1;
    int j = 0, k = -1;
    while (j < len - 1) {
        if (k == -1 || t[j] == t[k]) {
            ++k;
            ++j;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

void newCallNext(char* p, int next[]) {
    int m = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < m) {
        if (k == -1 || p[j] == p[k]) {
            if (p[j] == p[k])
                next[j + 1] = next[k];
            else
                next[j + 1] = next[j]+1;
            ++j; ++k;
        } else
            k = next[k];
    }
}

int KMP(char* s, char* p) {
    int ans = -1;
    int i = 0;
    int j = 0;
    int n = strlen(s);
    int m = strlen(p);
    int next[m];
    newCallNext(p, next); //初始化next数组
    while (i < n) {
        if (j == -1 || s[i] == p[j]) {
            ++i;	++j;
        }
        else
            j = next[j];
        if (j == m) {
            ans = i - m;
            break;
        }
    }
    return ans;
}

void question1() {
    char s[] = "232ab32r";
    char t[] = "ab";
    cout << "暴力：" << BForcePatternMatch(s, t) << endl;
}

void question2() {
    char s[] = "232ab32r";
    char t[] = "ab";
    cout << "KMP：" << KMP(s, t) << endl;
}

#endif //LAB3_1_PATTERN_MATCHING_H
