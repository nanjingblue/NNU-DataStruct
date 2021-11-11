//
// Created by cherry on 2021/10/13.
//

#ifndef LAB3_1_SUB_H
#define LAB3_1_SUB_H

#include <iostream>
#include <cstring>
#include "get_next.h"

using namespace std;

int subCnt(char * s, char * t) {
    int i = 0, j = 0, cnt = 0;
    int n = strlen(s), m = strlen(t);
    int next[100];
    callNext(t, next);
    while (i < n) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j >= m) {
            cnt ++;
            j = 0;
        }
    }
    cout << cnt << endl;
    return cnt;
}

int KMPMatching(char *s, char * t) {
    int i = 0, j = 0;
    int n = strlen(s), m = strlen(t);
    int next[1000];
    callNext(t, next);
    while (i < n && j < m) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j >= m) {
        return i - m;
    } else {
        return -1;
    }
}

void del_sub(char *s, char *t) {
    int pos = 0;
    int n = strlen(s), m = strlen(t);
    while (pos != -1) {
        pos = KMPMatching(s + pos, t);
        int i = pos, j = pos + m;
        while (j < n) s[i++] = s[j++];
        s[i] = '\0';
    }
}

void question2() {
    char s[] = "ababab";
    char t[] = "ab";
    subCnt(s, t);
}

void question3() {
    char s[] = "abababa";
    char t[] = "ab";
    del_sub(s, t);
    for (int i = 0; i < strlen(s); ++i) {
        cout << s[i] << " ";
    }
    cout << endl;
}

string longestComSub(char *s, char *p) {
    string lcs;
    int n = strlen(s), m = strlen(p);
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    int mmax = 0, pos;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i] == p[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > mmax) {
                    mmax = dp[i][j];
                    pos = i;
                }
            }
        }
    }
    for (int i = pos - mmax; i <= pos; ++i) {
        lcs += s[i];
    }
    return lcs;
}

void question4() {
    char s[] = "ababababc";
    char t[] = "abc";
    cout << longestComSub(s, t) << endl;
}

#endif //LAB3_1_SUB_H
