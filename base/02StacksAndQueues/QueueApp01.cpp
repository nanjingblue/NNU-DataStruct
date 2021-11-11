//
// Created by cherry on 2021/8/18.
// 队列求解报数问题
//
#include <iostream>
#include "LinkQueue.h"

using namespace std;

const int n = 5;

void Number() {
    LinkQueue<int> linkq;
    for (int i = 1; i <= n; ++i) {
        linkq.push(i);
    }
    while (!linkq.empty()) {
        int x = linkq.pop();
        cout << x;
        if(!linkq.empty()) {
            int y = linkq.pop();
            linkq.push(y);
        }
    }
}

int main() {
    Number();
    return 0;
}

