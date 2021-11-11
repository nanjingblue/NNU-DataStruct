//
// Created by cherry on 2021/8/17.
//
#include <iostream>
#include "LinkQueue.h"

using namespace std;

int main() {
    LinkQueue<int> linkQueue;
    for (int i = 0; i < 10; ++i) {
        linkQueue.push(i);
    }
    cout << linkQueue.Front() << endl;
    cout << linkQueue.back() << endl;
    cout << linkQueue.pop() << endl;
    cout << linkQueue.empty() << endl;
    return 0;
}