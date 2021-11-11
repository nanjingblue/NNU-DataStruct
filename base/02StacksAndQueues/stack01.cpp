//
// Created by cherry on 2021/8/8.
//
#include <iostream>
#include "SeqStack.h"


int main() {
    SeqStack<int, 10> seqStack;
    seqStack.Push(5);
    cout << seqStack.Empty() << endl;
    cout << seqStack.Top() << endl;
    return 0;
}