//
// Created by cherry on 2021/8/16.
//
#include <iostream>
#include "SeqQueue.h"

using namespace std;
int main() {
    SeqQueue<int, 100> seqQueue;
    for(int i=1; i<=20; ++i) {
        seqQueue.push(i);
    }
    cout << seqQueue.Front()<< endl;
    cout << seqQueue.back() << endl;
    cout << seqQueue.pop() << endl;
    cout << seqQueue.empty() << endl;
    return 0;
}

